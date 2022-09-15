from controller.studentController import StudentController
from controller.gradeController import GradeController
import traceback


class UI:
    def __init__(self, studentController: StudentController, gradeController: GradeController):
        self.__studentController = studentController
        self.__gradeController = gradeController
        self.__undo = list()
        self.__redo = list()
        self.__counter = 1
        self.__commandDictionary = {
            "store": self.uiStore,
            "remove": self.uiRemove,
            "assign": self.uiAssignLaboratory,
            "top": self.uiTop,
        }

    @staticmethod
    def menu():
        print("store - to store")
        print("remove - to remove")
        print("assign - to assign")
        print("top - for top")

    def run(self):
        self.menu()
        while True:
            inputCommand = (input("Enter your option: ")).strip()
            try:
                if inputCommand == "menu":
                    self.menu()
                elif inputCommand == "exit":
                    return
                else:
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

    def uiStore(self):
        objectChosen = input("Choose what to store: ")
        arguments = []
        try:
            if objectChosen == "student":
                arguments.append(int((input("Enter id of student: ")).strip()))
                arguments.append((input("Enter student's name: ")).strip())
                arguments.append(int((input("Enter student's group: ")).strip()))
                self.__studentController.create(*arguments)
                self.__undo.append(f"remove.student.{arguments[0]}")
                self.__redo.append(f"store.student.{arguments[0]}.{arguments[1]}.{arguments[2]}")
            elif objectChosen == "grade":
                arguments.append(int((input("Enter id of student: ")).strip()))
                arguments.append(int((input("Enter laboratory number: ")).strip()))
                arguments.append(int((input("Enter laboratory problem: ")).strip()))
                arguments.append(int((input("Enter student's grade: ")).strip()))
                self.__gradeController.create(*arguments)
            else:
                raise ValueError(f"The service {objectChosen} does not exist!")
        except ValueError as error:
            print(error)
            traceback.print_exc()

    def uiTop(self):
        try:
            argument = int((input("Group: ")).strip())
            listToPrint = self.__gradeController.top(argument, self.__studentController.getAllByGroup(argument))
            print(listToPrint)
        except ValueError as error:
            print(error)
            traceback.print_exc()

    def uiRemove(self):
        try:
            argument = int((input("Enter id of student: ")).strip())
            didItRemove = self.__studentController.remove(argument)
            if didItRemove is True:
                self.__undo.append(f"store.student.{argument}")
                self.__redo.append(f"remove.student.{argument}")
        except ValueError as error:
            print(error)
            traceback.print_exc()

    def uiAssignLaboratory(self):
        chosenInput = input("Student or group: ")
        arguments = []
        try:
            if chosenInput == "student":
                arguments.append(int((input("Enter id of student: ")).strip()))
                arguments.append((input("Enter laboratory number: ")).strip())
                arguments.append(int((input("Enter laboratory problem: ")).strip()))
                self.__studentController.assignLaboratory(*arguments)
            elif chosenInput == "group":
                arguments.append(int((input("Enter id of group: ")).strip()))
                arguments.append(int((input("Enter laboratory number: ")).strip()))
                self.__studentController.assignLaboratoryGroup(*arguments)
            else:
                raise ValueError(f"The service {chosenInput} does not exist!")
        except ValueError as error:
            print(error)
            traceback.print_exc()
