"""
  Program functionalities module
"""
from random import seed
from random import randint


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
    return listOfAllContestantsGrades


def insertScoresAtPosition(listOfAllContestantsGrades, firstGrade, secondGrade, thirdGrade, insertPosition):
    listOfAllContestantsGrades.insert(insertPosition - 1, [firstGrade, secondGrade, thirdGrade])
    return listOfAllContestantsGrades


def removeScoresFromContestants(listOfAllContestantsGrades, *arguments):
    if len(arguments) == 1:
        return removeScoresFromAContestant(listOfAllContestantsGrades, *arguments)
    else:
        return removeParticipantsDependingOnOperatorAndAverageScore(listOfAllContestantsGrades, *arguments)


def removeScoresFromAContestant(listOfAllContestantsGrades, contestantPosition):
    listOfAllContestantsGrades[contestantPosition - 1] = [0, 0, 0]
    return listOfAllContestantsGrades


def removeParticipantsDependingOnOperatorAndAverageScore(listOfAllContestantsGrades, operator, averageScore):
    if 100 < averageScore or averageScore < 0:
        raise ValueError("The average score needs to be between [0,100]!")
    operatorFunction = None
    if operator == "<":
        operatorFunction = lambda grade, score: grade < score
    if operator == "=":
        operatorFunction = lambda grade, score: grade == score
    if operator == ">":
        operatorFunction = lambda grade, score: grade > score
    for grades in listOfAllContestantsGrades:
        if operatorFunction(int(float((grades[0] + grades[1] + grades[2]) / 3) * 10), int(averageScore)):
            listOfAllContestantsGrades[listOfAllContestantsGrades.index(grades)] = 0, 0, 0
    return listOfAllContestantsGrades


def removeScoresFromMultipleContestants(listOfAllContestantsGrades, contestantsStartPosition, contestantsEndPosition):
    for contestants in listOfAllContestantsGrades[contestantsStartPosition - 1: contestantsEndPosition:]:
        listOfAllContestantsGrades[listOfAllContestantsGrades.index(contestants)] = 0, 0, 0
    return listOfAllContestantsGrades


def replaceScoreOfParticipantAtProblemXWithOtherScore(listOfAllContestantsGrades, contestant, problem, newGrade):
    problem = int(problem[1]) - 1
    if problem == -1:
        raise ValueError("The problem 0 doesn't exist!")
    listOfAllContestantsGrades[contestant - 1][problem] = newGrade
    return listOfAllContestantsGrades


def participantsDependingOnOperatorAndAverageScore(listOfAllContestantsGrades, operator, averageScore):
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
            print(*grades, sep='\t')
            foundAtLeastOne = True
    if not foundAtLeastOne:
        raise Exception("There is no such contestant!")


def comparisonBetween2Lists(listOne, listTwo):
    numbersFromListOne = listOne[0] + listOne[1] + listOne[2]
    numbersFromListTwo = listTwo[0] + listTwo[1] + listTwo[2]
    if numbersFromListOne < numbersFromListTwo:
        return True
    return False


def participantsSortedInDecreasingOrderOfAverageScore(listOfAllContestantsGrades):
    madeASwamp = True
    while madeASwamp:
        madeASwamp = False
        for i in range(len(listOfAllContestantsGrades) - 1):
            if comparisonBetween2Lists(listOfAllContestantsGrades[i], listOfAllContestantsGrades[i + 1]):
                auxiliary = listOfAllContestantsGrades[i]
                listOfAllContestantsGrades[i] = listOfAllContestantsGrades[i + 1]
                listOfAllContestantsGrades[i + 1] = auxiliary
                madeASwamp = True
    return listOfAllContestantsGrades


def averageOfContestantsAverageScoresBetween2Positions(listOfAllContestantsGrades, contestantsStartPosition, contestantsEndPosition):
    if contestantsEndPosition > len(listOfAllContestantsGrades) or contestantsStartPosition > contestantsEndPosition:
        raise ValueError("The contestants do not exist!")
    sumOfAllContestantsGrades = 0
    for contestants in listOfAllContestantsGrades[contestantsStartPosition - 1: contestantsEndPosition:]:
        sumOfAllContestantsGrades += contestants[0] + contestants[1] + contestants[2]
    return round(float(sumOfAllContestantsGrades/(3 * (contestantsEndPosition - contestantsStartPosition + 1))), 3)


