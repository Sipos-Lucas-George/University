from src.board.board import Board
from src.board.plane import Plane


class Human:
    def __init__(self, setUpBoard: Board, boardForLastCalls: Board, enemyBoard: Board):
        self.__board = setUpBoard
        self.__boardForLastCalls = boardForLastCalls
        self.__enemyBoard = enemyBoard
        self.__firstPlane = None
        self.__secondPlane = None
        self.__thirdPlane = None

    def verifyForDuplicateMove(self, strike):
        return False if self.__boardForLastCalls.getCell(int(strike[0]), int(strike[1])) == '-' else True

    def move(self, strike, listOfEnemyPlanes):
        line, column = int(strike[0]), int(strike[1])
        hitPlace = self.hitPlace(line, column)
        if hitPlace == "+":
            self.findPlaneAndDestroy(strike, listOfEnemyPlanes)
        else:
            self.__boardForLastCalls.setCell(line, column, hitPlace)

    def findPlaneAndDestroy(self, strike, listOfEnemyPlanes):
        i = -1
        popPlane = None
        for plane in listOfEnemyPlanes:
            i += 1
            if plane.getHead == strike:
                popPlane = listOfEnemyPlanes.pop(i)
        planeToDestroy = Plane(strike, popPlane.getDirection, self.__boardForLastCalls)
        popPlane.destroyPlane()
        planeToDestroy.setPlane()
        planeToDestroy.destroyPlane()

    def hitPlace(self, line, column):
        hitPlace = self.__enemyBoard.getCell(line, column)
        if hitPlace == "■":
            return "X"
        elif hitPlace != "-":
            return "+"
        else:
            return "O"

    def appendToList(self, entity):
        entity.append(self.__firstPlane)
        entity.append(self.__secondPlane)
        entity.append(self.__thirdPlane)

    def validatePlaneOnBoard(self, headPlane, direction):
        return Plane(headPlane, direction, self.__board).validatePlane()

    def setUpPlaneOnBoard(self, headPlane, direction, counter):
        if counter == 0:
            self.__firstPlane = Plane(headPlane, direction, self.__board)
            self.__firstPlane.setPlane()
        elif counter == 1:
            self.__secondPlane = Plane(headPlane, direction, self.__board)
            self.__secondPlane.setPlane()
        elif counter == 2:
            self.__thirdPlane = Plane(headPlane, direction, self.__board)
            self.__thirdPlane.setPlane()
