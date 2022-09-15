class GradeValidator:
    def __init__(self, laboratoryNumber, laboratoryProblem, value):
        if value < 1 or value > 10:
            raise ValueError("Incorrect input!")
        if laboratoryNumber < 1 or laboratoryNumber > 14:
            raise ValueError("Incorrect input!")
        if laboratoryProblem < 1 or laboratoryProblem > 20:
            raise ValueError("Incorrect input!")
