from src.domain.validations import RepositoryError


class Repository:
    def __init__(self):
        self.__data = dict()

    def __getitem__(self, item):
        return self.__data[item]

    def __len__(self):
        return len(self.__data)

    def add(self, entity):
        if entity.id in self.__data:
            raise RepositoryError("Entity with ID " + str(entity.id) + " already in repository!")
        self.__data[entity.id] = entity

    def delete(self, entityID):
        if entityID not in self.__data:
            raise RepositoryError("Entity with ID " + str(entityID) + " does not exist!")
        self.__data.pop(entityID)

    def update(self, entityID, newEntity):
        if entityID not in self.__data:
            raise RepositoryError("Entity with ID " + str(entityID) + " does not exist!")
        self.__data[entityID].name = newEntity

    def get(self, entityID):
        return self.__data[entityID].name

    def getAll(self):
        returnList = list()
        for i in self.__data.values():
            returnList.append(i)
        return returnList
