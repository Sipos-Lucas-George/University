class Taxi:
    def __init__(self, taxiID, coordinateX, coordinateY, fare):
        if coordinateX < 0 or coordinateX > 100:
            raise ValueError("Coordinates should be between [0,100]")
        if coordinateY < 0 or coordinateY > 100:
            raise ValueError("Coordinates should be between [0,100]")
        self.__taxiID = taxiID
        self.__coordinateX = coordinateX
        self.__coordinateY = coordinateY
        self.__fare = fare

    @property
    def id(self):
        return self.__taxiID

    @property
    def coordinates(self):
        return self.__coordinateX, self.__coordinateY

    @property
    def fare(self):
        return self.__fare
