#
# Write the implementation for A2 in this file
#

# UI section
# (write all functions that have input or print statements here). 
# Ideally, this section should not contain any calculations relevant to program functionalities


from random import seed
from random import randint


def displayTheListOfComplexNumbers(listOfComplexNumbers):
    print("\nThe list of your complex numbers is:")
    print(*listOfComplexNumbers)


def displayMenuOptions():
    print("\n\tEnter '+' to add another complex number to the list")
    print("\tEnter '1' to display the longest sequence of numbers with a strictly increasing real part")
    print("\tEnter '2' to display the longest sequence that contains at most 3 distinct values")
    print("\tEnter 'display' to display your complex numbers list")
    print("\tEnter 'x' to end the program\n")


def readComplexNumber(listOfComplexNumbers):
    realPartNumber = int(input("Enter the real part of your number: "))
    imaginaryPartNumber = int(input("Enter the imaginary part of your number: "))
    return addAComplexNumber(listOfComplexNumbers, realPartNumber, imaginaryPartNumber)


def displayListAfterAddingAComplexNumber(listOfComplexNumbers):
    print("\nThe new list after adding the complex number is:")
    print(*listOfComplexNumbers)


def displayTheLongestSequenceWithAStrictlyIncreasingRealPart(listOfComplexNumbers, startOfTheLongestSequence, endOfTheLongestSequence):
    print("\nThe longest sequence with a strictly increasing real part is:")
    print(*listOfComplexNumbers[startOfTheLongestSequence:endOfTheLongestSequence + 1:])


def displayTheLongestSequenceThatContainsAtMost3DistinctValues(listOfComplexNumbers, startOfTheLongestSequence, endOfTheLongestSequence):
    print("\nThe longest sequence that contains at most 3 distinct values is:")
    print(*listOfComplexNumbers[startOfTheLongestSequence:endOfTheLongestSequence + 1:])


# print('Hello A2')


# Function section
# (write all non-UI functions in this section)
# There should be no print or input statements below this comment
# Each function should do one thing only
# Functions communicate using input parameters and their return values


def first10ComplexNumbersAvailableAtProgramStartup():
    listOfComplexNumbers = randomNumberGeneratorForTheFirst10ComplexNumbers()
    return listOfComplexNumbers


def getTheRealPartOfTheComplexNumber(complexNumber):
    return complexNumber[0]


def getTheImaginaryPartOfTheComplexNumber(complexNumber):
    return complexNumber[1]


def addAComplexNumber(listOfComplexNumbers, realPartNumber, imaginaryPartNumber):
    listOfComplexNumbers.append([realPartNumber, imaginaryPartNumber])
    return displayListAfterAddingAComplexNumber(listOfComplexNumbers)


def longestSequenceWithAStrictlyIncreasingRealPart(listOfComplexNumbers):
    counterForComplexNumberList = 1
    startOfTheCurrentSequence = 0
    endOfTheCurrentSequence = 0
    endOfTheLongestSequence = 0
    startOfTheLongestSequence = 0
    lengthOfTheLongestSequence = 0
    while counterForComplexNumberList < len(listOfComplexNumbers):
        if listOfComplexNumbers[counterForComplexNumberList][0] > listOfComplexNumbers[counterForComplexNumberList - 1][0]:
            endOfTheCurrentSequence = counterForComplexNumberList
        elif listOfComplexNumbers[counterForComplexNumberList][0] <= listOfComplexNumbers[counterForComplexNumberList - 1][0]:
            startOfTheCurrentSequence = counterForComplexNumberList
            endOfTheCurrentSequence = counterForComplexNumberList
        if lengthOfTheLongestSequence < endOfTheCurrentSequence - startOfTheCurrentSequence:
            lengthOfTheLongestSequence = endOfTheCurrentSequence - startOfTheCurrentSequence
            endOfTheLongestSequence = endOfTheCurrentSequence
            startOfTheLongestSequence = startOfTheCurrentSequence
        counterForComplexNumberList += 1
    displayTheLongestSequenceWithAStrictlyIncreasingRealPart(listOfComplexNumbers, startOfTheLongestSequence, endOfTheLongestSequence)


def theLongestSequenceThatContainsAtMost3DistinctValues(listOfComplexNumbers):
    endOfTheLongestSequence = 0
    startOfTheLongestSequence = 0
    lengthOfTheLongestSequence = 0
    i = 0
    while i < len(listOfComplexNumbers) - 3:
        startOfTheCurrentSequence = i
        endOfTheCurrentSequence = i
        counterForDistinctValues = 1
        j = i + 1
        if len(listOfComplexNumbers) - (i + 1) < lengthOfTheLongestSequence:
            i = len(listOfComplexNumbers)
        while j < len(listOfComplexNumbers):
            if listOfComplexNumbers[startOfTheCurrentSequence:j:].count(listOfComplexNumbers[j]) == 0:
                if counterForDistinctValues == 3:
                    j = len(listOfComplexNumbers)
                else:
                    counterForDistinctValues += 1
                    endOfTheCurrentSequence = j
            else:
                endOfTheCurrentSequence = j
            if lengthOfTheLongestSequence < endOfTheCurrentSequence - startOfTheCurrentSequence:
                lengthOfTheLongestSequence = endOfTheCurrentSequence - startOfTheCurrentSequence
                startOfTheLongestSequence = startOfTheCurrentSequence
                endOfTheLongestSequence = endOfTheCurrentSequence
            j += 1
        i += 1
    displayTheLongestSequenceThatContainsAtMost3DistinctValues(listOfComplexNumbers, startOfTheLongestSequence, endOfTheLongestSequence)


def randomNumberGeneratorForTheFirst10ComplexNumbers():
    seed(1)
    listOfComplexNumbers = []
    counterForRandomNumberGenerator = 0
    while counterForRandomNumberGenerator < 10:
        realPartOfComplexNumber = randint(0, 100)
        imaginaryPartOfComplexNumber = randint(1, 100)
        listOfComplexNumbers.append([realPartOfComplexNumber, imaginaryPartOfComplexNumber])
        counterForRandomNumberGenerator += 1
    return listOfComplexNumbers


# print('Hello A2'!) -> prints aren't allowed here!


def main():
    listOfComplexNumbers = first10ComplexNumbersAvailableAtProgramStartup()
    displayTheListOfComplexNumbers(listOfComplexNumbers)
    while True:
        displayMenuOptions()
        userInputOption = input("Please select your option: ")
        if userInputOption == "+":
            readComplexNumber(listOfComplexNumbers)
        elif userInputOption == "1":
            longestSequenceWithAStrictlyIncreasingRealPart(listOfComplexNumbers)
        elif userInputOption == "2":
            theLongestSequenceThatContainsAtMost3DistinctValues(listOfComplexNumbers)
        elif userInputOption == "display":
            displayTheListOfComplexNumbers(listOfComplexNumbers)
        elif userInputOption == "x":
            return
        else:
            print("\nWrong input!!!")


main()
