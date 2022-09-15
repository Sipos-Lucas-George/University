from src.domain.flight import Flight


class Repository:
    def __init__(self):
        self.__data = dict()

    def __getitem__(self, item):
        return self.__data[item]

    def __len__(self):
        return len(self.__data)

    def add(self, entity: Flight):
        """
        Verify if there is another such identifier or time or arrivalTime and adds to dictionary the object Flight
        :param entity: - Flight
        :return: Raises a ValueError if id or time or arrivalTime already exist
        """
        if entity.id in self.__data:
            raise ValueError
        for values in self.__data.values():
            if entity.getTime() == values.getTime() and entity.getDepartureCity() == values.getDepartureCity():
                raise ValueError
            if entity.getArrivalTime() == values.getArrivalTime() and entity.getArrivalCity() == values.getArrivalCity():
                raise ValueError
        self.__data[entity.id] = entity

    def delete(self, entityID):
        if entityID not in self.__data:
            raise ValueError
        self.__data.pop(entityID)

    def getAirports(self):
        returnList = list()
        for i in self.__data.values():
            returnList.append(i.getAirport1)
            returnList.append(i.getAirport2)
        return returnList

    def getAll(self):
        returnList = list()
        for i in self.__data.values():
            returnList.append(i)
        return returnList
