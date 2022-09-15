from repository.studentRepository import StudentRepository
from repository.gradeRepository import GradeRepository
from controller.studentController import StudentController
from controller.gradeController import GradeController
from ui.ui import UI


gradeRepository = GradeRepository()
studentRepository = StudentRepository(gradeRepository)
studentController = StudentController(studentRepository)
gradeController = GradeController(gradeRepository)
ui = UI(studentController, gradeController)
ui.run()
