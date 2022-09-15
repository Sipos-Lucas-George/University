"""
  Start the program by running this module
"""
from src.ui import runMenuCommand
import traceback


def main():
    try:
        runMenuCommand()
    except Exception as ex:
        print("Unknown exception caught: ", ex)
        traceback.print_exc()


main()
