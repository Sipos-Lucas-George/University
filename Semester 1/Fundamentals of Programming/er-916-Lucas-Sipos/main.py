from board.board import Board
from players.computer import Computer
from players.human import Human
from strategy.strategy import Strategy
from ui.ui import UI


board = Board()
strategy = Strategy(board)
computer = Computer(board, strategy)
human = Human(board)
ui = UI(board, computer, human)
ui.start()
