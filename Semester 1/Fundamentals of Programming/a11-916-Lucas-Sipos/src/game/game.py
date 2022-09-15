from src.player.human import Human
from src.player.computer import Computer
from src.board.board import Board
from src.board.plane import Plane


class Game:
    def __init__(self, human: Human, computer: Computer, boardForPastCalls: Board, humanBoard: Board, computerBoard: Board):
        self.__human = human
        self.__computer = computer
        self.__boardForPastCalls = boardForPastCalls
        self.__humanBoard = humanBoard
        self.__computerBoard = computerBoard
        self.__humanPlanes = []
        self.__computerPlanes = []
        self.__turn = True

    def play(self):
        self.rules()
        self.__computer.setUpPlanesOnBoard(self.__computerPlanes)
        self.setUpPlayerBoard()
        print("\nLet the game begin!\n")
        print(self.__boardForPastCalls)
        print(self.__humanBoard)
        while True:
            if self.__turn is True:
                self.move()
            else:
                print("Computer's move:\n")
                self.__computer.move(self.__humanPlanes)
                self.__turn = True
            if self.winnerStatus() is True:
                return
            print(self.__computerBoard)
            print(self.__boardForPastCalls)
            print(self.__humanBoard)

    def winnerStatus(self):
        if len(self.__computerPlanes) == 0:
            print("Computer board:")
            print(self.__computerBoard)
            print("Your boards:")
            print(self.__boardForPastCalls)
            print(self.__humanBoard)
            print("!!!---YOU WON---!!!")
            return True
        elif len(self.__humanPlanes) == 0:
            print("Computer board:")
            print(self.__computerBoard)
            print("Your boards:")
            print(self.__boardForPastCalls)
            print(self.__humanBoard)
            print("!!!---COMPUTER WON---!!!")
            return True
        return False

    @staticmethod
    def rules():
        print("Plane management:")
        print("\t-when entering the plane's head first put a letter from A to J, then a number from 1 to 10")
        print("\t-after that choose the direction of the head: up/right/down/left")
        print("Game play:")
        print("\t-try to guess the opponents plane's position")
        print("\t-if you hit the head of the computer's plane, the hole plane will be destroy and covered by letter 'X'")
        print("\t-if you hit the plane's body the there will be an 'X' placed only on that position")
        print("\t-if you hit the air there will be an 'O' placed in that in position\n")

    def move(self):
        strike = input("Choose where you want to strike: ")
        strike = self.verifyInput(strike, "up")
        if strike != "":
            if self.__human.verifyForDuplicateMove(strike) is False:
                self.__human.move(strike, self.__computerPlanes)
                self.__turn = False
            else:
                print("Already struck there!")
                self.move()

    def setUpPlayerBoard(self):
        counterForPlanes = 0
        while True:
            print(self.__humanBoard)
            planeHead, direction = self.readPlayerChoice(counterForPlanes)
            if planeHead != -1:
                if counterForPlanes == 0:
                    if self.__human.validatePlaneOnBoard(planeHead, direction) is True:
                        self.__human.setUpPlaneOnBoard(planeHead, direction, counterForPlanes)
                        counterForPlanes += 1
                elif counterForPlanes < 3:
                    if self.__human.validatePlaneOnBoard(planeHead, direction) is True:
                        self.__human.setUpPlaneOnBoard(planeHead, direction, counterForPlanes)
                        counterForPlanes += 1
            if counterForPlanes == 3:
                break
        self.__human.appendToList(self.__humanPlanes)

    def readPlayerChoice(self, numberOfThePlane):
        planeHead = None
        if numberOfThePlane == 0:
            planeHead = input("Enter the position for the first plane head: ").strip()
        elif numberOfThePlane == 1:
            planeHead = input("Enter the position for the second plane head: ").strip()
        elif numberOfThePlane == 2:
            planeHead = input("Enter the position for the third plane head: ").strip()
        direction = input("Enter the direction of the plane's head: ").strip()
        planeHead = self.verifyInput(planeHead, direction)
        if planeHead == "":
            return -1, -1
        return planeHead, direction

    @staticmethod
    def verifyInput(planeHead, direction):
        listOfDirectionValidation = ["up", "down", "left", "right"]
        if listOfDirectionValidation.count(direction) == 0:
            return ""
        if len(planeHead) < 2 or len(planeHead) > 3:
            return ""
        if len(planeHead) == 3 and planeHead[1:] != "10":
            return ""
        if len(planeHead) == 2 and int(planeHead[1]) < 1:
            return ""
        if len(planeHead) == 3:
            if planeHead[0].isalpha() and planeHead[1:].isdigit():
                planeHead = str(ord(planeHead[0].upper()) - 65) + str(9)
            else:
                return ""
        else:
            if planeHead[0].isalpha() and planeHead[1].isdigit():
                planeHead = str(ord(planeHead[0].upper()) - 65) + str(int(planeHead[1]) - 1)
            else:
                return ""
        return planeHead
