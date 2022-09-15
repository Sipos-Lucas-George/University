from src.board.board import Board


class Plane:
    def __init__(self, head, direction, board: Board):
        self.__head = head
        self.__directionDictionary = {
            "up": "▲",
            "right": "▶",
            "down": "▼",
            "left": "◀"
        }
        self.__direction = self.__directionDictionary[direction]
        self.__board = board
        self.__validatePlaneDictionary = {
            "▲": self.__board.validateSetPlaneUp,
            "▶": self.__board.validateSetPlaneRight,
            "▼": self.__board.validateSetPlaneDown,
            "◀": self.__board.validateSetPlaneLeft
        }
        self.__setDirectionDictionary = {
            "▲": self.__board.setPlaneOnBoardUp,
            "▶": self.__board.setPlaneOnBoardRight,
            "▼": self.__board.setPlaneOnBoardDown,
            "◀": self.__board.setPlaneOnBoardLeft
        }
        self.__getPlaneDictionary = {
            "▲": self.__board.getPlaneOnBoardUp,
            "▶": self.__board.getPlaneOnBoardRight,
            "▼": self.__board.getPlaneOnBoardDown,
            "◀": self.__board.getPlaneOnBoardLeft
        }

    @property
    def getHead(self):
        return self.__head

    @property
    def getDirection(self):
        for key, value in self.__directionDictionary.items():
            if value == self.__direction:
                return key

    @property
    def getPlane(self):
        return self.__getPlaneDictionary[self.__direction](self.__head)

    def validatePlane(self):
        return self.__validatePlaneDictionary[self.__direction](self.__head)

    def setPlane(self):
        self.__setDirectionDictionary[self.__direction](self.__head, self.__direction)

    def modifyPlane(self, head, direction):
        self.__setDirectionDictionary[self.__direction](self.__head, "-", "-")
        self.__head = head
        self.__direction = self.__directionDictionary[direction]
        self.setPlane()

    def destroyPlane(self):
        self.__setDirectionDictionary[self.__direction](self.__head, "X", "X")
        self.__head = "X"
