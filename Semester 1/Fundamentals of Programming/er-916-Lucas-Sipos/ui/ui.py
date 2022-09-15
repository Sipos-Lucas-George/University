from board.board import Board
from players.computer import Computer
from players.human import Human


class UI:
    def __init__(self, board: Board, computer: Computer, human: Human):
        self.__board = board
        self.__computer = computer
        self.__human = human
        self.__humanDecision = ""

    def start(self):
        print(self.__board, "\n")
        while True:
            self.__computer.move()
            print(self.__board)
            print(self.__computer.print())
            if self.__computer.isWinner() is True:
                self.display("Computer")
                return
            elif self.__computer.isWinner() is False:
                self.display("Player")
                return
            self.move()
            print(f"Human: ({self.__humanDecision[0]},{self.__humanDecision[1]},{self.__humanDecision[2]})")
            if self.__board.isFull() is True:
                self.display("Player")
                return

    def move(self):
        while True:
            line = input("Line: ")
            column = input("Column: ")
            symbol = input("Symbol: ")
            if line.isdecimal() is True and column.isdecimal() is True:
                line = int(line) - 1
                column = int(column) - 1
                if self.__human.verifyInput(line, column) is True:
                    break
                else:
                    print("Incorrect input!")
            else:
                print("Incorrect input!")
        self.__humanDecision = f"{line+1}{column+1}{symbol}"
        self.__human.move(line, column, symbol)

    @staticmethod
    def display(winner):
        print(f"{winner} has won!!!")
