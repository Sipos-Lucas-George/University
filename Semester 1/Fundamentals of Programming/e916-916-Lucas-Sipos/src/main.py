from src.repository.repository import Repository
from src.service.service import Service
from src.ui.ui import UserInterface


fileName = "input.txt"
file = open(fileName, "rt")
flightRepository = Repository()
flightService = Service(flightRepository)
userInterface = UserInterface(flightService)
for line in file:
    l = line.split(",")
    flightService.addFlight(l[0], l[1], l[2], l[3], l[4].strip())
userInterface.start()
