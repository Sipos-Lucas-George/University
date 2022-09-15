from src.services.discipline_service import DisciplineService
import unittest


class DisciplineServiceTest(unittest.TestCase):
    def setUp(self) -> None:
        self.__disciplineService = DisciplineService()

    def tearDown(self) -> None:
        pass

    def testAddStudentToDictionary_validInputToClassDiscipline_shouldAddToStudentServiceRepository(self):
        self.__disciplineService.addDisciplineToDictionary("1", "IT")
        self.assertEqual(self.__disciplineService.getDisciplineFromDictionary(1), "IT")

    def testSearchByIDInListOfDisciplines_validInputToClassDiscipline_shouldSearchForDigitSubstringInDictionary(self):
        self.__disciplineService.addDisciplineToDictionary("1", "IT")
        self.assertEqual(self.__disciplineService.searchByIDInListOfDisciplines("1")[0].id, 1)

    def testSearchByNameInListOfDisciplines_validInputToClassDiscipline_shouldSearchForSubstringInDictionary(self):
        self.__disciplineService.addDisciplineToDictionary("1", "IT")
        self.assertEqual(self.__disciplineService.searchByNameInListOfDisciplines("t")[0].name, "IT")

    def testSortDiscipline_validListToSort_shouldReturnTheListSorted(self):
        self.__disciplineService.addDisciplineToDictionary("2", "IT")
        self.__disciplineService.addDisciplineToDictionary("1", "PE")
        self.assertEqual(self.__disciplineService.sortDiscipline()[0].id, 1)

    def testDeleteStudentFromDictionary_validInputAndCorrectIDToDelete_shouldNotExistAnymore(self):
        self.__disciplineService.addDisciplineToDictionary("1", "IT")
        self.__disciplineService.addDisciplineToDictionary("2", "PE")
        self.__disciplineService.deleteDisciplineFromDictionary(2)
        self.assertNotIn("PE", self.__disciplineService.getAllDisciplinesFromDictionary())

    def testUpdateStudentFromDictionary_validInputAndUpdateValidInput_shouldUpdateStudentName(self):
        self.__disciplineService.addDisciplineToDictionary("1", "IT")
        self.__disciplineService.updateDisciplineFromDictionary(1, "PE")
        self.assertEqual(self.__disciplineService.getDisciplineFromDictionary(1), "PE")
