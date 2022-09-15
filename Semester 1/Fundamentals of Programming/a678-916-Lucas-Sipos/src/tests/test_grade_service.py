from src.services.grade_service import GradeService
from src.services.student_service import StudentService
from src.services.discipline_service import DisciplineService
import unittest


class GradeServiceTest(unittest.TestCase):
    def setUp(self) -> None:
        self.__gradeService = GradeService()
        self.__studentService = StudentService()
        self.__disciplineService = DisciplineService()
        self.__studentService.addStudentToDictionary("1", "L")
        self.__studentService.addStudentToDictionary("2", "P")
        self.__studentService.addStudentToDictionary("3", "C")
        self.__disciplineService.addDisciplineToDictionary("1", "IT")
        self.__disciplineService.addDisciplineToDictionary("2", "PE")

    def tearDown(self) -> None:
        pass

    def testAddStudentToDictionary_validInputToClassStudent_shouldAddToStudentServiceRepository(self):
        self.__gradeService.addGradeToDictionary("1", "1", "10")
        self.assertEqual(self.__gradeService.getAllGradesFromDictionary()[0].name, 10)

    def testGetLastElement_validInputToClassStudent_shouldReturnGradeIDOfLastElement(self):
        self.__gradeService.addGradeToDictionary("1", "1", "10")
        self.__gradeService.addGradeToDictionary("2", "2", "9")
        self.assertEqual(self.__gradeService.getLastElement(), 2)

    def testDeleteStudentFromDictionary_validInputAndCorrectIDToDelete_shouldNotExistAnymore(self):
        self.__gradeService.addGradeToDictionary("1", "1", "10")
        self.__gradeService.addGradeToDictionary("2", "2", "9")
        self.__gradeService.deleteGradeFromDictionary(2)
        self.assertNotIn(9, self.__gradeService.getAllGradesFromDictionary())

    def testUpdateStudentFromDictionary_validInputAndUpdateValidInput_shouldUpdateStudentName(self):
        self.__gradeService.addGradeToDictionary("1", "1", "10")
        self.__gradeService.updateGradeFromDictionary(1, "9")
        self.assertEqual(self.__gradeService.getAllGradesFromDictionary()[0].name, 9)

    def testGetSecondElement_giveAList_returnsSecondElement(self):
        self.__gradeService.addGradeToDictionary("2", "1", "6")
        self.__gradeService.addGradeToDictionary("1", "1", "4")
        self.assertEqual(self.__gradeService.sortGradesByStudents()[0].studentID, 1)

    def testGetAllFailingStudent_addGradesForEveryIfStatement_returnsAllGradesBelow5(self):
        self.__gradeService.addGradeToDictionary("1", "1", "4")
        self.__gradeService.addGradeToDictionary("2", "1", "6")
        self.__gradeService.addGradeToDictionary("1", "1", "5")
        self.__gradeService.addGradeToDictionary("3", "2", "4")
        self.assertEqual(self.__gradeService.getAllFailingStudents(self.__studentService, self.__disciplineService), [['P', 'IT', '4.500'], ['C', 'PE', '4.000']])

    def testGetTopStudentsAggregatedAverage_addGradesForEveryIfStatementAndLastIfCondition3_returnsTopStudents(self):
        self.__gradeService.addGradeToDictionary("1", "1", "4")
        self.__gradeService.addGradeToDictionary("2", "1", "6")
        self.__gradeService.addGradeToDictionary("2", "2", "6")
        self.__gradeService.addGradeToDictionary("1", "1", "5")
        self.__gradeService.addGradeToDictionary("3", "2", "4")
        self.assertEqual(self.__gradeService.getTopStudentsAggregatedAverage(self.__studentService), [['P', 6.0], ['L', 4.5], ['C', 4.0]])

    def testGetTopStudentsAggregatedAverage_addGradesForEveryIfStatementAndLastIfCondition2_returnsTopStudents(self):
        self.__gradeService.addGradeToDictionary("1", "1", "4")
        self.__gradeService.addGradeToDictionary("1", "1", "5")
        self.__gradeService.addGradeToDictionary("3", "2", "4")
        self.__gradeService.addGradeToDictionary("3", "1", "6")
        self.__gradeService.addGradeToDictionary("2", "1", "6")
        self.assertEqual(self.__gradeService.getTopStudentsAggregatedAverage(self.__studentService), [['P', 6.0], ['C', 5.0], ['L', 4.5]])

    def testGetTopDisciplines_addGradesForEveryIfStatement_returnsTopDiscipline(self):
        self.__gradeService.addGradeToDictionary("1", "1", "4")
        self.__gradeService.addGradeToDictionary("2", "1", "6")
        self.__gradeService.addGradeToDictionary("2", "1", "5")
        self.__gradeService.addGradeToDictionary("1", "2", "5")
        self.__gradeService.addGradeToDictionary("3", "2", "4")
        self.assertEqual(self.__gradeService.getTopDisciplines(self.__disciplineService), [['IT', 5.0], ['PE', 4.5]])
