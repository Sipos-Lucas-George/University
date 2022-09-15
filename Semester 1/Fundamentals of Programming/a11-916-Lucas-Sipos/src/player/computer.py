from src.board.board import Board
from src.board.plane import Plane
from src.strategy.strategy import Strategy
from random import shuffle


class Computer:
    def __init__(self, setUpBoard: Board, strategy: Strategy):
        self.__board = setUpBoard
        self.__strategy = strategy
        self.__firstPlane = None
        self.__secondPlane = None
        self.__thirdPlane = None

    def move(self, listOfEnemyPlanes):
        self.__strategy.move(listOfEnemyPlanes)

    def setUpPlanesOnBoard(self, entity):
        positionSetPlaneUp = ['02', '03', '04', '05', '06', '07', '12', '13', '14', '15', '16', '17', '22', '23', '24', '25', '26', '27', '32', '33', '34', '35', '36', '37', '42', '43', '44', '45', '46', '47', '52', '53', '54', '55', '56', '57', '62', '63', '64', '65', '66', '67']
        positionSetPlaneRight = ['23', '24', '25', '26', '27', '28', '29', '33', '34', '35', '36', '37', '38', '39', '43', '44', '45', '46', '47', '48', '49', '53', '54', '55', '56', '57', '58', '59', '63', '64', '65', '66', '67', '68', '69', '73', '74', '75', '76', '77', '78', '79']
        positionSetPlaneDown = ['32', '33', '34', '35', '36', '37', '42', '43', '44', '45', '46', '47', '52', '53', '54', '55', '56', '57', '62', '63', '64', '65', '66', '67', '72', '73', '74', '75', '76', '77', '82', '83', '84', '85', '86', '87', '92', '93', '94', '95', '96', '97']
        positionSetPlaneLeft = ['20', '21', '22', '23', '24', '25', '26', '30', '31', '32', '33', '34', '35', '36', '40', '41', '42', '43', '44', '45', '46', '50', '51', '52', '53', '54', '55', '56', '60', '61', '62', '63', '64', '65', '66', '70', '71', '72', '73', '74', '75', '76']
        setDirection = ["up", "right", "down", "left"]
        planeDictionary = {
            "up": positionSetPlaneUp,
            "right": positionSetPlaneRight,
            "down": positionSetPlaneDown,
            "left": positionSetPlaneLeft
        }
        counterForPlanes = 0
        while True:
            shuffle(setDirection)
            if counterForPlanes == 0:
                shuffle(planeDictionary[setDirection[0]])
                self.__firstPlane = Plane(planeDictionary[setDirection[0]][0], setDirection[0], self.__board)
                self.__firstPlane.setPlane()
                counterForPlanes += 1
            elif counterForPlanes == 1:
                shuffle(planeDictionary[setDirection[0]])
                self.__secondPlane = Plane(planeDictionary[setDirection[0]][0], setDirection[0], self.__board)
                if self.__secondPlane.validatePlane() is True:
                    self.__secondPlane.setPlane()
                    counterForPlanes += 1
            elif counterForPlanes == 2:
                shuffle(planeDictionary[setDirection[0]])
                self.__thirdPlane = Plane(planeDictionary[setDirection[0]][0], setDirection[0], self.__board)
                if self.__thirdPlane.validatePlane() is True:
                    self.__thirdPlane.setPlane()
                    counterForPlanes += 1
            else:
                entity.append(self.__firstPlane)
                entity.append(self.__secondPlane)
                entity.append(self.__thirdPlane)
                return
