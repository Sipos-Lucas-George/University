from repository.gradeRepository import GradeRepository
from domain.student import Student


class StudentRepository:
    def __init__(self, gradeRepository: GradeRepository):
        self.__gradeRepository = gradeRepository
        self._data = list()
        self.__assignments = list()
        self.loadFile()

    def __getitem__(self, item):
        return self._data[item]

    def __len__(self):
        return len(self._data)

    def loadFile(self):
        file = open("repository/student.txt", "rt")
        for line in file:
            newLine = line.strip().split(" ")
            self.store(Student(newLine[0], newLine[1], newLine[2]))
        file.close()

    def store(self, entity):
        for student in self.getAll():
            if int(student[0]) == int(entity.id):
                raise ValueError("Entity with ID " + str(entity.id) + " already in repository!")
        self._data.append(entity)
        self.saveToFile()

    def remove(self, entityID):
        i = 0
        for student in self.getAll():
            if int(student[0]) == int(entityID):
                i += 1
        if i == 0:
            raise ValueError("Entity with ID " + str(entityID) + " does not exist!")
        elif str(entityID) in self.getAllIDs():
            self._data.remove(self.find(entityID))
            self.saveToFile()
            return True
        return False

    def assignLaboratory(self, studentID, laboratoryNumber, laboratoryProblem):
        if laboratoryNumber < 1 or laboratoryNumber > 14:
            raise ValueError("Incorrect input!")
        if laboratoryProblem < 1 or laboratoryProblem > 20:
            raise ValueError("Incorrect input!")
        for assignment in self.__assignments:
            if studentID == assignment[0] and laboratoryNumber == self.__assignments[1]:
                raise ValueError("Entity with ID " + str(studentID) + " was already assigned a problem!")
        getStudent = self.find(studentID)
        self.__assignments.append([studentID, laboratoryNumber, laboratoryProblem, getStudent.group])

    def assignLaboratoryGroup(self, groupID, laboratoryNumber):
        laboratoryProblem = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
        if laboratoryNumber < 1 or laboratoryNumber > 14:
            raise ValueError("Incorrect input!")
        listToAssign = self.getStudentsByGroup(groupID)
        for assignment in self.__assignments:
            if groupID == assignment[3] and laboratoryNumber == self.__assignments[1]:
                laboratoryProblem.remove(assignment[2])
                getStudent = self.find(assignment[0])
                listToAssign.remove([getStudent.id, getStudent.name, getStudent.group])
        for assignment in listToAssign:
            self.__assignments.append([assignment[0], laboratoryNumber, laboratoryProblem, assignment[2]])

    def getStudentsByGroup(self, groupID):
        listOfStudents = list()
        for student in self.getAll():
            if student[2] == groupID:
                listOfStudents.append(student)
        return listOfStudents

    def find(self, entityID):
        i = 0
        for student in self.getAll():
            if int(student[0]) == int(entityID):
                return self._data[i]
            i += 1

    def getAllByGroup(self, group):
        listToReturn = list()
        for student in self._data:
            if student.group == group:
                listToReturn.append(student.getAll())
        return listToReturn

    def getAllIDs(self):
        listToReturn = list()
        for student in self._data:
            listToReturn.append(student.getAll()[0])
        return listToReturn

    def getAll(self):
        listToReturn = list()
        for student in self._data:
            listToReturn.append(student.getAll())
        return listToReturn

    def getDetails(self):
        listOfDetails = ""
        for student in self._data:
            listOfDetails += student.getDetails() + "\n"
        return listOfDetails

    def saveToFile(self):
        file = open("repository/student.txt", "wt")
        file.write(self.getDetails())
        file.close()
