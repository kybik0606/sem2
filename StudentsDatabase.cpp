#include "StudentsDatabase.h"
#include "Students.h"


StudentsDatabase::StudentsDatabase() 
{
    name = "";
    age = 0;
    course = 0;
    gender = 0;
    grades = 0.0;
    subject = "";
}

StudentsDatabase::StudentsDatabase(const string& name, unsigned int age, unsigned int course, unsigned int gender, double grades, const string& subject)
    : name(name), age(age), course(course), gender(gender), grades(grades), subject(subject) {}


StudentsDatabase::StudentsDatabase(const StudentsDatabase& other) 
{
    name = other.name;
    age = other.age;
    course = other.course;
    gender = other.gender;
    grades = other.grades;
    subject = other.subject;
}

StudentsDatabase::StudentsDatabase(StudentsDatabase&& other) 
{
    name = move(other.name);
    age = move(other.age);
    course = move(other.course);
    gender = move(other.gender);
    grades = move(other.grades);
    subject = move(other.subject);
}

StudentsDatabase::~StudentsDatabase()
{};
void StudentsDatabase::add_student()
{
    studentsBase[this->numStudent].fill_data_of_student();
    this->numStudent++;
}
void StudentsDatabase::out_students_database()
{
    for (int i = 0; i < numStudent; i++)
        studentsBase[i].output_to_the_screen();
}
void StudentsDatabase::write_binary_file_db()
{
    for (int i = 0; i < numStudent; i++)
        studentsBase[i].load_binaryfile(studentsBase[i]);
}
void StudentsDatabase::read_binary_file_db()
{
    for (int i = 0; i < numStudent; i++)
        studentsBase[i].save_binaryfile(studentsBase[i]);
}

void StudentsDatabase::find_student(int index)
{
    cout << "Student under index " << index + 1 << ":" << endl;
    studentsBase[index].output_to_the_screen();
}
void StudentsDatabase::Determine_underachieving_students(unsigned int course, string& subject)
{
    int count = 0;
    for (const auto& student : studentsBase) 
    {
        if (student.getCourse() == course && student.getSubject() == subject && student.getGrades() < 4) {
            count++;
        }
    }
    cout << "Number of underachieving students " << course << " for subject " << subject << ": " << count << endl;
}
string StudentsDatabase::getName() const 
{
    return name;
}

unsigned int StudentsDatabase::getAge() const 
{
    return age;
}

unsigned int StudentsDatabase::getCourse() const 
{
    return course;
}

unsigned int StudentsDatabase::getGender() const 
{
    return gender;
}

double StudentsDatabase::getGrades() const 
{
    return grades;
}

string StudentsDatabase::getSubject() const 
{
    return subject;
}