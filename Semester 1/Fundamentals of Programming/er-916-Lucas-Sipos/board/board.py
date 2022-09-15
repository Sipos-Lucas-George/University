from texttable import Texttable


class Board:
    def __init__(self):
        self.__board = self.createBoard()

    def setOnBoard(self, line, column, symbol):
        self.__board[line][column] = symbol

    def getFromBoard(self, line, column):
        return self.__board[line][column]

    def checkSurrounding(self, line, column):
        if line + 1 < 6 and self.__board[line + 1][column] == "-":
            return line + 1, column
        if line - 1 > -1 and self.__board[line - 1][column] == "-":
            return line - 1, column
        if column + 1 < 6 and self.__board[line][column + 1] == "-":
            return line, column + 1
        if column - 1 > -1 and self.__board[line][column - 1] == "-":
            return line, column - 1
        return -1, -1

    def setAnythingLeft(self):
        for i in range(6):
            for j in range(6):
                if self.__board[i][j] == "-":
                    self.__board[i][j] = "X"
                    return i, j

    def checkForWinningPosition(self):
        """
        First checks every row for winning position, then the columns, then diagonals
        :return: return position of possible winning move or nothing
        """
        for line in range(6):
            if self.__board[line] == ["X", "X", "X", "X", "X", "-"]:
                return line, 5, "X"
            if self.__board[line] == ["-", "X", "X", "X", "X", "X"]:
                return line, 0, "X"
            if self.__board[line] == ["O", "O", "O", "O", "O", "-"]:
                return line, 5, "O"
            if self.__board[line] == ["-", "O", "O", "O", "O", "O"]:
                return line, 0, "O"
        for column in range(6):
            getColumn = self.getColumn(column)
            if getColumn == ["X", "X", "X", "X", "X", "-"]:
                return 5, column, "X"
            if getColumn == ["-", "X", "X", "X", "X", "X"]:
                return 0, column, "X"
            if getColumn == ["O", "O", "O", "O", "O", "-"]:
                return 5, column, "O"
            if getColumn == ["-", "O", "O", "O", "O", "O"]:
                return 0, column, "O"
        return "", "", ""

    def getColumn(self, column):
        matrix = list()
        for line in range(6):
            matrix.append(self.__board[line][column])
        return matrix

    def isFull(self):
        for line in range(6):
            for column in range(6):
                if self.__board[line][column] == "-":
                    return False
        return True

    @staticmethod
    def createBoard():
        return [["-" for _ in range(6)] for _ in range(6)]

    def print(self):
        text = Texttable()
        text.add_rows([[self.__board[0][0], self.__board[0][1], self.__board[0][2]],
                       [self.__board[1][0], self.__board[1][1], self.__board[1][2]]])
        text.draw()

    def __str__(self):
        printText = ""
        for line in range(6):
            for column in range(6):
                printText += self.__board[line][column] + " "
            if line != 5:
                printText += "\n"
        return printText
