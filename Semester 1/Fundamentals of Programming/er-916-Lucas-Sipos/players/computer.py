from strategy.strategy import Strategy
from board.board import Board


class Computer:
    def __init__(self, board: Board, strategy: Strategy):
        self.__board = board
        self.__strategy = strategy

    def move(self):
        if self.__board.isFull() is True:
            self.__strategy.setWinner()
            return
        if self.__strategy.getLastSymbol() == "":
            self.__strategy.centerDecision()
        else:
            self.__strategy.moveProperly()

    def getInvertedSymbol(self):
        if self.__strategy.getLastSymbol() == "X":
            return "O"
        return "X"

    def isWinner(self):
        return self.__strategy.getWinner()

    def print(self):
        return f"AI: ({int(self.__strategy.getLastPosition()[0])+1},{int(self.__strategy.getLastPosition()[1])+1},{self.__strategy.getLastSymbol()})"