def averageScoreOfAContestant(listOfAContestantGrades):
    sumOfContestantsGrade = 0
    for grades in listOfAContestantGrades:
        sumOfContestantsGrade += grades
    return float(sumOfContestantsGrade / 3)


def lowestContestantsAverageScoresBetween2Positions(listOfAllContestantsGrades, contestantsStartPosition, contestantsEndPosition):
    if contestantsEndPosition > len(listOfAllContestantsGrades) or contestantsStartPosition > contestantsEndPosition:
        raise ValueError("The contestants do not exist!")
    lowestContestantsAverageScores = averageScoreOfAContestant(listOfAllContestantsGrades[contestantsStartPosition - 1])
    for contestantsGrades in listOfAllContestantsGrades[contestantsStartPosition: contestantsEndPosition:]:
        currentContestantAverageScore = averageScoreOfAContestant(contestantsGrades)
        if currentContestantAverageScore < lowestContestantsAverageScores:
            lowestContestantsAverageScores = currentContestantAverageScore
    return round(lowestContestantsAverageScores, 2)


def topParticipantsHavingTheHighestAverageScore(listOfAllContestantsGrades, lastPlaceToBeDisplayed):
    topListOfParticipantsAverageScore = []
    topListToPrint = []
    for contestant in listOfAllContestantsGrades:
        topListOfParticipantsAverageScore.append([averageScoreOfAContestant(contestant), listOfAllContestantsGrades.index(contestant)])
    topListOfParticipantsAverageScore.sort(reverse=True)
    placeSituatedInTop = 1
    counterForTopList = 0
    averageScoreIndex = 0
    listOfAllContestantsGradesIndex = 1
    topListToPrint.append([placeSituatedInTop, *listOfAllContestantsGrades[topListOfParticipantsAverageScore[counterForTopList][listOfAllContestantsGradesIndex]]])
    while counterForTopList < len(topListOfParticipantsAverageScore) - 1:
        if topListOfParticipantsAverageScore[counterForTopList][averageScoreIndex] == topListOfParticipantsAverageScore[counterForTopList + 1][averageScoreIndex]:
            topListToPrint.append([placeSituatedInTop, *listOfAllContestantsGrades[topListOfParticipantsAverageScore[counterForTopList + 1][listOfAllContestantsGradesIndex]]])
        else:
            placeSituatedInTop += 1
            if placeSituatedInTop <= lastPlaceToBeDisplayed:
                topListToPrint.append([placeSituatedInTop, *listOfAllContestantsGrades[topListOfParticipantsAverageScore[counterForTopList + 1][listOfAllContestantsGradesIndex]]])
            else:
                return topListToPrint
        counterForTopList += 1
    return topListToPrint


def topParticipantsWhoObtainedTheHighestScoreAtASpecificProblem(listOfAllContestantsGrades, lastPlaceToBeDisplayed, problem):
    problem = int(problem[1]) - 1
    if problem == -1:
        raise ValueError("The problem 0 doesn't exist!")
    topListOfParticipantsAtAProblem = []
    for contestant in listOfAllContestantsGrades:
        topListOfParticipantsAtAProblem.append([contestant[problem], listOfAllContestantsGrades.index(contestant)])
    topListOfParticipantsAtAProblem.sort(reverse=True)
    topListToPrint = []
    placeSituatedInTop = 1
    counterForTopList = 0
    problemScoreIndex = 0
    listOfAllContestantsGradesIndex = 1
    topListToPrint.append([placeSituatedInTop, *listOfAllContestantsGrades[topListOfParticipantsAtAProblem[counterForTopList][listOfAllContestantsGradesIndex]]])
    while counterForTopList < len(topListOfParticipantsAtAProblem) - 1:
        if topListOfParticipantsAtAProblem[counterForTopList][problemScoreIndex] == topListOfParticipantsAtAProblem[counterForTopList + 1][problemScoreIndex]:
            topListToPrint.append([placeSituatedInTop, *listOfAllContestantsGrades[topListOfParticipantsAtAProblem[counterForTopList + 1][listOfAllContestantsGradesIndex]]])
        else:
            placeSituatedInTop += 1
            if placeSituatedInTop <= lastPlaceToBeDisplayed:
                topListToPrint.append([placeSituatedInTop, *listOfAllContestantsGrades[topListOfParticipantsAtAProblem[counterForTopList + 1][listOfAllContestantsGradesIndex]]])
            else:
                return topListToPrint
        counterForTopList += 1
    return topListToPrint


