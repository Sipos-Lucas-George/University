from board.board import Board


class Human:
    def __init__(self, board: Board):
        self.__board = board

    def move(self, line, column, symbol):
        self.__board.setOnBoard(line, column, symbol)

    def verifyInput(self, line, column):
        if line < 0 or line > 5:
            return False
        if column < 0 or column > 5:
            return False
        if self.__board.getFromBoard(line, column) != "-":
            return False
        return True
