from src.domain.validations import DomainError


class Discipline:
    def __init__(self, disciplineID, disciplineName):
        if not str(disciplineID).isnumeric():
            raise DomainError("Discipline ID should contain only digits!")
        elif int(disciplineID) < 1:
            raise DomainError("Discipline ID should be greater than 0!")
        self.verifyIfDisciplineNameContainsOnlyLetters(disciplineName)
        self.__disciplineID = int(disciplineID)
        self.__disciplineName = disciplineName

    @property
    def id(self):
        return self.__disciplineID

    @property
    def name(self):
        return self.__disciplineName

    @name.setter
    def name(self, newDisciplineName):
        self.__disciplineName = newDisciplineName

    @staticmethod
    def verifyIfDisciplineNameContainsOnlyLetters(disciplineName):
        if not disciplineName.strip():
            raise DomainError("Discipline name should contain only letters!")
        disciplineName = disciplineName.split()
        for name in disciplineName:
            if not name.isalpha():
                raise DomainError("Discipline name should contain only letters!")
