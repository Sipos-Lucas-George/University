class UserInterface:
    def __init__(self, listOfComplexNumbers):
        self.__listOfComplexNumbersServices = listOfComplexNumbers

    def __getitem__(self, item):
        return self.__listOfComplexNumbersServices[item]

    @staticmethod
    def displayMenu():
        print("\nEnter 'list' to display the list of numbers")
        print("Enter 'add <real part> <imaginary part>' to add a new complex number to the list of complex numbers")
        print("Enter 'filter <start> <end>' to filter the list so that it contains only the numbers between values start and end")
        print("Enter 'undo' to undo the last operation that modified the program data")
        print("Enter 'menu' to display the menu")
        print("Enter 'exit' to exit the program\n")

    def displayListOfNumbers(self):
        print()
        for i in range(self.__listOfComplexNumbersServices.__len__()):
            print(f"{self.__listOfComplexNumbersServices.__getitem__(i).realPartOfComplexNumber} + {self.__listOfComplexNumbersServices.__getitem__(i).imaginaryPartOfComplexNumber}i")
        print()
