from board.board import Board
import unittest


class TestForCondition5(unittest.TestCase):
    def setUp(self) -> None:
        self.__board = Board()

    def tearDown(self) -> None:
        pass

    def testCheckForWinningConditionForX(self):
        self.__board.setOnBoard(1, 0, "X")
        self.__board.setOnBoard(1, 1, "X")
        self.__board.setOnBoard(1, 2, "X")
        self.__board.setOnBoard(1, 3, "X")
        self.__board.setOnBoard(1, 4, "X")
        self.assertEqual(self.__board.checkForWinningPosition(), (1, 5, "X"))

    def testCheckForWinningConditionForO(self):
        self.__board.setOnBoard(0, 0, "O")
        self.__board.setOnBoard(1, 0, "O")
        self.__board.setOnBoard(2, 0, "O")
        self.__board.setOnBoard(3, 0, "O")
        self.__board.setOnBoard(4, 0, "O")
        self.assertEqual(self.__board.checkForWinningPosition(), (5, 0, "O"))
