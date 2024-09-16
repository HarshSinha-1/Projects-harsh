class Course:
    def __init__(self, course_id, course_name, description, instructor):
        self.course_id = course_id
        self.course_name = course_name
        self.description = description
        self.instructor = instructor
        self.students = []
        self.lessons = []

    def add_student(self, student):
        self.students.append(student)
        student.enroll_course(self)

    def remove_student(self, student):
        if student in self.students:
            self.students.remove(student)
            student.drop_course(self)

    def add_lesson(self, lesson):
        self.lessons.append(lesson)

    def list_students(self):
        for student in self.students:
            print(student.name)


class Student:
    def __init__(self, student_id, name, email):
        self.student_id = student_id
        self.name = name
        self.email = email
        self.enrolled_courses = []

    def enroll_course(self, course):
        self.enrolled_courses.append(course)

    def drop_course(self, course):
        if course in self.enrolled_courses:
            self.enrolled_courses.remove(course)

    def view_courses(self):
        print(f"{self.name} is enrolled in the following courses:")
        for course in self.enrolled_courses:
            print(course.course_name)


class Instructor:
    def __init__(self, instructor_id, name, email):
        self.instructor_id = instructor_id
        self.name = name
        self.email = email
        self.courses_taught = []

    def create_course(self, course_id, course_name, description):
        course = Course(course_id, course_name, description, self)
        self.courses_taught.append(course)
        return course

    def delete_course(self, course):
        if course in self.courses_taught:
            self.courses_taught.remove(course)

    def list_courses(self):
        print(f"{self.name} teaches the following courses:")
        for course in self.courses_taught:
            print(course.course_name)


class Lesson:
    def __init__(self, lesson_id, title, content):
        self.lesson_id = lesson_id
        self.title = title
        self.content = content
        self.quiz = None

    def add_quiz(self, quiz):
        self.quiz = quiz

    def remove_quiz(self):
        self.quiz = None


class Quiz:
    def __init__(self, quiz_id):
        self.quiz_id = quiz_id
        self.questions = []

    def add_question(self, question):
        self.questions.append(question)

    def remove_question(self, question):
        if question in self.questions:
            self.questions.remove(question)


class Question:
    def __init__(self, question_id, question_text):
        self.question_id = question_id
        self.question_text = question_text
        self.options = []
        self.correct_answer = None

    def add_option(self, option):
        self.options.append(option)

    def set_correct_answer(self, correct_answer):
        self.correct_answer = correct_answer




# Create an instructor
instructor = Instructor(instructor_id=1, name='Harsh SInha', email='harshsinha@example.com')

# Create a course
course = instructor.create_course(course_id=101, course_name='Python Basics', description='Learn the basics of Python.')

# Create a student
student = Student(student_id=1001, name='shyam', email='shyam@example.com')

# Enroll the student in the course
course.add_student(student)

# List students enrolled in the course
course.list_students()

# Create a lesson for the course
lesson = Lesson(lesson_id=1, title='Introduction to Python', content='Python is a versatile programming language...')
course.add_lesson(lesson)

# Create a quiz
quiz = Quiz(quiz_id=1)

# Create a question for the quiz
question = Question(question_id=1, question_text='What is Python?')
question.add_option('A programming language')
question.add_option('A snake')
question.set_correct_answer('A programming language')

# Add the question to the quiz
quiz.add_question(question)

# Add the quiz to the lesson
lesson.add_quiz(quiz)

# List the courses the student is enrolled in
student.view_courses()
# Adding the new course
instructor.create_course(102,"Physics","Enginnering Physics")
#list of cources by instructor
instructor.list_courses()
# Create a new student
new_student = Student(student_id=1112, name='Saksham', email='saksham@example.com')

# Enroll the new student in the course
course.add_student(new_student)
student.enroll_course("physics")