def addToHistoryCommandList(historyForListOfCommands, command, *arguments):
    historyForListOfCommands.append([command, *arguments])
    return historyForListOfCommands


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
            if "<=>Pp".find(arguments[i][0]) < 0:
                arguments[i] = int(arguments[i])
                if (10 < arguments[i] or -1 > arguments[i]) and not (("replace.remove.top".count(command) != 0 and i == 0)
                                                                     or (command == "insert at" and i == 3)
                                                                     or ("avg to.min to.remove to".count(command) != 0)):
                    raise Exception("The arguments should be in this interval [0,10]!")
            i += 1
    return command, arguments


def testAllTestFunctions():
    testAddScoresOfANewContestant_listToTestAnd3Grades_listToTestAppendedWith3Grades()
    testInsertScoresAtPosition_listToTestAnd3GradesPlusPosition_listToTestWithTheGradesInserted()
    testRemoveScoresFromAContestant_listToTestAndPosition_listToTestWithThePositionsGradeSetTo0()
    testDisplayParticipantsSortedInDecreasingOrderOfAverageScore_listToTest_listToTestSorted()
    testAverageOfContestantsAverageScoresBetween2Positions_listToTestAnd2Positions_averageOfAllGradesInListToTestBetween2Positions()
    testLowestContestantsAverageScoresBetween2Positions_listToTestAnd2Positions_lowestAverageInListToTestBetween2Positions()
    testTopParticipantsHavingTheHighestAverageScore_listToTestAndLastPlaceToDisplay_topOfListToTest()
    testTopParticipantsWhoObtainedTheHighestScoreAtASpecificProblem_listToTestAndLastPlaceToDisplayPlusProblem_topOfListToTestAtASpecificProblem()


def testAddScoresOfANewContestant_listToTestAnd3Grades_listToTestAppendedWith3Grades():
    listToTest = []
    assert addScoresOfANewContestant(listToTest, 1, 2, 3) == [[1, 2, 3]]


def testInsertScoresAtPosition_listToTestAnd3GradesPlusPosition_listToTestWithTheGradesInserted():
    listToTest = [[1, 2, 3]]
    assert insertScoresAtPosition(listToTest, 0, 0, 0, 1) == [[0, 0, 0], [1, 2, 3]]


def testRemoveScoresFromAContestant_listToTestAndPosition_listToTestWithThePositionsGradeSetTo0():
    listToTest = [[1, 2, 3]]
    assert removeScoresFromAContestant(listToTest, 1) == [[0, 0, 0]]


def testDisplayParticipantsSortedInDecreasingOrderOfAverageScore_listToTest_listToTestSorted():
    listToTest = [[1, 1, 1], [3, 3, 3], [2, 2, 2], [0, 0, 0]]
    assert participantsSortedInDecreasingOrderOfAverageScore(listToTest) == [[3, 3, 3], [2, 2, 2], [1, 1, 1], [0, 0, 0]]


def testAverageOfContestantsAverageScoresBetween2Positions_listToTestAnd2Positions_averageOfAllGradesInListToTestBetween2Positions():
    listToTest = [[4, 4, 4], [2, 2, 2]]
    assert averageOfContestantsAverageScoresBetween2Positions(listToTest, 1, 2) == 3.0


def testLowestContestantsAverageScoresBetween2Positions_listToTestAnd2Positions_lowestAverageInListToTestBetween2Positions():
    listToTest = [[1, 1, 2], [1, 2, 2]]
    assert lowestContestantsAverageScoresBetween2Positions(listToTest, 1, 2) == 1.33


def testTopParticipantsHavingTheHighestAverageScore_listToTestAndLastPlaceToDisplay_topOfListToTest():
    listToTest = [[1, 1, 1], [3, 3, 3], [2, 2, 2], [0, 0, 0]]
    assert topParticipantsHavingTheHighestAverageScore(listToTest, 3) == [[1, 3, 3, 3], [2, 2, 2, 2], [3, 1, 1, 1]]


def testTopParticipantsWhoObtainedTheHighestScoreAtASpecificProblem_listToTestAndLastPlaceToDisplayPlusProblem_topOfListToTestAtASpecificProblem():
    listToTest = [[1, 1, 1], [3, 3, 3], [2, 2, 2], [0, 0, 0]]
    assert topParticipantsWhoObtainedTheHighestScoreAtASpecificProblem(listToTest, 3, 'P1') == [[1, 3, 3, 3], [2, 2, 2, 2], [3, 1, 1, 1]]
