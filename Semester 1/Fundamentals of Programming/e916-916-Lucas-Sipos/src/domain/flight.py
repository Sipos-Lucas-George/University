class Flight:
    def __init__(self, identifier, departureCity, time, arrivalCity, arrivalTime):
        self.__identifier = identifier
        self.__departureCity = departureCity
        self.__time = time
        self.__arrivalCity = arrivalCity
        self.__arrivalTime = arrivalTime

    @property
    def id(self):
        return self.__identifier

    @property
    def all(self):
        return self.__departureCity, self.__time, self.__arrivalCity, self.__arrivalTime

    def getDepartureCity(self):
        return self.__departureCity

    def getTime(self):
        return self.__time

    def getArrivalCity(self):
        return self.__arrivalCity

    def getArrivalTime(self):
        return self.__arrivalTime

    def getAirport1(self):
        return self.__departureCity

    def getAirport2(self):
        return self.__arrivalCity
