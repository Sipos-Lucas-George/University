from src.service.service import Service
import traceback


class UserInterface:
    def __init__(self, flightService: Service):
        self.__flightService = flightService
        self.__commandDict = {
            "add": self.addFlight,
            "delete": self.deleteFlight,
            "list": self.listFlights,
            "list airports": self.listAirports,
        }

    def start(self):
        while True:
            inputCommand = (input("Enter your option: ")).strip()
            try:
                if inputCommand == "exit":
                    return
                else:
                    self.__commandDict[inputCommand]()
            except ValueError:
                print("Something was incorrect")
                traceback.print_exc()
            except KeyError:
                print(f"The command {inputCommand} does not exist!")

    def addFlight(self):
        try:
            identifier = input("Identifier: ").strip()
            departureCity = input("Departure city: ").strip()
            time = input("Time: ").strip()
            arrivalCity = input("Arrival city: ").strip()
            arrivalTime = input("Arrival time: ").strip()
            self.__flightService.addFlight(identifier, departureCity, time, arrivalCity, arrivalTime)
        except ValueError:
            print("Incorrect input!")

    def deleteFlight(self):
        try:
            identifier = input("Identifier: ").strip()
            self.__flightService.deleteFlight(identifier)
        except ValueError:
            print("Incorrect ID!")

    def listFlights(self):
        listFlights = self.__flightService.getAllFlights()
        for flight in listFlights:
            print(flight.id, *flight.all)

    def listAirports(self):
        listFlights = self.__flightService.getAirports()
        print(listFlights)
