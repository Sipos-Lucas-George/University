"""
Implement the solution here. 
You may add other source files.
Make sure you commit & push the source code before the end of the test.

Solutions using user-defined classes will not be graded.
"""
from src.computer_code import *
from src.player_code import *
from src.user_interface import *
import time


def main():
    randomNumberChoseByComputer = randomNumberGenerator()
    startOfTheGame()
    timeValue = time.time()
    while True:
        numberChoseByPlayer = int(input("Guess the computer's number and make your choice fast: "))
        if time.time() - timeValue > 60:
            playerLostTheGame()
            return
        if verifyPlayerNumberIfIsACheatNumber(numberChoseByPlayer) is False:
            playerLostTheGame()
            return
        else:
            if randomNumberChoseByComputer == numberChoseByPlayer:
                playerWinTheGame()
                return
            givePlayerInformationAboutTheirChoice(numberChoseByPlayer, *givePlayerValueInformationAboutTheirChoice(numberChoseByPlayer, randomNumberChoseByComputer))


main()
