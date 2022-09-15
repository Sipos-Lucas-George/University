from src.domain.student import Student
from src.domain.validations import DomainError
import unittest


class StudentTest(unittest.TestCase):
    def setUp(self) -> None:
        self.__student = Student("123", "letters")

    def tearDown(self) -> None:
        pass

    def testInit_onlyDigitsAndOnlyLetters_nameShouldBeCorrectAndNoErrors(self):
        self.assertEqual(self.__student.name, "letters")

    def testInit_onlyDigitsAndOnlyLetters_idShouldBeCorrectAndNoErrors(self):
        self.assertEqual(self.__student.id, 123)

    def testSetNameFunction_validInput_theNameShouldBeSetCorrectly(self):
        self.__student.name = "Luke"
        self.assertEqual(self.__student.name, "Luke")

    def testInit_randomValueAndOnlyLetters_displayNameError(self):
        with self.assertRaises(DomainError) as error:
            self.__student.name = "123"
        self.assertEqual(str(error.exception), "Student name should contain only letters!")

    def testInit_onlyDigitsAndRandomValue_displayFirstIDError(self):
        with self.assertRaises(DomainError) as error:
            Student("abc", "letters")
            self.assertEqual(str(error.exception), "Student ID should contain only digits!")

    def testInit_onlyDigitsAndRandomValue_displaySecondIDError(self):
        with self.assertRaises(DomainError) as error:
            Student("0", "letters")
        self.assertEqual(str(error.exception), "Student ID should be greater than 0!")

    def testInit_onlyDigitsAndNoNameValue_displayNoNameError(self):
        with self.assertRaises(DomainError) as error:
            Student("1", "")
        self.assertEqual(str(error.exception), "Student name should contain only letters!")
