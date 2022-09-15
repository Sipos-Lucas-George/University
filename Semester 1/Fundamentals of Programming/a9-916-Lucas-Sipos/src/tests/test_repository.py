from src.domain.student import Student
from src.repository.repository import Repository
from src.domain.validations import RepositoryError
import unittest


class RepositoryTest(unittest.TestCase):
    def setUp(self) -> None:
        self.__repository = Repository()

    def tearDown(self) -> None:
        pass

    def testRepositoryAddFunction_entityWithNoDuplicateID_shouldAddToRepositoryNoErrors(self):
        self.__repository.add(Student("1", "Name A"))
        self.assertEqual(self.__repository.get(1), "Name A")

    def testRepositoryLengthFunction_entityWithNoDuplicateID_shouldReturnTheRepositoryLength(self):
        self.__repository.add(Student("1", "Name A"))
        self.assertEqual(len(self.__repository), 1)

    def testRepositoryAddFunction_entityWithSameID_displayRepositoryException(self):
        self.__repository.add(Student("1", "Name A"))
        with self.assertRaises(RepositoryError) as error:
            self.__repository.add(Student("1", "Name A"))
        self.assertEqual(str(error.exception), "Entity with ID " + str(1) + " already in repository!")

    def testRepositoryDeleteFunction_entitiesWithDifferentIDsAndNames_secondEntityShouldNotExist(self):
        self.__repository.add(Student("1", "Name A"))
        self.__repository.add(Student("2", "Name B"))
        self.__repository.delete(2)
        self.assertNotIn("Name B", self.__repository.getAll())

    def testRepositoryDeleteFunction_randomEntityAndDeleteDifferentID_displayRepositoryException(self):
        self.__repository.add(Student("1", "Name A"))
        with self.assertRaises(RepositoryError) as error:
            self.__repository.delete(2)
        self.assertEqual(str(error.exception), "Entity with ID " + str(2) + " does not exist!")

    def testRepositoryUpdateFunction_validIDAndNewEntity_updateTheRepository(self):
        self.__repository.add(Student("1", "Name A"))
        self.__repository.update(1, "Name B")
        self.assertEqual(self.__repository[1].name, "Name B")

    def testRepositoryUpdateFunction_nonValidIDAndNewEntity_displayRepositoryException(self):
        self.__repository.add(Student("1", "Name A"))
        with self.assertRaises(RepositoryError) as error:
            self.__repository.update(2, "Name B")
        self.assertEqual(str(error.exception), "Entity with ID " + str(2) + " does not exist!")
