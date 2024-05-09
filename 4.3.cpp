#include "StudentsDatabase.h"
#include "Students.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    vector<Student> students;
    int countStudents;

    cout << "Enter count of students: ";
    cin >> countStudents;
    StudentsDatabase base;

    for (int i = 0; i < countStudents; i++)
        base.add_student();

    cout << endl;
    base.out_students_database();
    base.write_binary_file_db();
    base.read_binary_file_db();
    base.find_student(0);
    unsigned int course;
    string subject;
    cout << "Enter number of course: ";
    cin >> course;
    cout << "Enter name of subject: ";
    cin >> subject;
    base.Determine_underachieving_students(course, subject);
    const char* data = "students.bin";
    remove(data);
    return 0;
}
