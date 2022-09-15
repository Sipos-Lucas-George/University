"""
  User interface module
"""
from src.functions import *
import traceback


def displayTheContestants(listOfAllContestantsGrades):
    i = 1
    for gradesOfAContestant in listOfAllContestantsGrades:
        print(f"{i})\t\t P1: {gradesOfAContestant[0]}\t P2: {gradesOfAContestant[1]}\t P3: {gradesOfAContestant[2]}")
        i += 1


def displayTheAverageContestantsScoresBetween2Positions(contestantsStartPosition, contestantsEndPosition, averageContestantsScoreBetween2Positions):
    print(f"The average of the average scores for participants between positions {contestantsStartPosition} "
          f"and {contestantsEndPosition} is {averageContestantsScoreBetween2Positions}")


def displayTheLowestContestantsAverageScoresBetween2Positions(contestantsStartPosition, contestantsEndPosition, lowestContestantsAverageScores):
    print(f"The lowest average score of the participants between positions {contestantsStartPosition} "
          f"and {contestantsEndPosition} is {lowestContestantsAverageScores}")


def displayTheTopListOfParticipants(topListOfParticipants):
    placeOfParticipant = 0
    for grades in topListOfParticipants:
        print(f"{grades[placeOfParticipant]}.\t", grades[1], grades[2], grades[3])


def displayOptionsMenu():
    print("\n\tEnter 'add <P1 score> <P2 score> <P3 score>' to add new participant with P1, P2 and P3 scores")
    print("\tEnter 'insert <P1 score> <P2 score> <P3 score> at <position>' to insert scores at the given position")
    print("\tEnter 'remove <position>' to set the contestant's scores to 0")
    print("\tEnter 'remove <start position> to <end position>' to set all contestants scores, in that interval, to 0")
    print("\tEnter 'replace <participant> <P1 | P2 | P3> with <new score>' to replace contestant's problem score with a new score")
    print("\tEnter 'list' to display participants and all their scores")
    print("\tEnter 'list sorted' to display participants sorted in decreasing order of average score")
    print("\tEnter 'list [ < | = | > ] <score>' to display participants with an average score '< | = | >' to a given score")
    print("\tEnter 'avg <start position> to <end position>' to display the average of the average scores for participants between the given positions")
    print("\tEnter 'min <start position> to <end position>' to display the lowest average score of the participants between the given positions")
    print("\tEnter 'top <number>' to display the top participants having the highest average score, in descending order of average score")
    print("\tEnter 'top <number> <P1 | P2 | P3>' to display the top participants who obtained the highest score for 'P1 | P2 | P3', sorted descending by that score")
    print("\tEnter 'remove [ < | = | > ] <score>' to set the scores of participants having an average score '< | = | >' <score> to 0")
    print("\tEnter 'undo' to reverse the last operation that modified the list of participants\n")


def runMenuCommand():
    listOfAllContestantsGrades = randomScoresGeneratorForTheFirst10Contestants()
    listOfAllContestantsGradesDuplicate = listOfAllContestantsGrades.copy()
    historyForListOfCommands = []
    testAllTestFunctions()
    commands = {
        "add": addScoresOfANewContestant,
        "insert at": insertScoresAtPosition,
        "remove": removeScoresFromContestants,
        "remove to": removeScoresFromMultipleContestants,
        "replace with": replaceScoreOfParticipantAtProblemXWithOtherScore,
        "list": participantsDependingOnOperatorAndAverageScore,
        "list sorted": participantsSortedInDecreasingOrderOfAverageScore,
        "avg to": averageOfContestantsAverageScoresBetween2Positions,
        "min to": lowestContestantsAverageScoresBetween2Positions,
        "top": topParticipantsWithHighAverageOrHighProblemScore,
        "undo": undoTheLastOperationUI
    }
    topParticipantsHavingTheHighestAverageScore(listOfAllContestantsGrades, 20)
    while True:
        displayOptionsMenu()
        commandAndArguments = (input("Enter your command and arguments: ")).strip()
        if commandAndArguments == "exit":
            return
        if commandAndArguments == "list":
            displayTheContestants(listOfAllContestantsGrades)
        elif commandAndArguments == "undo":
            listOfAllContestantsGrades = listOfAllContestantsGradesDuplicate.copy()
            undoTheLastOperationUI(listOfAllContestantsGrades, historyForListOfCommands, commands)
        else:
            try:
                command, arguments = separateCommandAndArguments(commandAndArguments)
                try:
                    commands[command](listOfAllContestantsGrades, *arguments)
                    if command != "top":
                        addToHistoryCommandList(historyForListOfCommands, command, *arguments)
                    if command == "avg to":
                        displayTheAverageContestantsScoresBetween2Positions(*arguments, listOfAllContestantsGrades)
                    elif command == "min to":
                        displayTheLowestContestantsAverageScoresBetween2Positions(*arguments, listOfAllContestantsGrades)
                    elif command != "top" or command != "list":
                        displayTheContestants(listOfAllContestantsGrades)
                except KeyError:
                    print(f"Option '{command}' is not yet implemented")
                except TypeError:
                    print(f"The menu command '{command}' takes less/more/other attributes")
                    traceback.print_exc()
            except BaseException as error:
                print(error)
                traceback.print_exc()


def undoTheLastOperationUI(listOfAllContestantsGrades, historyForListOfCommands, commands):
    if len(historyForListOfCommands) == 0:
        print("There is nothing to undo!")
    else:
        historyForListOfCommands.pop()
        for commandsToDo in historyForListOfCommands:
            commands[commandsToDo[0]](listOfAllContestantsGrades, *commandsToDo[1:])
        return displayTheContestants(listOfAllContestantsGrades)


def topParticipantsWithHighAverageOrHighProblemScore(listOfAllContestantsGrades, *arguments):
    if len(arguments) == 1:
        displayTheTopListOfParticipants(topParticipantsHavingTheHighestAverageScore(listOfAllContestantsGrades, *arguments))
    else:
        displayTheTopListOfParticipants(topParticipantsWhoObtainedTheHighestScoreAtASpecificProblem(listOfAllContestantsGrades, *arguments))
