from domain.gradeValidator import GradeValidator


class Grade:
    def __init__(self, studentID, laboratoryNumber, laboratoryProblem, value):
        GradeValidator(laboratoryNumber, laboratoryProblem, value)
        self.__id = studentID
        self.__laboratoryNumber = laboratoryNumber
        self.__laboratoryProblem = laboratoryProblem
        self.__value = value

    @property
    def id(self):
        return self.__id

    def getAll(self):
        return [self.__id, self.__laboratoryNumber, self.__laboratoryProblem, self.__value]

    def getDetails(self):
        toReturn = f"{self.__id} {self.__laboratoryNumber} {self.__laboratoryProblem} {self.__value}"
        return toReturn
