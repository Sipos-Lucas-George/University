from src.domain.validations import RepositoryError
from src.domain.student import Student
from src.domain.discipline import Discipline
from src.domain.grade import Grade
import pickle


class Repository:
    def __init__(self):
        self._data = dict()

    def __getitem__(self, item):
        return self._data[item]

    def __len__(self):
        return len(self._data)

    def add(self, entity):
        if entity.id in self._data:
            raise RepositoryError("Entity with ID " + str(entity.id) + " already in repository!")
        self._data[entity.id] = entity

    def delete(self, entityID):
        if entityID not in self._data:
            raise RepositoryError("Entity with ID " + str(entityID) + " does not exist!")
        self._data.pop(entityID)

    def update(self, entityID, newEntity):
        if entityID not in self._data:
            raise RepositoryError("Entity with ID " + str(entityID) + " does not exist!")
        self._data[entityID].name = newEntity

    def get(self, entityID):
        return self._data[entityID].name

    def getAll(self):
        returnList = list()
        for i in self._data.values():
            returnList.append(i)
        return returnList


class TextFileRepository(Repository):
    def __init__(self, saveFile, domain):
        super().__init__()
        self.__textFileName = saveFile
        self.__domainName = domain
        self._loadFile()

    def interpretAndAdd(self, domain, _id, arguments):
        self.add(eval(domain + "(" + _id + ",*" + str(str(arguments[:-1]).split(",")) + ")"))

    def _loadFile(self):
        try:
            file = open(self.__textFileName, "rt")
            for line in file.readlines():
                domain, _id, arguments = line.split(maxsplit=2, sep=",")
                self.interpretAndAdd(domain, _id, arguments)
            file.close()
        except FileNotFoundError:
            print(f"File not found. Input = {self.__textFileName}")

    def _save_file(self):
        file = open(self.__textFileName, "w")

        for item in self._data.values():
            file.write(self.__domainName + "," + ",".join(str(part) for part in vars(item).values()) + "\n")

        file.close()

    def add(self, entity):
        super(TextFileRepository, self).add(entity)
        self._save_file()

    def delete(self, entityID):
        super(TextFileRepository, self).delete(entityID)
        self._save_file()

    def update(self, entityID, newEntity):
        super(TextFileRepository, self).update(entityID, newEntity)
        self._save_file()


class BinaryFileRepository(Repository):
    def __init__(self, saveFile, domain):
        super().__init__()
        self.__binaryFileName = saveFile
        self.__domainName = domain
        self._loadFile()

    def interpretAndAdd(self, domain, _id, arguments):
        self.add(eval(domain + "(" + _id + ",*" + str(str(arguments[:-1]).split(",")) + ")"))

    def _loadFile(self):
        try:
            file = open(self.__binaryFileName, "rb")
            self._data = pickle.load(file)
            file.close()
        except EOFError:
            print("File empty.")

    def _save_file(self):
        file = open(self.__binaryFileName, "wb")
        pickle.dump(self._data, file)
        file.close()

    def add(self, entity):
        super(BinaryFileRepository, self).add(entity)
        self._save_file()

    def delete(self, entityID):
        super(BinaryFileRepository, self).delete(entityID)
        self._save_file()

    def update(self, entityID, newEntity):
        super(BinaryFileRepository, self).update(entityID, newEntity)
        self._save_file()
