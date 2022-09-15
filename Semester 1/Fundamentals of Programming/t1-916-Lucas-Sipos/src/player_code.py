def verifyPlayerNumberIfIsACheatNumber(generatedRandomNumberToBeVerified):
    if 9999 - generatedRandomNumberToBeVerified < 1000 or 9999 - generatedRandomNumberToBeVerified > 8999:
        return False
    digitsThatWereFound = [generatedRandomNumberToBeVerified % 10]
    generatedRandomNumberToBeVerified = int(generatedRandomNumberToBeVerified / 10)
    for i in range(3):
        if digitsThatWereFound.count(generatedRandomNumberToBeVerified % 10):
            return False
        else:
            digitsThatWereFound.append(generatedRandomNumberToBeVerified % 10)
            generatedRandomNumberToBeVerified = int(generatedRandomNumberToBeVerified / 10)
    return True
