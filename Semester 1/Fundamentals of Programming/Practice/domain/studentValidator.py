class StudentValidator:
    def __init__(self, name, group):
        if not name.isalpha() or len(str(group)) > 3:
            raise ValueError("Incorrect input!")
