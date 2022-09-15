from repository.studentRepository import StudentRepository
from domain.student import Student


class StudentController:
    def __init__(self, repository: StudentRepository):
        self.__repository = repository

    def create(self, identification, name, group):
        self.__repository.store(Student(identification, name, group))

    def remove(self, studentID):
        return self.__repository.remove(studentID)

    def assignLaboratory(self, studentID, laboratoryNumber, laboratoryProblem):
        self.__repository.assignLaboratory(studentID, laboratoryNumber, laboratoryProblem)

    def assignLaboratoryGroup(self, groupID, laboratoryNumber):
        self.__repository.assignLaboratoryGroup(groupID, laboratoryNumber)

    def getAllByGroup(self, group):
        return self.__repository.getAllByGroup(group)

    def getAll(self):
        return self.__repository.getAll()
