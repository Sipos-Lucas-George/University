from src.service.service import Service
from src.repository.repository import Repository
import unittest


class Function2Test(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo = Service(Repository())

    def tearDown(self) -> None:
        pass

    def testIfIDCorrect(self):
        self.__repo.addFlight("RO123", "Buc", "15:00", "Tim", "15:55")
        self.assertEqual(self.__repo.getAllFlights()[0].id, "RO123")

    def testIfDepartureCityAndTimeAndArrivalCityAndArrivalTime(self):
        self.__repo.addFlight("RO123", "Buc", "15:00", "Tim", "15:55")
        self.assertEqual(self.__repo.getAllFlights()[0].all, ('Buc', '15:00', 'Tim', '15:55'))

    def testSameID(self):
        self.__repo.addFlight("RO123", "Buc", "15:00", "Tim", "15:55")
        with self.assertRaises(ValueError) as error:
            self.__repo.addFlight("RO123", "SM", "16:00", "Dej", "16:30")
        self.assertEqual(str(error.exception), "")

    def testWrongCityInput(self):
        with self.assertRaises(ValueError) as error:
            self.__repo.addFlight("RO123", "123", "15:00", "Tim", "15:55")
        self.assertEqual(str(error.exception), "")

    def testWrongHourInput(self):
        with self.assertRaises(ValueError) as error:
            self.__repo.addFlight("RO123", "Buc", "1500", "Tim", "15:55")
        self.assertEqual(str(error.exception), "")

