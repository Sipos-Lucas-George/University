from domain.studentValidator import StudentValidator


class Student:
    def __init__(self, identification, name, group):
        StudentValidator(name, group)
        self.__id = identification
        self.__name = name
        self.__group = group

    @property
    def id(self):
        return self.__id

    @property
    def name(self):
        return self.__name

    @property
    def group(self):
        return self.__group

    def getAll(self):
        return [self.__id, self.__name, self.__group]

    def getDetails(self):
        return str(self.__id) + " " + str(self.__name) + " " + str(self.__group)
