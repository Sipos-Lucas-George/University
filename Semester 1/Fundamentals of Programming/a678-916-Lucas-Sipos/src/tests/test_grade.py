from src.domain.grade import Grade
from src.domain.validations import DomainError
import unittest


class GradeTest(unittest.TestCase):
    def setUp(self) -> None:
        self.__grade = Grade(1, "2", "3", "10")

    def tearDown(self) -> None:
        pass

    def testInit_onlyDigitsTheDisciplineIDAndStudentIDDoNotMatterAndValidGradeValue_idShouldBeCorrectAndNoErrors(self):
        self.assertEqual(self.__grade.id, 1)

    def testInit_onlyDigitsTheDisciplineIDAndStudentIDDoNotMatterAndValidGradeValue_nameShouldBeCorrectAndNoErrors(self):
        self.assertEqual(self.__grade.name, 10)

    def testInit_onlyDigitsTheDisciplineIDAndStudentIDDoNotMatterAndValidGradeValue_studentIDShouldBeCorrectAndNoErrors(self):
        self.assertEqual(self.__grade.studentID, 2)

    def testInit_onlyDigitsTheDisciplineIDAndStudentIDDoNotMatterAndValidGradeValue_disciplineIDShouldBeCorrectAndNoErrors(self):
        self.assertEqual(self.__grade.disciplineID, 3)

    def testSetNameFunction_correctInput_theNameShouldBeSetCorrectly(self):
        self.__grade.name = "9"
        self.assertEqual(self.__grade.name, 9)

    def testSetNameFunction_notNumericGradeValue_raiseOnlyDigitsError(self):
        with self.assertRaises(DomainError) as error:
            self.__grade.name = "a"
        self.assertEqual(str(error.exception), "Grade value should contain only digits!")

    def testSetNameFunction_gradeValueInvalidNumber_raiseGradeValueIntervalError(self):
        with self.assertRaises(DomainError) as error:
            self.__grade.name = "11"
        self.assertEqual(str(error.exception), "Grade value should be between [1,10]!")

    def testInit_validIDTheDisciplineIDAndStudentIDDoNotMatterAndCharGrade_DomainError(self):
        with self.assertRaises(DomainError) as error:
            Grade(1, "2", "3", "a")
        self.assertEqual(str(error.exception), "Grade value should contain only digits!")

    def testInit_validIDTheDisciplineIDAndStudentIDDoNotMatterAndInvalidGrade_DomainError(self):
        with self.assertRaises(DomainError) as error:
            Grade(1, "2", "3", "11")
        self.assertEqual(str(error.exception), "Grade value should be between [1,10]!")
