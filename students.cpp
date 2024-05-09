#include "Students.h"


Student::Student() 
{
    name = "";
    age = 0;
    course = 0;
    gender = 0;
    grades = 0.0;
    subject = "";
}

Student::Student(const string& name, unsigned int age, unsigned int course, unsigned int gender, double grades, const string& subject)
    : name(name), age(age), course(course), gender(gender), grades(grades), subject(subject) {}


Student::Student(const Student& other) 
{
    name = other.name;
    age = other.age;
    course = other.course;
    gender = other.gender;
    grades = other.grades;
    subject = other.subject;
}

Student::Student(Student&& other)
{
    name = move(other.name);
    age = move(other.age);
    course = move(other.course);
    gender = move(other.gender);
    grades = move(other.grades);
    subject = move(other.subject);
}

Student::~Student()
{};

void Student::fill_data_of_student()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter course: ";
    cin >> course;
    cout << "Enter gender (1 - male, 2 - female): ";
    cin >> gender;
    cout << "Enter grades: ";
    cin >> grades;
    cout << "Enter subject: ";
    cin >> subject;
}

void Student::load_binaryfile(Student student) 
{
    ifstream inFile("students.bin", ios::binary);
    if (!inFile) 
        return;
    inFile.read(reinterpret_cast<char*>(this), sizeof(Student));
    inFile.close();
}

void Student::save_binaryfile(Student student) 
{
    ofstream outFile("students.bin", ios::binary | ios::app);
    outFile.write(reinterpret_cast<const char*>(this), sizeof(Student));
    outFile.close();
}



void Student::output_to_the_screen() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Course: " << course << endl;
    cout << "Gender: " << (gender == 1 ? "Male" : "Female") << endl;
    cout << "Grades: " << grades << endl;
    cout << "Subject: " << subject << endl << endl;
}

string Student::getName() const {
    return name;
}

unsigned int Student::getAge() const {
    return age;
}

unsigned int Student::getCourse() const {
    return course;
}

unsigned int Student::getGender() const {
    return gender;
}

double Student::getGrades() const {
    return grades;
}

string Student::getSubject() const {
    return subject;
}