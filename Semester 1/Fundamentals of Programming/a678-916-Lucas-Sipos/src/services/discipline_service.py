from src.repository.repository import Repository
from src.domain.discipline import Discipline


class DisciplineService:
    def __init__(self):
        self.__repository = Repository()

    def addDisciplineToDictionary(self, *discipline):
        self.__repository.add(Discipline(*discipline))

    def deleteDisciplineFromDictionary(self, disciplineID):
        self.__repository.delete(disciplineID)

    def updateDisciplineFromDictionary(self, disciplineID, disciplineName):
        self.__repository.update(disciplineID, disciplineName)

    def searchByIDInListOfDisciplines(self, argument):
        listToReturn = list()
        for discipline in self.getAllDisciplinesFromDictionary():
            if argument in str(discipline.id):
                listToReturn.append(discipline)
        return listToReturn

    def searchByNameInListOfDisciplines(self, argument):
        listToReturn = list()
        for discipline in self.getAllDisciplinesFromDictionary():
            if argument in str(discipline.name).lower():
                listToReturn.append(discipline)
        return listToReturn

    @staticmethod
    def sortByID(classObject):
        return classObject.id

    def sortDiscipline(self):
        listOfSortedDiscipline = self.getAllDisciplinesFromDictionary()
        listOfSortedDiscipline.sort(key=self.sortByID)
        return listOfSortedDiscipline

    def getDisciplineFromDictionary(self, disciplineID):
        return self.__repository.get(disciplineID)

    def getAllDisciplinesFromDictionary(self):
        return self.__repository.getAll()
