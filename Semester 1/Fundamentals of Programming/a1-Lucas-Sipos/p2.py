# Solve the problem from the second set here
import math


def initializeNaturalNumber():
    naturalNumber = int(input("Enter your number: "))
    return naturalNumber


def ifNaturalNumberIsPrime(naturalNumber):
    for i in range(3, int(math.sqrt(naturalNumber)) + 1, 2):
        if naturalNumber % i == 0:
            return 0
    return 1


def findTheTwinPrimeNaturalNumbersLargerThanANaturalNumber(naturalNumber):
    firstNaturalNumber = -1
    secondNaturalNumber = 0
    if naturalNumber < 3:
        firstNaturalNumber = 3
        secondNaturalNumber = 5
    elif naturalNumber % 2 == 0:
        naturalNumber += 1
    else:
        naturalNumber += 2

    while secondNaturalNumber - firstNaturalNumber != 2 and firstNaturalNumber - secondNaturalNumber != 2:
        if ifNaturalNumberIsPrime(naturalNumber) == 1:
            if secondNaturalNumber - firstNaturalNumber > 0:
                firstNaturalNumber = naturalNumber
            else:
                secondNaturalNumber = naturalNumber
        naturalNumber += 2

    if firstNaturalNumber - secondNaturalNumber == 2:
        return secondNaturalNumber, firstNaturalNumber
    else:
        return firstNaturalNumber, secondNaturalNumber


def showOnScreen(firstNaturalNumber, secondNaturalNumber):
    print("The twin prime numbers are p1 =", firstNaturalNumber, "and p2 =", secondNaturalNumber)


def main():
    naturalNumber = initializeNaturalNumber()
    firstNaturalNumber, secondNaturalNumber = findTheTwinPrimeNaturalNumbersLargerThanANaturalNumber(naturalNumber)
    showOnScreen(firstNaturalNumber, secondNaturalNumber)


main()
