# Solve the problem from the third set here


def initializeNaturalNumber():
    naturalNumber = int(input("Enter your number: "))
    return naturalNumber


def sumOfDivisors(x):
    theSumOfDivisors = 1
    for i in range(2, x // 2 + 1):
        if x % i == 0:
            theSumOfDivisors += i
    return theSumOfDivisors


def showOnScreen(naturalNumber):
    if naturalNumber > 5:
        print("The largest perfect number smaller than a given natural number is: ", naturalNumber)
    else:
        print("There is no such number!!!(that's perfect and smaller than the given natural number)")


def main():
    naturalNumber = initializeNaturalNumber()
    naturalNumber -= 1
    while naturalNumber != sumOfDivisors(naturalNumber) and naturalNumber > 5:
        naturalNumber -= 1
    showOnScreen(naturalNumber)


main()
