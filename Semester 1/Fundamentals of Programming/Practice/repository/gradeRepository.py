from domain.grade import Grade


class GradeRepository:
    def __init__(self):
        self._data = list()

    def __getitem__(self, item):
        return self._data[item]

    def __len__(self):
        return len(self._data)

    def loadFile(self):
        file = open("repository/grade.txt", "rt")
        for line in file:
            newLine = line.strip().split(" ")
            self.store(Grade(newLine[0], newLine[1], newLine[2], newLine[3]))
        file.close()

    def store(self, entity):
        for grade in self.getAll():
            if int(grade[1]) == int(entity.getAll()[1]) and int(grade[2]) == int(entity.getAll()[2]):
                raise ValueError("Entity with ID " + str(entity.id) + " already in repository!")
        self._data.append(entity)
        self.saveToFile()

    def getAll(self):
        listToReturn = list()
        for grade in self._data:
            listToReturn.append(grade.getAll())
        return listToReturn

    def getDetails(self):
        listOfDetails = ""
        for student in self._data:
            listOfDetails += student.getDetails() + "\n"
        return listOfDetails

    def saveToFile(self):
        file = open("repository/grade.txt", "wt")
        file.write(self.getDetails())
        file.close()
