# Solve the problem from the first set here


def initializeStringNumber():
    stringNumber = input("Enter your number: ")
    if stringNumber.isnumeric():
        return stringNumber
    return "Wrong input"


def theLargestNumberFormedFromTheStringsDigits(stringNumber):
    stringNumber = sorted(stringNumber)
    stringNumber = "".join(stringNumber)
    return stringNumber[::-1]


def showOnScreen(stringNumber):
    print("The largest natural number written with the same digits is: ", stringNumber)


def main():
    stringNumber = initializeStringNumber()
    if stringNumber == "Wrong input":
        print(stringNumber)
        return
    showOnScreen(theLargestNumberFormedFromTheStringsDigits(stringNumber))


main()
