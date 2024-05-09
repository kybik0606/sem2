//Вариант 10 задача 4.2
#define _CRT_SECURE_NO_WARNINGS 
#include "Students.h"
#include <iostream>
#include <vector>
using namespace std;

void Determine_underachieving_students(const vector<Student>& students, unsigned int course, const string& subject);

int main() {
    vector<Student> students;
    int num_students;
    cout << "Enter the number of students: ";
    cin >> num_students;

    for (int i = 0; i < num_students; ++i) {
        Student student;
        student.fill_data_of_student();
        students.push_back(student);
        student.save_binaryfile();
    }

    unsigned int course;
    string subject;
    cout << "Enter the course number: ";
    cin >> course;
    cout << "Enter the subject: ";
    cin >> subject;

    Determine_underachieving_students(students, course, subject);

    return 0;
}
void Determine_underachieving_students(const vector<Student>& students, unsigned int course, const string& subject) {
    int count = 0;
    for (const auto& student : students) {
        if (student.getCourse() == course && student.getSubject() == subject && student.getGrades() < 4) {
            ++count;
        }
    }
    cout << "Number of underachieving students " << course << " for subject " << subject << ": " << count << endl;
}
