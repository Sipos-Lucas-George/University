from domain.taxi import Taxi
from repository.repository import Repository


class TaxiService:
    def __init__(self):
        self.__repository = Repository()
        self.__id = 1

    def addTaxi(self, *taxi):
        self.__repository.add(Taxi(self.__id, *taxi))
        self.__id += 1

    def getCloseTaxi(self, coordinateX, coordinateY):
        minimumDistance = 100
        for taxi in self.getAllTaxi():
            x, y = taxi.coordinates
            if abs(coordinateX - x) + abs(coordinateY - y) < minimumDistance:
                minimumDistance = abs(coordinateX - x) + abs(coordinateY - y)
                minX, minY = x, y
                address = taxi
        address = Taxi(self.__id, minX, minY, minimumDistance)
        self.__id += 1

    def getAllTaxi(self):
        return self.__repository.getAll()
