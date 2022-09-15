class Board:
    def __init__(self, lines=10, columns=10, empty="-"):
        self.__lines = lines
        self.__columns = columns
        self.__emptySpace = empty
        self.__board = self.__createBoard()

    def __createBoard(self):
        return [[self.__emptySpace for _ in range(self.__columns)] for _ in range(self.__lines)]

    def getCell(self, line, column):
        return self.__board[int(line)][int(column)]

    def setCell(self, line, column, value):
        self.__board[int(line)][int(column)] = value

    def boardClear(self):
        self.__board = self.__createBoard()

    """
        --------------------VALIDATE--------------------
    """

    def validateSetPlaneUp(self, head):
        line = int(head[0])
        column = int(head[1])
        empty = "-"
        if line > 6 or column < 2 or column > 7:
            return False

        """HEAD"""
        if self.__board[line][column] != empty:
            return False

        """MIDDLE PART"""
        for i in range(1, 4):
            if self.__board[line + i][column] != empty:
                return False

        """FRONT WING"""
        for i in range(1, 3):
            if self.__board[line + 1][column + i] != empty or self.__board[line + 1][column - i] != empty:
                return False

        """"BACK WING"""
        if self.__board[line + 3][column + 1] != empty or self.__board[line + 3][column - 1] != empty:
            return False
        return True

    def validateSetPlaneRight(self, head):
        line = int(head[0])
        column = int(head[1])
        empty = "-"
        if line < 2 or line > 7 or column < 3:
            return False

        """HEAD"""
        if self.__board[line][column] != empty:
            return False

        """MIDDLE PART"""
        for i in range(1, 4):
            if self.__board[line][column - i] != empty:
                return False

        """FRONT WING"""
        for i in range(1, 3):
            if self.__board[line + i][column - 1] != empty or self.__board[line - i][column - 1] != empty:
                return False

        """"BACK WING"""
        if self.__board[line + 1][column - 3] != empty or self.__board[line - 1][column - 3] != empty:
            return False
        return True

    def validateSetPlaneDown(self, head):
        line = int(head[0])
        column = int(head[1])
        empty = "-"
        if line < 3 or column < 2 or column > 7:
            return False

        """HEAD"""
        if self.__board[line][column] != empty:
            return False

        """MIDDLE PART"""
        for i in range(1, 4):
            if self.__board[line - i][column] != empty:
                return False

        """FRONT WING"""
        for i in range(1, 3):
            if self.__board[line - 1][column + i] != empty or self.__board[line - 1][column - i] != empty:
                return False

        """"BACK WING"""
        if self.__board[line - 3][column + 1] != empty or self.__board[line - 3][column - 1] != empty:
            return False
        return True

    def validateSetPlaneLeft(self, head):
        line = int(head[0])
        column = int(head[1])
        empty = "-"
        if line < 2 or line > 7 or column > 6:
            return False

        """HEAD"""
        if self.__board[line][column] != empty:
            return False

        """MIDDLE PART"""
        for i in range(1, 4):
            if self.__board[line][column + i] != empty:
                return False

        """FRONT WING"""
        for i in range(1, 3):
            if self.__board[line + i][column + 1] != empty or self.__board[line - i][column + 1] != empty:
                return False

        """"BACK WING"""
        if self.__board[line + 1][column + 3] != empty or self.__board[line - 1][column + 3] != empty:
            return False
        return True

    """
        --------------------SETTING UP--------------------
    """

    def setPlaneOnBoardUp(self, head, headSymbol, bodySymbol="■"):
        line = int(head[0])
        column = int(head[1])

        """HEAD"""
        self.setCell(line, column, headSymbol)

        """MIDDLE PART"""
        for i in range(1, 4):
            self.setCell(line + i, column, bodySymbol)

        """FRONT WING"""
        for i in range(1, 3):
            self.setCell(line + 1, column + i, bodySymbol)
            self.setCell(line + 1, column - i, bodySymbol)

        """"BACK WING"""
        self.setCell(line + 3, column + 1, bodySymbol)
        self.setCell(line + 3, column - 1, bodySymbol)

    def setPlaneOnBoardRight(self, head, headSymbol, bodySymbol="■"):
        line = int(head[0])
        column = int(head[1])

        """HEAD"""
        self.setCell(line, column, headSymbol)

        """MIDDLE PART"""
        for i in range(1, 4):
            self.setCell(line, column - i, bodySymbol)

        """FRONT WING"""
        for i in range(1, 3):
            self.setCell(line + i, column - 1, bodySymbol)
            self.setCell(line - i, column - 1, bodySymbol)

        """"BACK WING"""
        self.setCell(line + 1, column - 3, bodySymbol)
        self.setCell(line - 1, column - 3, bodySymbol)

    def setPlaneOnBoardDown(self, head, headSymbol, bodySymbol="■"):
        line = int(head[0])
        column = int(head[1])

        """HEAD"""
        self.setCell(line, column, headSymbol)

        """MIDDLE PART"""
        for i in range(1, 4):
            self.setCell(line - i, column, bodySymbol)

        """FRONT WING"""
        for i in range(1, 3):
            self.setCell(line - 1, column + i, bodySymbol)
            self.setCell(line - 1, column - i, bodySymbol)

        """"BACK WING"""
        self.setCell(line - 3, column + 1, bodySymbol)
        self.setCell(line - 3, column - 1, bodySymbol)

    def setPlaneOnBoardLeft(self, head, headSymbol, bodySymbol="■"):
        line = int(head[0])
        column = int(head[1])

        """HEAD"""
        self.setCell(line, column, headSymbol)

        """MIDDLE PART"""
        for i in range(1, 4):
            self.setCell(line, column + i, bodySymbol)

        """FRONT WING"""
        for i in range(1, 3):
            self.setCell(line + i, column + 1, bodySymbol)
            self.setCell(line - i, column + 1, bodySymbol)

        """"BACK WING"""
        self.setCell(line + 1, column + 3, bodySymbol)
        self.setCell(line - 1, column + 3, bodySymbol)

    """
        --------------------GETTING PLANE--------------------
    """

    @staticmethod
    def getPlaneOnBoardUp(head):
        line = int(head[0])
        column = int(head[1])
        listOfPlanePositions = list()

        """HEAD"""
        listOfPlanePositions.append(f"{line}{column}")

        """MIDDLE PART"""
        for i in range(1, 4):
            listOfPlanePositions.append(f"{line + i}{column}")

        """FRONT WING"""
        for i in range(1, 3):
            listOfPlanePositions.append(f"{line + 1}{column + i}")
            listOfPlanePositions.append(f"{line + 1}{column - i}")

        """"BACK WING"""
        listOfPlanePositions.append(f"{line + 3}{column + 1}")
        listOfPlanePositions.append(f"{line + 3}{column - 1}")
        return listOfPlanePositions

    @staticmethod
    def getPlaneOnBoardRight(head):
        line = int(head[0])
        column = int(head[1])
        listOfPlanePositions = list()

        """HEAD"""
        listOfPlanePositions.append(f"{line}{column}")

        """MIDDLE PART"""
        for i in range(1, 4):
            listOfPlanePositions.append(f"{line}{column - i}")

        """FRONT WING"""
        for i in range(1, 3):
            listOfPlanePositions.append(f"{line + i}{column - 1}")
            listOfPlanePositions.append(f"{line - i}{column - 1}")

        """"BACK WING"""
        listOfPlanePositions.append(f"{line + 1}{column - 3}")
        listOfPlanePositions.append(f"{line - 1}{column - 3}")
        return listOfPlanePositions

    @staticmethod
    def getPlaneOnBoardDown(head):
        line = int(head[0])
        column = int(head[1])
        listOfPlanePositions = list()

        """HEAD"""
        listOfPlanePositions.append(f"{line}{column}")

        """MIDDLE PART"""
        for i in range(1, 4):
            listOfPlanePositions.append(f"{line - i}{column}")

        """FRONT WING"""
        for i in range(1, 3):
            listOfPlanePositions.append(f"{line - 1}{column + i}")
            listOfPlanePositions.append(f"{line - 1}{column - i}")

        """"BACK WING"""
        listOfPlanePositions.append(f"{line - 3}{column + 1}")
        listOfPlanePositions.append(f"{line - 3}{column - 1}")
        return listOfPlanePositions

    @staticmethod
    def getPlaneOnBoardLeft(head):
        line = int(head[0])
        column = int(head[1])
        listOfPlanePositions = list()

        """HEAD"""
        listOfPlanePositions.append(f"{line}{column}")

        """MIDDLE PART"""
        for i in range(1, 4):
            listOfPlanePositions.append(f"{line}{column + i}")

        """FRONT WING"""
        for i in range(1, 3):
            listOfPlanePositions.append(f"{line + i}{column + 1}")
            listOfPlanePositions.append(f"{line - i}{column + 1}")

        """"BACK WING"""
        listOfPlanePositions.append(f"{line + 1}{column + 3}")
        listOfPlanePositions.append(f"{line - 1}{column + 3}")
        return listOfPlanePositions

    def __str__(self):
        boardInString = " "
        alphabet = "ABCDEFGHIJ"
        for number in range(10):
            boardInString += f" {number + 1}"
        boardInString += "\n"
        for line in range(self.__lines):
            convertToString = " ".join([str(self.__board[line][column]) for column in range(self.__columns)]) + "\n"
            boardInString += alphabet[line] + " " + convertToString
        return boardInString
