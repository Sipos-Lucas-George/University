from src.domain.complex_number import ComplexNumber


class Services:
    def __init__(self):
        self.__listOfComplexNumbers = list()
        self.__listOfComplexNumbers.append(ComplexNumber(6, 6))
        self.__listOfComplexNumbers.append(ComplexNumber(1, 7))
        self.__listOfComplexNumbers.append(ComplexNumber(8, 4))
        self.__listOfComplexNumbers.append(ComplexNumber(8, 9))
        self.__listOfComplexNumbers.append(ComplexNumber(4, 7))
        self.__listOfComplexNumbers.append(ComplexNumber(9, 5))
        self.__listOfComplexNumbers.append(ComplexNumber(2, 2))
        self.__listOfComplexNumbers.append(ComplexNumber(7, 6))
        self.__listOfComplexNumbers.append(ComplexNumber(9, 7))
        self.__listOfComplexNumbers.append(ComplexNumber(9, 6))

    def __getitem__(self, item):
        return self.__listOfComplexNumbers[item]

    def __len__(self):
        return self.__listOfComplexNumbers.__len__()

    def __delitem__(self, key):
        self.__delitem__(key)

    def addComplexNumberToList(self, realPartOfComplexNumber, imaginaryPartOfComplexNumber):
        self.__listOfComplexNumbers.append(ComplexNumber(realPartOfComplexNumber, imaginaryPartOfComplexNumber))

    def filterTheListOfComplexNumbers(self, startValue, endValue):
        if startValue > endValue:
            raise ValueError("The <start> value should be <= to <end> value")
        i = 0
        while i < self.__len__():
            if (startValue > self.__getitem__(i).realPartOfComplexNumber or self.__getitem__(i).realPartOfComplexNumber > endValue) or (startValue > self.__getitem__(i).imaginaryPartOfComplexNumber or self.__getitem__(i).imaginaryPartOfComplexNumber > endValue):
                del self.__listOfComplexNumbers[i]
                i -= 1
            i += 1

    def resetListOfComplexNumber(self):
        self.__listOfComplexNumbers.clear()
        self.__listOfComplexNumbers.append(ComplexNumber(6, 6))
        self.__listOfComplexNumbers.append(ComplexNumber(1, 7))
        self.__listOfComplexNumbers.append(ComplexNumber(8, 4))
        self.__listOfComplexNumbers.append(ComplexNumber(8, 9))
        self.__listOfComplexNumbers.append(ComplexNumber(4, 7))
        self.__listOfComplexNumbers.append(ComplexNumber(9, 5))
        self.__listOfComplexNumbers.append(ComplexNumber(2, 2))
        self.__listOfComplexNumbers.append(ComplexNumber(7, 6))
        self.__listOfComplexNumbers.append(ComplexNumber(9, 7))
        self.__listOfComplexNumbers.append(ComplexNumber(9, 6))

    @staticmethod
    def addToHistoryCommandList(historyForListOfCommands, command, *arguments):
        historyForListOfCommands.append([command, *arguments])
        return historyForListOfCommands

    @staticmethod
    def undoTheLastOperation(historyForListOfCommands, commands):
        if len(historyForListOfCommands) == 0:
            print("There is nothing to undo!")
        else:
            historyForListOfCommands.pop()
            for commandsToDo in historyForListOfCommands:
                commands[commandsToDo[0]](*commandsToDo[1:])


def testAllTestFunctionsOfServicesClass():
    testAddComplexNumberToListFunction_validInput_realPartOfNumberShouldBeAdded()
    testAddComplexNumberToListFunction_validInput_imaginaryPartOfNumberShouldBeAdded()
    testLengthOfComplexNumberListFunction_initializeAService_lengthOfTheInitializeService()
    testAddComplexNumberToListFunction_realPartRandomNumberAndImaginaryPartInvalidInput_errorMessageForImaginaryPart()


def testAddComplexNumberToListFunction_validInput_realPartOfNumberShouldBeAdded():
    listOfComplexNumbers = Services()
    listOfComplexNumbers.addComplexNumberToList(1, 2)
    assert listOfComplexNumbers[10].realPartOfComplexNumber == 1


def testAddComplexNumberToListFunction_validInput_imaginaryPartOfNumberShouldBeAdded():
    listOfComplexNumbers = Services()
    listOfComplexNumbers.addComplexNumberToList(1, 2)
    assert listOfComplexNumbers[10].imaginaryPartOfComplexNumber == 2


def testLengthOfComplexNumberListFunction_initializeAService_lengthOfTheInitializeService():
    assert len(Services()) == 10


def testAddComplexNumberToListFunction_realPartRandomNumberAndImaginaryPartInvalidInput_errorMessageForImaginaryPart():
    try:
        Services().addComplexNumberToList(1, 0)
        assert False
    except ValueError as valueError:
        assert str(valueError) == "Imaginary part should be different from 0!"


testAllTestFunctionsOfServicesClass()
