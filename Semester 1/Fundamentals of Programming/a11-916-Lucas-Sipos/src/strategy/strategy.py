from src.board.board import Board
from src.board.plane import Plane
from random import shuffle


class Strategy:
    def __init__(self, enemyBoard: Board):
        self.__enemyBoard = enemyBoard
        self.__movesThatHit = list()
        self.__counterForMakingDecisions = 0
        self.__pickNextElement = 0
        self.__actDumb = 0
        self.__dictionaryForSurroundingCheck = {
            "line1": 1,
            "line2": -1,
            "column1": 1,
            "column2": -1
        }
        self.__bestRandomDecisions = ['02', '03', '04', '05', '06', '07', '11', '12', '13', '14', '15', '16', '17', '18', '20', '21', '22', '23', '24', '25', '26', '27', '28', '29', '30', '31', '32', '33', '34', '35', '36', '37', '38', '39', '40', '41', '42', '43', '44', '45', '46', '47', '48', '49', '50', '51', '52', '53', '54', '55', '56', '57', '58', '59', '60', '61', '62', '63', '64', '65', '66', '67', '68', '69', '70', '71', '72', '73', '74', '75', '76', '77', '78', '79', '81', '82', '83', '84', '85', '86', '87', '88', '92', '93', '94', '95', '96', '97']

    def move(self, listOfEnemyPlanes):
        if len(self.__movesThatHit) != 0:
            self.makeADecision(listOfEnemyPlanes)
        else:
            self.randomDecision(listOfEnemyPlanes)

    def makeADecision(self, listOfEnemyPlanes):
        if self.__counterForMakingDecisions < 4:
            self.firstChecks(listOfEnemyPlanes)
        elif len(self.__movesThatHit) > 6:
            self.pickThePlaneHead(listOfEnemyPlanes)
        else:
            self.nextChecks(listOfEnemyPlanes)

    def pickThePlaneHead(self, listOfEnemyPlanes):
        positionOfPlaneToDestroy = self.popUselessInformationFromMovesThatHit(listOfEnemyPlanes)
        listOfEnemyPlanes[positionOfPlaneToDestroy].destroyPlane()
        listOfEnemyPlanes.pop(positionOfPlaneToDestroy)

    def nextChecks(self, listOfEnemyPlanes):
        if self.__actDumb == 0:
            self.__pickNextElement += 1
            self.__dictionaryForSurroundingCheck = {
                "line1": 1,
                "line2": -1,
                "column1": 1,
                "column2": -1
            }
            self.__actDumb = self.setActDumb()
            if self.__actDumb == 0:
                self.nextChecks(listOfEnemyPlanes)
        # else:
        self.__actDumb -= 1
        self.setStrikeForActDumb(self.__movesThatHit[self.__pickNextElement], listOfEnemyPlanes)

    def setStrikeForActDumb(self, position, listOfEnemyPlanes):
        line, column = int(position[0]), int(position[1])
        convertDictionaryToList = list(self.__dictionaryForSurroundingCheck.items())
        for key, value in convertDictionaryToList:
            if key[:-1] == "line":
                line = line + value
                hitPlace = self.hitPlace(line, column)
            else:
                column = column + value
                hitPlace = self.hitPlace(line, column)
            self.deleteFromRandomList(f"{line}{column}")
            self.__dictionaryForSurroundingCheck.pop(key)
            if hitPlace == "":
                self.nextChecks(listOfEnemyPlanes)
            elif self.hitOrMiss(hitPlace) is False:
                self.__enemyBoard.setCell(line, column, "O")
            elif hitPlace == "X":
                self.__enemyBoard.setCell(line, column, "X")
                self.__movesThatHit.append(f"{line}{column}")
            elif hitPlace == "+":
                self.popUselessInformationFromMovesThatHit(listOfEnemyPlanes, f"{line}{column}")
                self.findPlaneAndDestroy(f"{line}{column}", listOfEnemyPlanes)
            return

    def popUselessInformationFromMovesThatHit(self, listOfEnemyPlanes, position="unknown"):
        if position != "unknown":
            numberOfPlane = self.findPlane(position, listOfEnemyPlanes)
            listOfPositions = listOfEnemyPlanes[numberOfPlane].getPlane
            for i in listOfPositions:
                self.deleteFromRandomList(i)
                if self.__movesThatHit.count(i) != 0:
                    self.__movesThatHit.remove(i)
            self.setVariablesAfterPop()
        else:
            maxCounter, maxPosition = -1, -1
            for i in range(len(listOfEnemyPlanes)):
                counter, position = 0, i
                for location in listOfEnemyPlanes[i].getPlane:
                    if location in self.__movesThatHit:
                        counter += 1
                if counter > maxCounter:
                    maxCounter = counter
                    maxPosition = position
            listOfPositions = listOfEnemyPlanes[maxPosition].getPlane
            for i in listOfPositions:
                self.deleteFromRandomList(i)
                if self.__movesThatHit.count(i) != 0:
                    self.__movesThatHit.remove(i)
            self.setVariablesAfterPop()
            return maxPosition

    def setVariablesAfterPop(self):
        if len(self.__movesThatHit) > 0:
            self.__pickNextElement = -1
            self.__actDumb = 0
        else:
            self.__counterForMakingDecisions = 0
            self.__pickNextElement = 0
            self.__actDumb = 0
            self.__dictionaryForSurroundingCheck = {
                "line1": 1,
                "line2": -1,
                "column1": 1,
                "column2": -1
            }

    def setActDumb(self):
        _ = self.checkBorders(self.__movesThatHit[self.__pickNextElement])
        counter = self.checkSurrounding(self.__movesThatHit[self.__pickNextElement])
        return counter

    def checkSurrounding(self, position):
        line, column = int(position[0]), int(position[1])
        counterForAer = 0
        counterForHit = 0
        convertDictionaryToList = list(self.__dictionaryForSurroundingCheck.items())
        for key, value in convertDictionaryToList:
            if key[:-1] == "line":
                hitPlace = self.hitPlace(line + value, column)
            else:
                hitPlace = self.hitPlace(line, column + value)
            if hitPlace == "":
                self.__dictionaryForSurroundingCheck.pop(key)
            else:
                if self.hitOrMiss(hitPlace) is True:
                    counterForHit += 1
                else:
                    if counterForAer == 1:
                        self.__dictionaryForSurroundingCheck.pop(key)
                    else:
                        counterForAer += 1
        if counterForHit == 0:
            return 0
        overallCounter = counterForAer + counterForHit
        return overallCounter

    @staticmethod
    def hitOrMiss(hitPlace):
        if hitPlace == "X" or hitPlace == "+":
            return True
        return False

    def firstChecks(self, listOfEnemyPlanes):
        if self.__counterForMakingDecisions == 0:
            self.__counterForMakingDecisions = self.checkBorders(self.__movesThatHit[0])
        convertDictionaryToList = list(self.__dictionaryForSurroundingCheck.items())
        axis = convertDictionaryToList[0][0]
        self.setDecision(axis, listOfEnemyPlanes)

    def setDecision(self, axis, listOfEnemyPlanes):
        line, column = int(self.__movesThatHit[0][0]), int(self.__movesThatHit[0][1])
        hitPlace = None
        if axis == "line1":
            hitPlace = self.hitPlace(line + 1, column)
            self.__movesThatHit.append(f"{line + 1}{column}")
            line, column = line + 1, column
        elif axis == "line2":
            hitPlace = self.hitPlace(line - 1, column)
            self.__movesThatHit.append(f"{line - 1}{column}")
            line, column = line - 1, column
        elif axis == "column1":
            hitPlace = self.hitPlace(line, column + 1)
            self.__movesThatHit.append(f"{line}{column + 1}")
            line, column = line, column + 1
        elif axis == "column2":
            hitPlace = self.hitPlace(line, column - 1)
            self.__movesThatHit.append(f"{line}{column - 1}")
            line, column = line, column - 1
        self.__counterForMakingDecisions += 1
        self.__dictionaryForSurroundingCheck.pop(axis)
        self.deleteFromRandomList(f"{line}{column}")
        if hitPlace == "":
            self.makeADecision(listOfEnemyPlanes)
        elif hitPlace == "O":
            self.__movesThatHit.pop()
            self.__enemyBoard.setCell(line, column, hitPlace)
        elif hitPlace == "X":
            self.__enemyBoard.setCell(line, column, hitPlace)
        elif hitPlace == "+":
            self.findPlaneAndDestroy(f"{line}{column}", listOfEnemyPlanes)
            self.__movesThatHit.clear()
            self.__counterForMakingDecisions = 0
            self.__dictionaryForSurroundingCheck = {
                "line1": 1,
                "line2": -1,
                "column1": 1,
                "column2": -1
            }

    def checkBorders(self, position):
        line = int(position[0])
        column = int(position[1])
        if line == 0:
            self.__dictionaryForSurroundingCheck.pop("line2")
        if line == 9:
            self.__dictionaryForSurroundingCheck.pop("line1")
        if column == 0:
            self.__dictionaryForSurroundingCheck.pop("column2")
        if column == 9:
            self.__dictionaryForSurroundingCheck.pop("column1")
        return 4 - len(self.__dictionaryForSurroundingCheck)

    def randomDecision(self, listOfEnemyPlanes):
        shuffle(self.__bestRandomDecisions)
        hitLocation = self.__bestRandomDecisions.pop(0)
        hitPlace = self.hitPlace(hitLocation[0], hitLocation[1])
        if hitPlace == "":
            self.randomDecision(listOfEnemyPlanes)
        elif hitPlace == "O":
            self.__enemyBoard.setCell(hitLocation[0], hitLocation[1], hitPlace)
        elif hitPlace == "X":
            self.__enemyBoard.setCell(hitLocation[0], hitLocation[1], hitPlace)
            self.__movesThatHit.append(hitLocation)
        else:
            self.findPlaneAndDestroy(hitLocation, listOfEnemyPlanes)

    def deleteFromRandomList(self, position):
        if self.__bestRandomDecisions.count(position) == 0:
            return
        self.__bestRandomDecisions.remove(position)

    @staticmethod
    def findPlane(strike, listOfEnemyPlanes):
        i = -1
        for plane in listOfEnemyPlanes:
            i += 1
            if plane.getHead == strike:
                return i

    @staticmethod
    def findPlaneAndDestroy(strike, listOfEnemyPlanes):
        i = -1
        for plane in listOfEnemyPlanes:
            i += 1
            if plane.getHead == strike:
                popPlane = listOfEnemyPlanes.pop(i)
                popPlane.destroyPlane()

    def hitPlace(self, line, column):
        hitPlace = self.__enemyBoard.getCell(line, column)
        if hitPlace == "■":
            return "X"
        elif hitPlace == "X" or hitPlace == "O":
            return ""
        elif hitPlace == "-":
            return "O"
        else:
            return "+"
