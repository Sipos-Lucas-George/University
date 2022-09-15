from src.domain.validations import RepositoryError, DomainError
from random import shuffle
import traceback


class UserInterface:
    def __init__(self, studentService, disciplineService, gradeService, testFlag=True):
        self.__studentService = studentService
        self.__disciplineService = disciplineService
        self.__gradeService = gradeService
        self.__commandDictionary = {
            "add": self.userInterfaceAdd,
            "delete": self.userInterfaceDelete,
            "update": self.userInterfaceUpdate,
            "search": self.userInterfaceSearch,
            "statistic 1": self.userInterfaceFailingStudents,
            "statistic 2": self.userInterfaceTopStudents,
            "statistic 3": self.userInterfaceTopDisciplines,
            "list": self.userInterfaceList
        }
        self.__undo = list()
        self.__redo = list()
        self.__undoCounter = 1
        self.__redoCounter = 1
        self.__undoDictionary = {
            "add": self.userInterfaceAddForUndo,
            "delete": self.userInterfaceDeleteForUndo,
            "update": self.userInterfaceUpdateForUndo
        }
        self.__redoDictionary = {
            "add": self.userInterfaceAddForRedo,
            "delete": self.userInterfaceDeleteForRedo,
            "update": self.userInterfaceUpdateForRedo
        }
        if testFlag is False:
            self.startUp20Elements()

    @staticmethod
    def displayMenu():
        print("\nEnter 'add' to add an object")
        print("Enter 'delete' to delete an object")
        print("Enter 'update' to update an object")
        print("Enter 'search' to search an object")
        print("Enter 'list' to display some object")
        print("Enter 'statistic 1' to display all failing students")
        print("Enter 'statistic 2' to display top students")
        print("Enter 'statistic 3' to display top disciplines")
        print("Enter 'menu' to display the menu commands")
        print("Enter 'undo' to undo last performed command")
        print("Enter 'redo' to redo the last undo command")
        print("Enter 'exit' to exit the program\n")

    def startUp20Elements(self):
        nameForStudents = ["Cheryl", "Pace", "Larry"]
        nameForDisciplines = ["IT   ", "PE   ", "Maths"]
        gradesToShuffle = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        for i in range(0, 3):
            idForEverythingInString = str(i + 1)
            self.__studentService.addStudentToDictionary(*[idForEverythingInString, nameForStudents[i]])
            self.__disciplineService.addDisciplineToDictionary(*[idForEverythingInString, nameForDisciplines[i]])
        for i in range(3):
            for j in range(3):
                shuffle(gradesToShuffle)
                self.__gradeService.addGradeToDictionary(i + 1, j + 1, str(gradesToShuffle[0]))

    def start(self):
        self.displayMenu()
        while True:
            inputCommand = (input("Enter you option: ")).strip()
            try:
                if inputCommand == "menu":
                    self.displayMenu()
                elif inputCommand == "exit":
                    return
                elif inputCommand == "undo":
                    commandsAndArguments = self.__undo[-self.__undoCounter].split(".")
                    self.__undoDictionary[commandsAndArguments[0]](*commandsAndArguments[1:])
                    self.__undoCounter += 1
                    self.__redoCounter += 1
                elif inputCommand == "redo":
                    if self.__redoCounter != 1:
                        self.__redoCounter -= 1
                        self.__undoCounter -= 1
                        commandsAndArguments = self.__redo[-self.__redoCounter].split(".")
                        self.__redoDictionary[commandsAndArguments[0]](*commandsAndArguments[1:])
                    else:
                        raise IndexError("There is nothing to redo!")
                else:
                    if inputCommand == "add" or inputCommand == "delete" or inputCommand == "update":
                        for i in range(1, self.__undoCounter):
                            self.__undo.pop()
                        for i in range(1, self.__redoCounter):
                            self.__redo.pop()
                        self.__undoCounter = 1
                        self.__redoCounter = 1
                    self.__commandDictionary[inputCommand]()
            except ValueError as error:
                print(str(error))
                traceback.print_exc()
            except KeyError:
                print(f"The command {inputCommand} does not exist!")
                traceback.print_exc()
            except IndexError:
                print("There is nothing to undo!")
                traceback.print_exc()

    def userInterfaceAdd(self):
        objectChosen = (input("Enter the object you want to work with: ")).strip()
        arguments = []
        try:
            if objectChosen == "student":
                arguments.append((input("Enter id of student: ")).strip())
                arguments.append((input("Enter student's name: ")).strip())
                self.__studentService.addStudentToDictionary(*arguments)
                self.__undo.append(f"delete.student.{arguments[0]}")
                self.__redo.append(f"add.student.{arguments[0]}.{arguments[1]}")
            elif objectChosen == "discipline":
                arguments.append((input("Enter id of discipline: ")).strip())
                arguments.append((input("Enter discipline's name: ")).strip())
                self.__disciplineService.addDisciplineToDictionary(*arguments)
                self.__undo.append(f"delete.discipline.{arguments[0]}")
                self.__redo.append(f"add.discipline.{arguments[0]}.{arguments[1]}")
            elif objectChosen == "grade":
                arguments.append((input("Enter id of student: ")).strip())
                arguments.append((input("Enter id of discipline: ")).strip())
                arguments.append((input("Enter grade: ")).strip())
                if self.verifyDisciplineIDAndStudentIDForGradeClass(arguments[0], arguments[1]) is True:
                    self.__gradeService.addGradeToDictionary(*arguments)
                    self.__redo.append(f"add.grade.{arguments[0]}.{arguments[1]}.{arguments[2]}")
                    self.__undo.append(f"delete.grade.{self.__gradeService.getLastElement()}")
                else:
                    raise ValueError("The student/discipline id does not exist!")
            else:
                raise ValueError(f"The service {objectChosen} does not exist!")
        except RepositoryError as error:
            print(str(error))
            traceback.print_exc()
        except DomainError as error:
            print(str(error))
            traceback.print_exc()

    def userInterfaceDelete(self):
        objectChosen = (input("Enter the object you want to work with: ")).strip()
        arguments = []
        try:
            if objectChosen == "student":
                arguments.append(int((input("Enter id of student you want to delete: ")).strip()))
                rememberStudentNameForUndo = self.__studentService.getStudentFromDictionary(arguments[0])
                rememberGradesInformationToUndo = ""
                self.__studentService.deleteStudentFromDictionary(*arguments)
                for grade in self.__gradeService.getAllGradesFromDictionary():
                    if grade.studentID == arguments[0]:
                        rememberGradesInformationToUndo += f".{grade.studentID}.{grade.disciplineID}.{grade.name}"
                        self.__gradeService.deleteGradeFromDictionary(int(grade.id))
                self.__undo.append(
                    f"add.student.{arguments[0]}.{rememberStudentNameForUndo}{rememberGradesInformationToUndo}")
                self.__redo.append(f"delete.student.{arguments[0]}")
            elif objectChosen == "discipline":
                arguments.append(int((input("Enter id of discipline you want to delete: ")).strip()))
                rememberDisciplineNameForUndo = self.__disciplineService.getDisciplineFromDictionary(arguments[0])
                rememberGradesInformationToUndo = ""
                self.__disciplineService.deleteDisciplineFromDictionary(*arguments)
                for grade in self.__gradeService.getAllGradesFromDictionary():
                    if grade.disciplineID == arguments[0]:
                        rememberGradesInformationToUndo += f".{grade.studentID}.{grade.disciplineID}.{grade.name}"
                        self.__gradeService.deleteGradeFromDictionary(int(grade.id))
                self.__undo.append(
                    f"add.discipline.{arguments[0]}.{rememberDisciplineNameForUndo}{rememberGradesInformationToUndo}")
                self.__redo.append(f"delete.discipline.{arguments[0]}")
            elif objectChosen == "grade":
                arguments.append(int((input("Enter id of student: ")).strip()))
                arguments.append(int((input("Enter id of discipline: ")).strip()))
                arguments.append(int((input("Enter the index of the grade you want to delete: ")).strip()))
                counterGrades = 0
                if self.verifyDisciplineIDAndStudentIDForGradeClass(arguments[0], arguments[1]) is True:
                    for grade in self.__gradeService.getAllGradesFromDictionary():
                        if grade.studentID == arguments[0] and grade.disciplineID == arguments[1]:
                            counterGrades += 1
                            if counterGrades == arguments[2]:
                                rememberArgumentsForRedo = f"{arguments[0]}.{arguments[1]}.{arguments[2]}"
                                rememberArgumentsForUndo = f"{arguments[0]}.{arguments[1]}.{grade.name}"
                                self.__gradeService.deleteGradeFromDictionary(int(grade.id))
                                self.__redo.append(f"delete.grade.{rememberArgumentsForRedo}")
                                self.__undo.append(f"add.grade.{rememberArgumentsForUndo}")
                                return
                else:
                    raise ValueError("The student/discipline id does not exist!")
            else:
                raise ValueError(f"The service {objectChosen} does not exist!")
        except RepositoryError as error:
            print(str(error))
            traceback.print_exc()
        except DomainError as error:
            print(str(error))
            traceback.print_exc()

    def userInterfaceUpdate(self):
        objectChosen = (input("Enter the object you want to work with: ")).strip()
        arguments = []
        try:
            if objectChosen == "student":
                arguments.append(int((input("Enter id of student you want to update: ")).strip()))
                arguments.append((input("Enter the name you want to give to this student: ")).strip())
                rememberStudentName = self.__studentService.getStudentFromDictionary(arguments[0])
                self.__studentService.updateStudentFromDictionary(*arguments)
                self.__undo.append(f"update.student.{arguments[0]}.{rememberStudentName}")
                self.__redo.append(f"update.student.{arguments[0]}.{arguments[1]}")
            elif objectChosen == "discipline":
                arguments.append(int((input("Enter id of discipline you want to update: ")).strip()))
                arguments.append((input("Enter the name you want to give to this discipline: ")).strip())
                rememberDisciplineName = self.__disciplineService.getDisciplineFromDictionary(arguments[0])
                self.__disciplineService.updateDisciplineFromDictionary(*arguments)
                self.__undo.append(f"update.discipline.{arguments[0]}.{rememberDisciplineName}")
                self.__redo.append(f"update.discipline.{arguments[0]}.{arguments[1]}")
            elif objectChosen == "grade":
                arguments.append(int((input("Enter id of student: ")).strip()))
                arguments.append(int((input("Enter id of discipline: ")).strip()))
                arguments.append(int((input("Enter position of the grade you want to update: ")).strip()))
                arguments.append(
                    int((input("Enter the grade you want to give to this student at this discipline: ")).strip()))
                verifyThePositionOfTheGrade = 0
                if self.verifyDisciplineIDAndStudentIDForGradeClass(arguments[0], arguments[1]) is True:
                    for grade in self.__gradeService.getAllGradesFromDictionary():
                        if grade.studentID == arguments[0] and grade.disciplineID == arguments[1]:
                            verifyThePositionOfTheGrade += 1
                            if verifyThePositionOfTheGrade == arguments[2]:
                                rememberGradeName = grade.name
                                self.__gradeService.updateGradeFromDictionary(grade.id, arguments[3])
                                self.__undo.append(f"update.grade.{grade.id}.{rememberGradeName}")
                                self.__redo.append(f"update.grade.{grade.id}.{arguments[3]}")
                                return
                else:
                    raise ValueError("The student/discipline id does not exist!")
            else:
                raise ValueError(f"The service {objectChosen} does not exist!")
        except RepositoryError as error:
            print(str(error))
            traceback.print_exc()
        except DomainError as error:
            print(str(error))
            traceback.print_exc()

    def userInterfaceSearch(self):
        objectChosen = (input("Enter the object you want to work with: ")).strip()
        try:
            if objectChosen == "student":
                typeOfArgument = ((input("Choose between searching by id/name: ")).strip()).lower()
                if typeOfArgument == "id":
                    argument = (input("Enter id: ")).strip()
                    print()
                    listOfFoundObject = self.__studentService.searchByIDInListOfStudents(argument)
                    for student in listOfFoundObject:
                        self.displayStudentInformation(student.id, student.name)
                elif typeOfArgument == "name":
                    argument = ((input("Enter name: ")).strip()).lower()
                    print()
                    listOfFoundObject = self.__studentService.searchByNameInListOfStudents(argument)
                    for student in listOfFoundObject:
                        self.displayStudentInformation(student.id, student.name)
            elif objectChosen == "discipline":
                typeOfArgument = ((input("Choose between searching by id/name: ")).strip()).lower()
                if typeOfArgument == "id":
                    argument = (input("Enter id: ")).strip()
                    print()
                    listOfFoundObject = self.__disciplineService.searchByIDInListOfDisciplines(argument)
                    for discipline in listOfFoundObject:
                        self.displayDisciplineInformation(discipline.id, discipline.name)
                elif typeOfArgument == "name":
                    argument = ((input("Enter name: ")).strip()).lower()
                    print()
                    listOfFoundObject = self.__disciplineService.searchByNameInListOfDisciplines(argument)
                    for discipline in listOfFoundObject:
                        self.displayDisciplineInformation(discipline.id, discipline.name)
            else:
                raise ValueError(f"The service {objectChosen} does not exist!")
            print()
        except RepositoryError as error:
            print(str(error))
            traceback.print_exc()
        except DomainError as error:
            print(str(error))
            traceback.print_exc()

    def userInterfaceFailingStudents(self):
        listOfFailingStudents = self.__gradeService.getAllFailingStudents(self.__studentService,
                                                                          self.__disciplineService)
        print()
        for i in listOfFailingStudents:
            print(f"Student: {i[0]}\t\t"
                  f"Discipline: {i[1]}\t\t"
                  f"Average: {i[2]}")
        print()

    def userInterfaceTopStudents(self):
        listOfTopStudents = self.__gradeService.getTopStudentsAggregatedAverage(self.__studentService)
        print()
        for i in listOfTopStudents:
            floatToString = "%.3f" % i[1]
            print(f"Student: {i[0]}\t\t"
                  f"Aggregated average: {floatToString}")
        print()

    def userInterfaceTopDisciplines(self):
        listOfTopDisciplines = self.__gradeService.getTopDisciplines(self.__disciplineService)
        print()
        for i in listOfTopDisciplines:
            floatToString = "%.3f" % i[1]
            print(f"Discipline: {i[0]}\t\t"
                  f"Overall Average: {floatToString}")
        print()

    def userInterfaceList(self):
        objectChosen = (input("Enter the object you want to work with: ")).strip()
        try:
            if objectChosen == "student":
                print()
                listForTheChosenService = self.__studentService.sortStudents()
                for studentDetails in listForTheChosenService:
                    self.displayStudentInformation(studentDetails.id, studentDetails.name)
            elif objectChosen == "discipline":
                print()
                listForTheChosenService = self.__disciplineService.sortDiscipline()
                for disciplineDetails in listForTheChosenService:
                    self.displayDisciplineInformation(disciplineDetails.id, disciplineDetails.name)
            elif objectChosen == "grade":
                listForTheChosenService = self.__gradeService.sortAllGradeByStudentAndByDiscipline()
                disciplineID = 0
                studentID = 0
                for gradeDetails in listForTheChosenService:
                    if gradeDetails.disciplineID == disciplineID and gradeDetails.studentID == studentID:
                        print(",", gradeDetails.name, end="")
                    else:
                        print()
                        self.displayGradeInformation(
                            self.__studentService.getStudentFromDictionary(gradeDetails.studentID),
                            self.__disciplineService.getDisciplineFromDictionary(gradeDetails.disciplineID),
                            gradeDetails.name)
                    disciplineID = gradeDetails.disciplineID
                    studentID = gradeDetails.studentID
                print()
            else:
                raise ValueError(f"The service {objectChosen} does not exist!")
            print()
        except RepositoryError as error:
            print(str(error))
            traceback.print_exc()
        except DomainError as error:
            print(str(error))
            traceback.print_exc()

    def userInterfaceAddForUndo(self, objectToAdd, *restOfArguments):
        if objectToAdd == "student":
            self.__studentService.addStudentToDictionary(*restOfArguments[:2])
            listOfGradeToAdd = restOfArguments[2:]
            i = 0
            while i < len(listOfGradeToAdd):
                self.__gradeService.addGradeToDictionary(int(listOfGradeToAdd[i]), int(listOfGradeToAdd[i + 1]),
                                                         listOfGradeToAdd[i + 2])
                i += 3
        elif objectToAdd == "discipline":
            self.__disciplineService.addDisciplineToDictionary(*restOfArguments[:2])
            listOfGradeToAdd = restOfArguments[2:]
            i = 0
            while i < len(listOfGradeToAdd):
                self.__gradeService.addGradeToDictionary(int(listOfGradeToAdd[i]), int(listOfGradeToAdd[i + 1]),
                                                         listOfGradeToAdd[i + 2])
                i += 3
        elif objectToAdd == "grade":
            self.__gradeService.addGradeToDictionary(*restOfArguments)

    def userInterfaceDeleteForUndo(self, objectToDelete, objectID):
        if objectToDelete == "student":
            self.__studentService.deleteStudentFromDictionary(int(objectID))
        elif objectToDelete == "discipline":
            self.__disciplineService.deleteDisciplineFromDictionary(int(objectID))
        elif objectToDelete == "grade":
            self.__gradeService.deleteGradeFromDictionary(int(objectID))

    def userInterfaceUpdateForUndo(self, objectToUpdate, objectID, objectName):
        if objectToUpdate == "student":
            self.__studentService.updateStudentFromDictionary(int(objectID), objectName)
        elif objectToUpdate == "discipline":
            self.__disciplineService.updateDisciplineFromDictionary(int(objectID), objectName)
        elif objectToUpdate == "grade":
            self.__gradeService.updateGradeFromDictionary(int(objectID), objectName)

    def userInterfaceAddForRedo(self, objectToAdd, *arguments):
        if objectToAdd == "student":
            self.__studentService.addStudentToDictionary(arguments[0], arguments[1])
        elif objectToAdd == "discipline":
            self.__disciplineService.addDisciplineToDictionary(arguments[0], arguments[1])
        elif objectToAdd == "grade":
            self.__gradeService.addGradeToDictionary(*arguments)

    def userInterfaceDeleteForRedo(self, objectToDelete, *arguments):
        if objectToDelete == "student":
            self.__studentService.deleteStudentFromDictionary(int(arguments[0]))
            for grade in self.__gradeService.getAllGradesFromDictionary():
                if grade.studentID == arguments[0]:
                    self.__gradeService.deleteGradeFromDictionary(grade.id)
        elif objectToDelete == "discipline":
            self.__disciplineService.deleteDisciplineFromDictionary(int(arguments[0]))
            for grade in self.__gradeService.getAllGradesFromDictionary():
                if grade.disciplineID == arguments[0]:
                    self.__gradeService.deleteGradeFromDictionary(grade.id)
        elif objectToDelete == "grade":
            counterGrades = 0
            for grade in self.__gradeService.getAllGradesFromDictionary():
                if grade.studentID == arguments[0] and grade.disciplineID == arguments[1]:
                    counterGrades += 1
                    if counterGrades == int(arguments[2]):
                        print("yes")
                        self.__gradeService.deleteGradeFromDictionary(grade.id)
                        return

    def userInterfaceUpdateForRedo(self, objectToUpdate, objectID, objectName):
        if objectToUpdate == "student":
            self.__studentService.updateStudentFromDictionary(int(objectID), objectName)
        elif objectToUpdate == "discipline":
            self.__disciplineService.updateDisciplineFromDictionary(int(objectID), objectName)
        elif objectToUpdate == "grade":
            self.__gradeService.updateGradeFromDictionary(int(objectID), objectName)

    @staticmethod
    def displayStudentInformation(*studentDetails):
        print(f"ID: {studentDetails[0]}\tStudent: {studentDetails[1]}")

    @staticmethod
    def displayDisciplineInformation(*disciplineDetails):
        print(f"ID: {disciplineDetails[0]}\tDiscipline: {disciplineDetails[1]}")

    @staticmethod
    def displayGradeInformation(*gradeDetails):
        print(f"Student: {gradeDetails[0]}\t\t"
              f"Discipline: {gradeDetails[1]}\t\t"
              f"Grade: {gradeDetails[2]}", end="")

    def verifyDisciplineIDAndStudentIDForGradeClass(self, studentID, disciplineID):
        counter = False
        for findDisciplineID in self.__disciplineService.getAllDisciplinesFromDictionary():
            if findDisciplineID.id == int(disciplineID):
                counter = True
                break
        if counter is False:
            return False
        for findStudentID in self.__studentService.getAllStudentsFromDictionary():
            if findStudentID.id == int(studentID):
                return True
        return False
