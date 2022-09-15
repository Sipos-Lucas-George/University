from src.repository.repository import Repository, TextFileRepository, BinaryFileRepository
from src.ui.user_interface import UserInterface
from src.services.student_service import StudentService
from src.services.discipline_service import DisciplineService
from src.services.grade_service import GradeService

filepath = "settings.properties"
commentCharacter = '#'
separator = "="
properties = {}

with open(filepath, "rt") as file:
    for line in file:
        currentLine: str = line.strip()
        if currentLine and not currentLine.startswith(commentCharacter):
            keyValue = currentLine.split(separator)
            key = keyValue[0].strip()
            value = separator.join(keyValue[1:]).strip().strip('"')
            properties[key] = value

if properties["repository"] == "inmemory":
    studentRepository = Repository()
    disciplineRepository = Repository()
    gradeRepository = Repository()
elif properties["repository"] == "textfiles":
    studentRepository = TextFileRepository(properties["students"], "Student")
    disciplineRepository = TextFileRepository(properties["disciplines"], "Discipline")
    gradeRepository = TextFileRepository(properties["grades"], "Grade")
elif properties["repository"] == "binaryfiles":
    studentRepository = BinaryFileRepository(properties["students"], "Student")
    disciplineRepository = BinaryFileRepository(properties["disciplines"], "Discipline")
    gradeRepository = BinaryFileRepository(properties["grades"], "Grade")
else:
    print("No valid repository type found. Selected \"inmemory\" type.")
    studentRepository = Repository()
    disciplineRepository = Repository()
    gradeRepository = Repository()

studentService = StudentService(studentRepository)
disciplineService = DisciplineService(disciplineRepository)
gradeService = GradeService(gradeRepository)

userInterface = UserInterface(studentService, disciplineService, gradeService, testFlag=False)
userInterface.start()
