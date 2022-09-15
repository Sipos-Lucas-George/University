from src.domain.flight import Flight
from src.repository.repository import Repository


class Service:
    def __init__(self, repository: Repository):
        self.__repository = repository

    def addFlight(self, ident, departureCity, time, arrivalCity, arrivalTime):
        """
        Just receiving information about the flight
        :param ident: - string
        :param departureCity: - string
        :param time: - string
        :param arrivalCity: - string
        :param arrivalTime: - string
        :return: adds the object Flight(ident, departureCity, time, arrivalCity, arrivalTime) in repository memory
        """
        if self.verifyInput(departureCity, time, arrivalCity, arrivalTime) is True:
            self.__repository.add(Flight(ident, departureCity, time, arrivalCity, arrivalTime))

    def deleteFlight(self, ident):
        self.__repository.delete(ident)

    def getAllFlights(self):
        return self.__repository.getAll()

    def getAirports(self):
        listOfAirports = self.__repository.getAirports()
        return listOfAirports

    @staticmethod
    def verifyInput(departureCity, time, arrivalCity, arrivalTime):
        """
        Verify if input is correct or not
        :param departureCity: - string, only letter
        :param time: - string mask: xx:yy x,y - string, only numbers; xx - [00, 23] and yy - [00, 59]
        :param arrivalCity: - string, only letter
        :param arrivalTime: - string mask: xx:yy x,y - string, only numbers; xx - [00, 23] and yy - [00, 59]
        :return: if the input is incorrect raises a ValueError else True
        """
        if departureCity.isalpha():
            pass
        else:
            raise ValueError
        if arrivalCity.isalpha():
            pass
        else:
            raise ValueError

        if time[:2].isnumeric() and time[3:5].isnumeric() and arrivalTime[:2].isnumeric() and arrivalTime[3:5].isnumeric():
            pass
        else:
            raise ValueError
        if int(time[:2]) < 0 or int(time[:2]) > 23 or time[2] != ":" or int(time[3:5]) < 0 or int(time[3:5]) > 59:
            raise ValueError
        if int(arrivalTime[:2]) < 0 or int(arrivalTime[:2]) > 23 or arrivalTime[2] != ":" \
                or int(arrivalTime[3:5]) < 0 or int(arrivalTime[3:5]) > 59:
            raise ValueError
        if int(time[:2]) - int(arrivalTime[:2]) > 0:
            raise ValueError
        x = int(time[:2]) - int(arrivalTime[:2])
        if x < 0:
            minutes = (60 - int(time[3:5])) + int(arrivalTime[3:5])
            if minutes > 90 or minutes < 15:
                return ValueError
        elif x == 0:
            minutes = int(arrivalTime[3:5]) - int(time[3:5])
            if minutes > 90 or minutes < 15:
                return ValueError
        return True
