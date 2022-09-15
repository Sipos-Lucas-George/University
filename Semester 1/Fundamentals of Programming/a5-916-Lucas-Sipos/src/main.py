from src.services.complex_number_services import Services
from src.ui.user_interface import UserInterface
import traceback


def main():
    listOfComplexNumberService = Services()
    userInterfaceObject = UserInterface(listOfComplexNumberService)
    historyForListOfCommands = []
    commands = {
        "add": listOfComplexNumberService.addComplexNumberToList,
        "filter": listOfComplexNumberService.filterTheListOfComplexNumbers
    }
    userInterfaceObject.displayMenu()
    while True:
        chosenCommand = (input("Enter your command: ")).strip()
        if chosenCommand == "exit":
            return
        elif chosenCommand == "list":
            userInterfaceObject.displayListOfNumbers()
        elif chosenCommand == "menu":
            userInterfaceObject.displayMenu()
        elif chosenCommand == "undo":
            listOfComplexNumberService.resetListOfComplexNumber()
            listOfComplexNumberService.undoTheLastOperation(historyForListOfCommands, commands)
            userInterfaceObject.displayListOfNumbers()
        else:
            try:
                arguments = []
                if chosenCommand == "add":
                    arguments.append(int((input("Enter the real part of the number: ")).strip()))
                    arguments.append(int((input("Enter the imaginary part of the number: ")).strip()))
                    commands[chosenCommand](*arguments)
                elif chosenCommand == "filter":
                    arguments.append(int((input("Enter the start value: ")).strip()))
                    arguments.append(int((input("Enter the end value: ")).strip()))
                    commands[chosenCommand](*arguments)
                else:
                    raise f"The menu command '{chosenCommand}' takes less/more/other attributes"
                listOfComplexNumberService.addToHistoryCommandList(historyForListOfCommands, chosenCommand, *arguments)
            except KeyError:
                print(f"Option '{chosenCommand}' is not yet implemented")
            except TypeError:
                print(f"The menu command '{chosenCommand}' takes less/more/other attributes")
            except Exception as exception:
                print(exception)
                traceback.print_exc()


main()
