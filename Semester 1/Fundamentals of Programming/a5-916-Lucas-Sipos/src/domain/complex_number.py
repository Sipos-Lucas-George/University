class ComplexNumber:
    def __init__(self, realPartOfComplexNumberConstructor=0, imaginaryPartOfComplexNumberConstructor=1):
        if imaginaryPartOfComplexNumberConstructor == 0:
            raise ValueError("Imaginary part should be different from 0!")
        self.__realPartOfComplexNumber = realPartOfComplexNumberConstructor
        self.__imaginaryPartOfComplexNumber = imaginaryPartOfComplexNumberConstructor

    @property
    def realPartOfComplexNumber(self):
        return self.__realPartOfComplexNumber

    @realPartOfComplexNumber.setter
    def realPartOfComplexNumber(self, newRealPartOfComplexNumber):
        self.__realPartOfComplexNumber = newRealPartOfComplexNumber

    @property
    def imaginaryPartOfComplexNumber(self):
        return self.__imaginaryPartOfComplexNumber

    @imaginaryPartOfComplexNumber.setter
    def imaginaryPartOfComplexNumber(self, newImaginaryPartOfComplexNumber):
        if newImaginaryPartOfComplexNumber == 0:
            raise ValueError("Imaginary part should be different from 0!")
        self.__imaginaryPartOfComplexNumber = newImaginaryPartOfComplexNumber


def testAllTestFunctions():
    testConstructorOfComplexNumberClass_initializeTheClassWithNoParameters_realPartShouldBe0()
    testConstructorOfComplexNumberClass_initializeTheClassWithNoParameters_imaginaryPartShouldBe1()
    testClassComplexNumber_realPartRandomNumberAndImaginaryPartIs0_errorMessageForImaginaryPart()
    testClassComplexNumber_validInput_noErrorForRealPartOfNumber()
    testClassComplexNumber_validInput_noErrorForImaginaryPartOfNumber()
    testSetterFunctionOfComplexNumberClass_randomValidNumbers_setterShouldWorkForAddingToRealPartOfTheNumber()
    testSetterFunctionOfComplexNumberClass_randomValidNumbers_setterShouldWorkForAddingToImaginaryPartOfTheNumber()
    testSetterFunctionOfComplexNumberClass_invalidSetNumberForImaginaryPart_errorMessageForImaginaryPart()


def testConstructorOfComplexNumberClass_initializeTheClassWithNoParameters_realPartShouldBe0():
    assert ComplexNumber().realPartOfComplexNumber == 0


def testConstructorOfComplexNumberClass_initializeTheClassWithNoParameters_imaginaryPartShouldBe1():
    assert ComplexNumber().imaginaryPartOfComplexNumber == 1


def testClassComplexNumber_realPartRandomNumberAndImaginaryPartIs0_errorMessageForImaginaryPart():
    try:
        ComplexNumber(5, 0)
        assert False
    except ValueError as valueError:
        assert str(valueError) == "Imaginary part should be different from 0!"


def testClassComplexNumber_validInput_noErrorForRealPartOfNumber():
    assert ComplexNumber(5, 6).realPartOfComplexNumber == 5


def testClassComplexNumber_validInput_noErrorForImaginaryPartOfNumber():
    assert ComplexNumber(5, 6).imaginaryPartOfComplexNumber == 6


def testSetterFunctionOfComplexNumberClass_randomValidNumbers_setterShouldWorkForAddingToRealPartOfTheNumber():
    complexNumber = ComplexNumber(5, 6)
    complexNumber.realPartOfComplexNumber += 1
    assert complexNumber.realPartOfComplexNumber == 6


def testSetterFunctionOfComplexNumberClass_randomValidNumbers_setterShouldWorkForAddingToImaginaryPartOfTheNumber():
    complexNumber = ComplexNumber(5, 6)
    complexNumber.imaginaryPartOfComplexNumber += 1
    assert complexNumber.imaginaryPartOfComplexNumber == 7


def testSetterFunctionOfComplexNumberClass_invalidSetNumberForImaginaryPart_errorMessageForImaginaryPart():
    try:
        ComplexNumber(5, 6).imaginaryPartOfComplexNumber = 0
        assert False
    except ValueError as valueError:
        assert str(valueError) == "Imaginary part should be different from 0!"


testAllTestFunctions()
