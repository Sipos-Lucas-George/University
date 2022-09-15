from board.board import Board
from random import randint


class Strategy:
    def __init__(self, board: Board):
        self.__board = board
        self.__winner = None
        self.__lastMoves = list()
        self.__lastMoveSymbol = ""
        self.__lastMovePosition = ""

    def moveProperly(self):
        line, column, symbol = self.__board.checkForWinningPosition()
        if line != "":
            self.__board.setOnBoard(line, column, symbol)
            self.__lastMovePosition = f"{line}{column}"
            self.__lastMoveSymbol = f"{symbol}"
            self.__winner = True
        else:
            self.nextMove()

    def nextMove(self):
        decision = self.__lastMoves[len(self.__lastMoves) - 1]
        line, column = int(decision[0]), int(decision[1])
        line, column = self.__board.checkSurrounding(line, column)
        while line == -1:
            self.__lastMoves.pop()
            if len(self.__lastMoves) == 0:
                self.makeRandomDecision()
                return
            else:
                decision = self.__lastMoves[len(self.__lastMoves) - 1]
                line, column = int(decision[0]), int(decision[1])
                line, column = self.__board.checkSurrounding(line, column)
        self.__board.setOnBoard(line, column, "X")
        self.__lastMovePosition = f"{line}{column}"
        self.__lastMoveSymbol = "X"
        self.__lastMoves.append(self.__lastMovePosition)

    def makeRandomDecision(self):
        line, column = self.__board.setAnythingLeft()
        self.__lastMovePosition = f"{line}{column}"
        self.__lastMoveSymbol = "X"
        self.__lastMoves.append(self.__lastMovePosition)

    def centerDecision(self):
        line = randint(2, 3)
        column = randint(2, 3)
        self.__lastMovePosition = f"{line}{column}"
        self.__lastMoveSymbol = "X"
        self.__board.setOnBoard(line, column, "X")
        self.__lastMoves.append(f"{line}{column}")

    def getLastPosition(self):
        return self.__lastMovePosition

    def getLastSymbol(self):
        return self.__lastMoveSymbol

    def getWinner(self):
        return self.__winner

    def setWinner(self):
        self.__winner = False
