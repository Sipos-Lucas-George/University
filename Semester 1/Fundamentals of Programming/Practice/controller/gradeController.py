from repository.gradeRepository import GradeRepository
from domain.grade import Grade


class GradeController:
    def __init__(self, repository: GradeRepository):
        self.__repository = repository

    def create(self, studentID, laboratoryNumber, laboratoryProblem, grade):
        self.__repository.store(Grade(studentID, laboratoryNumber, laboratoryProblem, grade))

    def top(self, group, listOfStudents):
        listOfGrades = self.__repository.getAll()
        listToReturn = list()
        return listOfStudents
