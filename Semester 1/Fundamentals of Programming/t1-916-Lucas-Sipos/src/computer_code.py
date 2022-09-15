from random import seed
from random import randint


def verifyRandomNumberIfIsACheatNumber(generatedRandomNumberToBeVerified):
    int(generatedRandomNumberToBeVerified)
    digitsThatWereFound = [generatedRandomNumberToBeVerified % 10]
    generatedRandomNumberToBeVerified = int(generatedRandomNumberToBeVerified / 10)
    for i in range(3):
        if digitsThatWereFound.count(generatedRandomNumberToBeVerified % 10):
            return False
        else:
            digitsThatWereFound.append(generatedRandomNumberToBeVerified % 10)
            generatedRandomNumberToBeVerified = int(generatedRandomNumberToBeVerified / 10)
    return True


def randomNumberGenerator():
    seed(1)
    randomNumberGenerated = randint(1000, 9876)
    while verifyRandomNumberIfIsACheatNumber(randomNumberGenerated) is False:
        randomNumberGenerated = randint(1000, 9876)
    return int(randomNumberGenerated)


def givePlayerValueInformationAboutTheirChoice(numberToGiveInformationAbout, randomNumberChoseByComputer):
    randomNumberChoseByComputer = str(randomNumberChoseByComputer)
    runnerValue = 0
    codesValue = 0
    for i in range(4):
        digitToVerify = str(int(numberToGiveInformationAbout / pow(10, i)) % 10)
        if digitToVerify == randomNumberChoseByComputer[3 - i]:
            codesValue += 1
        elif digitToVerify in randomNumberChoseByComputer:
            runnerValue += 1
    return codesValue, runnerValue
