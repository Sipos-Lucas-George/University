from domain.ride import Ride
from repository.repository import Repository


class RideService:
    def __init__(self):
        self.__repository = Repository()
        self.__id = 1

    def addRide(self, *ride):
        self.__repository.add(Ride(*ride))
        self.__id += 1

    def deleteRide(self, gradeID):
        self.__repository.delete(gradeID)
