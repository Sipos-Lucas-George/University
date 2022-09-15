from src.domain.validations import DomainError


class Student:
    def __init__(self, studentID, studentName):
        if not str(studentID).isnumeric():
            raise DomainError("Student ID should contain only digits!")
        elif int(studentID) < 1:
            raise DomainError("Student ID should be greater than 0!")
        self.verifyIfStudentNameContainsOnlyLetters(studentName)
        self.__studentID = int(studentID)
        self.__studentName = studentName

    @property
    def id(self):
        return self.__studentID

    @property
    def name(self):
        return self.__studentName

    @name.setter
    def name(self, newStudentName):
        self.verifyIfStudentNameContainsOnlyLetters(newStudentName)
        self.__studentName = newStudentName

    @staticmethod
    def verifyIfStudentNameContainsOnlyLetters(studentName):
        if not studentName.strip():
            raise DomainError("Student name should contain only letters!")
        studentName = studentName.split()
        for name in studentName:
            if not name.isalpha():
                raise DomainError("Student name should contain only letters!")
