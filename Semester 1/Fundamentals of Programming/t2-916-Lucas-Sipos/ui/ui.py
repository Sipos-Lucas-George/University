from services.taxi_service import TaxiService
from services.ride_service import RideService
from random import *
import traceback


class UserInterface:
    def __init__(self):
        self.__taxiService = TaxiService()
        self.__rideService = RideService()
        self.__commandDictionary = {
            "add": self.addRide,
        }

    def start(self):
        operationalTaxi = int(input("How many operational Taxi do you want: "))
        self.randomCoordinateGenerator(operationalTaxi)
        while True:
            #self.printTaxi()
            inputCommand = (input("Enter you option: ")).strip()
            try:
                self.__commandDictionary[inputCommand]()
            except ValueError as error:
                print(str(error))
                traceback.print_exc()
            except KeyError:
                print(f"The command {inputCommand} does not exist!")
                traceback.print_exc()

    def addRide(self):
        coordinateX = int(input("Coordinate 1: "))
        coordinateY = int(input("Coordinate 2: "))
        self.__taxiService.getCloseTaxi(coordinateX, coordinateY)

    def randomCoordinateGenerator(self, operationalTaxi):
        seed(1)
        listForVerify = list()
        while operationalTaxi > 0:
            coordinateX = randint(0, 100)
            coordinateY = randint(0, 100)
            if self.verifyIfCoordinatesCorrect(coordinateX, coordinateY, listForVerify) is True:
                self.__taxiService.addTaxi(coordinateX, coordinateY, 0)
                operationalTaxi -= 1
                listForVerify.append([coordinateX, coordinateY])

    @staticmethod
    def verifyIfCoordinatesCorrect(coordinateX, coordinateY, listForVerify):
        if len(listForVerify) == 0:
            return True
        for x, y in listForVerify:
            if abs(coordinateX-x) + abs(coordinateY-y) < 6:
                return False
        return True
