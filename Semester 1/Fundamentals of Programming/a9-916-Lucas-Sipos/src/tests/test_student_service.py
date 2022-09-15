from src.services.student_service import StudentService
from src.repository.repository import Repository
import unittest


class StudentServiceTest(unittest.TestCase):
    def setUp(self) -> None:
        self.__studentService = StudentService(Repository())

    def tearDown(self) -> None:
        pass

    def testAddStudentToDictionary_validInputToClassStudent_shouldAddToStudentServiceRepository(self):
        self.__studentService.addStudentToDictionary("1", "Rose")
        self.assertEqual(self.__studentService.getStudentFromDictionary(1), "Rose")

    def testSearchByIDInListOfDisciplines_validInputToClassDiscipline_shouldSearchForDigitSubstringInDictionary(self):
        self.__studentService.addStudentToDictionary("1", "IT")
        self.assertEqual(self.__studentService.searchByIDInListOfStudents("1")[0].id, 1)

    def testSearchByNameInListOfDisciplines_validInputToClassDiscipline_shouldSearchForSubstringInDictionary(self):
        self.__studentService.addStudentToDictionary("1", "IT")
        self.assertEqual(self.__studentService.searchByNameInListOfStudents("t")[0].name, "IT")

    def testSortDiscipline_validListToSort_shouldReturnTheListSorted(self):
        self.__studentService.addStudentToDictionary("2", "IT")
        self.__studentService.addStudentToDictionary("1", "PE")
        self.assertEqual(self.__studentService.sortStudents()[0].id, 1)

    def testDeleteStudentFromDictionary_validInputAndCorrectIDToDelete_shouldNotExistAnymore(self):
        self.__studentService.addStudentToDictionary("1", "Rose")
        self.__studentService.addStudentToDictionary("2", "Emma")
        self.__studentService.deleteStudentFromDictionary(2)
        self.assertNotIn("Emma", self.__studentService.getAllStudentsFromDictionary())

    def testUpdateStudentFromDictionary_validInputAndUpdateValidInput_shouldUpdateStudentName(self):
        self.__studentService.addStudentToDictionary("1", "Rose")
        self.__studentService.updateStudentFromDictionary(1, "Emma")
        self.assertEqual(self.__studentService.getStudentFromDictionary(1), "Emma")
