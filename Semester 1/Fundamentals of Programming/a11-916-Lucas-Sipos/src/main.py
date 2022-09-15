from src.game.game import Game
from src.player.human import Human
from src.player.computer import Computer
from src.board.board import Board
from src.strategy.strategy import Strategy


boardForPastCalls = Board()
humanBoard = Board()
computerBoard = Board()
strategy = Strategy(humanBoard)
human = Human(humanBoard, boardForPastCalls, computerBoard)
computer = Computer(computerBoard, strategy)
game = Game(human, computer, boardForPastCalls, humanBoard, computerBoard)
game.play()
