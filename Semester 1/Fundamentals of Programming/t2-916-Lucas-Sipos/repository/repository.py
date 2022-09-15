class Repository:
    def __init__(self):
        self._data = dict()

    def __getitem__(self, item):
        return self._data[item]

    def __len__(self):
        return len(self._data)

    def add(self, entity):
        self._data[entity.id] = entity

    def delete(self, entityID):
        if entityID not in self._data:
            raise ValueError("Entity with ID " + str(entityID) + " does not exist!")
        del self._data[entityID]

    def update(self, entityID, newEntity):
        if entityID not in self._data:
            raise ValueError("Entity with ID " + str(entityID) + " does not exist!")
        self._data[entityID].coordinates = newEntity

    def get(self, entityID):
        return self._data[entityID].coordinates

    def getAll(self):
        returnList = list()
        for i in self._data.values():
            returnList.append(i)
        return returnList
