from src.domain.validations import DomainError


class Grade:
    def __init__(self, gradeID, studentID, disciplineID, gradeValue):
        if str(gradeValue).isalpha():
            raise DomainError("Grade value should contain only digits!")
        elif int(gradeValue) < 1 or int(gradeValue) > 10:
            raise DomainError("Grade value should be between [1,10]!")
        self.__gradeID = gradeID
        self.__studentID = int(studentID)
        self.__disciplineID = int(disciplineID)
        self.__gradeValue = int(gradeValue)

    @property
    def id(self):
        return self.__gradeID

    """
    I name the gradeValue property name so that I can use the update method in repository
    """
    @property
    def name(self):
        return self.__gradeValue

    @property
    def studentID(self):
        return self.__studentID

    @property
    def disciplineID(self):
        return self.__disciplineID

    @name.setter
    def name(self, newGradeValue):
        if str(newGradeValue).isalpha():
            raise DomainError("Grade value should contain only digits!")
        elif int(newGradeValue) < 1 or int(newGradeValue) > 10:
            raise DomainError("Grade value should be between [1,10]!")
        self.__gradeValue = int(newGradeValue)
