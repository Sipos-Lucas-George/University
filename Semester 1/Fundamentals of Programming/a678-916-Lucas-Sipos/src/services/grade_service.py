from src.repository.repository import Repository
from src.domain.grade import Grade


class GradeService:
    def __init__(self):
        self.__repository = Repository()
        self.__gradeID = 1

    def addGradeToDictionary(self, *grade):
        self.__repository.add(Grade(self.__gradeID, *grade))
        self.__gradeID += 1

    def deleteGradeFromDictionary(self, gradeID):
        self.__repository.delete(gradeID)

    def updateGradeFromDictionary(self, gradeID, gradeValue):
        self.__repository.update(gradeID, gradeValue)

    def sortASublistBySecondElement(self, givenList):
        givenList.sort(key=self.sortByDisciplineID)
        return givenList

    @staticmethod
    def sortByStudentID(classObject):
        return classObject.studentID

    @staticmethod
    def sortByDisciplineID(classObject):
        return classObject.disciplineID

    def sortGradesByStudents(self):
        listToReturn = self.getAllGradesFromDictionary()
        listToReturn.sort(key=self.sortByStudentID)
        return listToReturn

    def sortAllGradeByStudentAndByDiscipline(self):
        listOfGrades = self.getAllGradesFromDictionary()
        listOfGrades.sort(key=self.sortByStudentID)
        lastStudentID = listOfGrades[0].studentID
        counterOfSublists = 0
        beginningOfNewSublist = 0
        for grade in listOfGrades:
            counterOfSublists += 1
            if grade.studentID != lastStudentID:
                listOfGrades[beginningOfNewSublist:counterOfSublists-1] = self.sortASublistBySecondElement(listOfGrades[beginningOfNewSublist:counterOfSublists-1])
                lastStudentID = grade.studentID
                beginningOfNewSublist = counterOfSublists-1
        listOfGrades[beginningOfNewSublist:] = self.sortASublistBySecondElement(listOfGrades[beginningOfNewSublist:])
        return listOfGrades

    def getAllFailingStudents(self, studentService, disciplineService):
        listOfGrades = self.sortAllGradeByStudentAndByDiscipline()
        listOfFailingStudents = list()
        sumOfGrades = 0
        numberOfGrades = 0
        lastStudentID = listOfGrades[0].studentID
        lastDisciplineID = listOfGrades[0].disciplineID
        for grade in listOfGrades:
            if grade.studentID == lastStudentID and grade.disciplineID == lastDisciplineID:
                sumOfGrades += grade.name
                numberOfGrades += 1
            else:
                average = float(sumOfGrades/numberOfGrades)
                if average < 5:
                    listOfFailingStudents.append([grade, "%.3f" % average])
                sumOfGrades = grade.name
                numberOfGrades = 1
                lastStudentID = grade.studentID
                lastDisciplineID = grade.disciplineID
        average = float(sumOfGrades/numberOfGrades)
        if average < 5:
            listOfFailingStudents.append([listOfGrades[len(listOfGrades)-1], "%.3f" % average])
        completeListOfFailingStudents = list()
        for grade in listOfFailingStudents:
            completeListOfFailingStudents.append([studentService.getStudentFromDictionary(grade[0].studentID), disciplineService.getDisciplineFromDictionary(grade[0].disciplineID), grade[1]])
        return completeListOfFailingStudents

    def getTopStudentsAggregatedAverage(self, studentService):
        listOfGrades = self.sortAllGradeByStudentAndByDiscipline()
        listOfTopStudents = list()
        sumOfGrades = 0
        numberOfGrades = 0
        numberOfDisciplines = 0
        aggregatedAverage = 0
        verifyLastOperation = 0
        lastStudentID = listOfGrades[0].studentID
        lastDisciplineID = listOfGrades[0].disciplineID
        for i in listOfGrades:
            if i.studentID == lastStudentID and i.disciplineID == lastDisciplineID:
                sumOfGrades += i.name
                numberOfGrades += 1
                verifyLastOperation = 1
            elif i.studentID == lastStudentID and i.disciplineID != lastDisciplineID:
                aggregatedAverage += float(sumOfGrades/numberOfGrades)
                numberOfDisciplines += 1
                sumOfGrades = i.name
                numberOfGrades = 1
                lastStudentID = i.studentID
                lastDisciplineID = i.disciplineID
                verifyLastOperation = 2
            else:
                if aggregatedAverage == 0:
                    aggregatedAverage = float(sumOfGrades/numberOfGrades)
                else:
                    aggregatedAverage += float(sumOfGrades / numberOfGrades)
                    aggregatedAverage = float(aggregatedAverage/(numberOfDisciplines+1))
                listOfTopStudents.append([aggregatedAverage, lastStudentID])
                aggregatedAverage = 0
                numberOfDisciplines = 0
                sumOfGrades = i.name
                numberOfGrades = 1
                lastStudentID = i.studentID
                lastDisciplineID = i.disciplineID
                verifyLastOperation = 3
        if verifyLastOperation == 3:
            listOfTopStudents.append([float(sumOfGrades/numberOfGrades), lastStudentID])
        elif verifyLastOperation == 2 or verifyLastOperation == 1:
            aggregatedAverage += float(sumOfGrades/numberOfGrades)
            listOfTopStudents.append([float(aggregatedAverage/(numberOfDisciplines + 1)), lastStudentID])
        listOfTopStudents.sort(reverse=True)
        completeListOfFailingStudents = list()
        for i in listOfTopStudents:
            completeListOfFailingStudents.append([studentService.getStudentFromDictionary(i[1]), i[0]])
        return completeListOfFailingStudents

    def getTopDisciplines(self, disciplineService):
        listOfGrades = self.getAllGradesFromDictionary()
        listOfGrades.sort(key=self.sortByDisciplineID)
        listOfTopAverageAtDisciplines = list()
        sumOfGrades = 0
        numberOfGrades = 0
        lastDisciplineID = listOfGrades[0].disciplineID
        for grade in listOfGrades:
            if grade.disciplineID == lastDisciplineID:
                sumOfGrades += grade.name
                numberOfGrades += 1
            else:
                listOfTopAverageAtDisciplines.append([float(sumOfGrades/numberOfGrades), lastDisciplineID])
                sumOfGrades = grade.name
                numberOfGrades = 1
                lastDisciplineID = grade.disciplineID
        listOfTopAverageAtDisciplines.append([float(sumOfGrades / numberOfGrades), lastDisciplineID])
        listOfTopAverageAtDisciplines.sort(reverse=True)
        completeListOfFailingStudents = list()
        for grade in listOfTopAverageAtDisciplines:
            completeListOfFailingStudents.append([disciplineService.getDisciplineFromDictionary(grade[1]), grade[0]])
        return completeListOfFailingStudents

    def getLastElement(self):
        return self.__gradeID - 1

    def getAllGradesFromDictionary(self):
        return self.__repository.getAll()
