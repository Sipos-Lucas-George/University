from src.domain.discipline import Discipline
from src.domain.validations import DomainError
import unittest


class DisciplineTest(unittest.TestCase):
    def setUp(self) -> None:
        self.__discipline = Discipline("123", "letters")

    def tearDown(self) -> None:
        pass

    def testInit_onlyDigitsAndOnlyLetters_nameShouldBeCorrectAndNoErrors(self):
        self.assertEqual(self.__discipline.name, "letters")

    def testInit_onlyDigitsAndOnlyLetters_idShouldBeCorrectAndNoErrors(self):
        self.assertEqual(self.__discipline.id, 123)

    def testSetNameFunction_onlyDigitsAndOnlyLetters_nameShouldBeSetCorrectly(self):
        self.__discipline.name = "maths"
        self.assertEqual(self.__discipline.name, "maths")

    def testInit_randomValueAndOnlyLetters_displayNameError(self):
        with self.assertRaises(DomainError) as error:
            Discipline("123", "123")
        self.assertEqual(str(error.exception), "Discipline name should contain only letters!")

    def testInit_onlyDigitsAndRandomValue_displayFirstIDError(self):
        with self.assertRaises(DomainError) as error:
            Discipline("abc", "letters")
        self.assertEqual(str(error.exception), "Discipline ID should contain only digits!")

    def testInit_onlyDigitsAndRandomValue_displaySecondIDError(self):
        with self.assertRaises(DomainError) as error:
            Discipline("0", "letters")
        self.assertEqual(str(error.exception), "Discipline ID should be greater than 0!")

    def testInit_onlyDigitsAndNoNameValue_displayNoNameError(self):
        with self.assertRaises(DomainError) as error:
            Discipline("1", "")
        self.assertEqual(str(error.exception), "Discipline name should contain only letters!")
