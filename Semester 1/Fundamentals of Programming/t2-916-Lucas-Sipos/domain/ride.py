class Ride:
    def __init__(self, rideID, startX, startY, endX, endY):
        if startX < 0 or startX > 100 or startY < 0 or startY > 100 or endX < 0 or endX > 100 or endY < 0 or endY > 100:
            raise ValueError("Coordinates must be between [0,100]")
        self.__startX = startX
        self.__startY = startY
        self.__endX = endX
        self.__endY = endY
        self.__rideID = rideID

    @property
    def startCoordinate(self):
        return self.__startX, self.__startY

    @property
    def endCoordinate(self):
        return self.__endX, self.__endY

    @property
    def id(self):
        return self.__rideID
