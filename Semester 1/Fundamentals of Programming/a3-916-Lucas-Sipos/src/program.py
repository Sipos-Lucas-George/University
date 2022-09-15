from random import seed
from random import randint

"""
  Write non-UI functions below
"""


def randomScoresGeneratorForTheFirst10Contestants():
    seed(1)
    listOfAllContestantsGrades = []
    counterForRandomNumberGenerator = 0
    while counterForRandomNumberGenerator < 10:
        gradeOfFirstProblem = randint(0, 10)
        gradeOfSecondProblem = randint(0, 10)
        gradeOfThirdProblem = randint(0, 10)
        listOfAllContestantsGrades.append([gradeOfFirstProblem, gradeOfSecondProblem, gradeOfThirdProblem])
        counterForRandomNumberGenerator += 1
    return listOfAllContestantsGrades


def addScoresOfANewContestant(listOfAllContestantsGrades, firstGrade, secondGrade, thirdGrade):
    listOfAllContestantsGrades.append([firstGrade, secondGrade, thirdGrade])
    return displayTheContestants(listOfAllContestantsGrades)


def insertScoresAtPosition(listOfAllContestantsGrades, firstGrade, secondGrade, thirdGrade, insertPosition):
    listOfAllContestantsGrades.insert(insertPosition - 1, [firstGrade, secondGrade, thirdGrade])
    return displayTheContestants(listOfAllContestantsGrades)


def removeScoresFromAContestant(listOfAllContestantsGrades, contestantPosition):
    listOfAllContestantsGrades[contestantPosition - 1] = [0, 0, 0]
    return displayTheContestants(listOfAllContestantsGrades)


def removeScoresFromMultipleContestants(listOfAllContestantsGrades, contestantsStartPosition, contestantsEndPosition):
    for contestants in listOfAllContestantsGrades[contestantsStartPosition - 1: contestantsEndPosition:]:
        contestants[0], contestants[1], contestants[2] = 0, 0, 0
    return displayTheContestants(listOfAllContestantsGrades)


def replaceScoreOfParticipantAtProblemXWithOtherScore(listOfAllContestantsGrades, contestant, problem, newGrade):
    listOfAllContestantsGrades[contestant - 1][int(problem[1]) - 1] = newGrade
    return displayTheContestants(listOfAllContestantsGrades)


def displayParticipantsDependingOnOperatorAndAverageScore(listOfAllContestantsGrades, operator, averageScore):
    operatorFunction = None
    foundAtLeastOne = False
    if operator == "<":
        operatorFunction = lambda grade, score: grade < score
    if operator == "=":
        operatorFunction = lambda grade, score: grade == score
    if operator == ">":
        operatorFunction = lambda grade, score: grade > score
    for grades in listOfAllContestantsGrades:
        if operatorFunction(grades[0] + grades[1] + grades[2], int(averageScore) * 3):
            print(*grades)
            foundAtLeastOne = True
    if not foundAtLeastOne:
        print("There is no such contestant!")


def comparisonBetween2Lists(listOne, listTwo):
    numbersFromListOne = listOne[0] + listOne[1] + listOne[2]
    numbersFromListTwo = listTwo[0] + listTwo[1] + listTwo[2]
    if numbersFromListOne < numbersFromListTwo:
        return True
    return False


def displayParticipantsSortedInDecreasingOrderOfAverageScore(listOfAllContestantsGrades):
    madeASwamp = True
    while madeASwamp:
        madeASwamp = False
        for i in range(len(listOfAllContestantsGrades) - 1):
            if comparisonBetween2Lists(listOfAllContestantsGrades[i], listOfAllContestantsGrades[i + 1]):
                auxiliary = listOfAllContestantsGrades[i]
                listOfAllContestantsGrades[i] = listOfAllContestantsGrades[i + 1]
                listOfAllContestantsGrades[i + 1] = auxiliary
                madeASwamp = True
    displayTheContestants(listOfAllContestantsGrades)


def separateCommandAndArguments(commandAndArguments):
    positionBetweenCommandAndArguments = commandAndArguments.find(" ")
    if positionBetweenCommandAndArguments == -1:
        return commandAndArguments, None
    command = commandAndArguments[:positionBetweenCommandAndArguments:]
    arguments = commandAndArguments[positionBetweenCommandAndArguments::].strip().split(" ")
    i = 0
    while i < len(arguments):
        if arguments[i] == "":
            arguments.remove(arguments[i])
        elif arguments[i].isalpha():
            command += " " + arguments[i]
            arguments.remove(arguments[i])
        else:
            if "<=>P".find(arguments[i][0]) < 0:
                arguments[i] = int(arguments[i])
                if (10 < arguments[i] or -1 > arguments[i]) and not (("replace.remove".count(command) != 0 and i == 0)
                                                                     or (command == "insert at" and i == 3)):
                    raise Exception("The arguments should be in this interval [0,10]!")
            i += 1
    return command, arguments


"""
  Write the command-driven UI below
"""


def displayTheContestants(listOfAllContestantsGrades):
    i = 1
    for gradesOfAContestant in listOfAllContestantsGrades:
        print(f"{i})\t\t P1: {gradesOfAContestant[0]}\t P2: {gradesOfAContestant[1]}\t P3: {gradesOfAContestant[2]}")
        i += 1


def displayOptionsMenu():
    print("\n\tEnter 'add <P1 score> <P2 score> <P3 score>' to add new participant with P1, P2 and P3 scores")
    print("\tEnter 'insert <P1 score> <P2 score> <P3 score> at <position>' to insert scores at the given position")
    print("\tEnter 'remove <position>' to set the contestant's scores to 0")
    print("\tEnter 'remove <start position> to <end position>' to set all contestants scores, in that interval, to 0")
    print("\tEnter 'replace <participant> <P1 | P2 | P3> with <new score>' to replace contestant's problem score with a new score")
    print("\tEnter 'list' to display participants and all their scores")
    print("\tEnter 'list sorted' to display participants sorted in decreasing order of average score")
    print("\tEnter 'list [ < | = | > ] <score>' to display participants with an average score '<'/'='/'>' to a given score\n")


def runMenuCommand():
    listOfAllContestantsGrades = randomScoresGeneratorForTheFirst10Contestants()
    commands = {
        "add": addScoresOfANewContestant,
        "insert at": insertScoresAtPosition,
        "remove": removeScoresFromAContestant,
        "remove to": removeScoresFromMultipleContestants,
        "replace with": replaceScoreOfParticipantAtProblemXWithOtherScore,
        "list": displayParticipantsDependingOnOperatorAndAverageScore,
        "list sorted": displayParticipantsSortedInDecreasingOrderOfAverageScore
    }
    while True:
        displayOptionsMenu()
        commandAndArguments = (input("Enter your command and arguments: ")).strip()
        if commandAndArguments == "exit":
            return
        if commandAndArguments == "list":
            displayTheContestants(listOfAllContestantsGrades)
        else:
            try:
                command, arguments = separateCommandAndArguments(commandAndArguments)
                try:
                    commands[command](listOfAllContestantsGrades, *arguments)
                except KeyError:
                    print(f"Option '{command}' is not yet implemented")
                except TypeError:
                    print(f"The menu command '{command}' takes less/more/other attributes")
            except BaseException as error:
                print(error)


def main():
    try:
        runMenuCommand()
    except Exception as ex:
        print("Unknown exception caught: ", ex)


main()
