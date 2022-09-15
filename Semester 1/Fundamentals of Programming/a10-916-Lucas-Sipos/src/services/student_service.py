from src.domain.student import Student


class StudentService:
    def __init__(self, repository):
        self.__repository = repository

    def addStudentToDictionary(self, *student):
        self.__repository.add(Student(*student))

    def deleteStudentFromDictionary(self, studentID):
        self.__repository.delete(studentID)

    def updateStudentFromDictionary(self, studentID, studentName):
        self.__repository.update(studentID, studentName)

    def searchByIDInListOfStudents(self, argument):
        listToReturn = list()
        for student in self.getAllStudentsFromDictionary():
            if argument in str(student.id):
                listToReturn.append(student)
        return listToReturn

    def searchByNameInListOfStudents(self, argument):
        listToReturn = list()
        for student in self.getAllStudentsFromDictionary():
            if argument in str(student.name).lower():
                listToReturn.append(student)
        return listToReturn

    @staticmethod
    def sortByID(classObject):
        return classObject.id

    def sortStudents(self):
        listOfSortedStudents = self.getAllStudentsFromDictionary()
        listOfSortedStudents.sort(key=self.sortByID)
        return listOfSortedStudents

    def getStudentFromDictionary(self, studentID):
        return self.__repository.get(studentID)

    def getAllStudentsFromDictionary(self):
        return self.__repository.getAll()
