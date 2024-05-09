#pragma once
#include "Students.h"

class StudentsDatabase
{
    Student studentsBase[100];
    int numStudent = 0;
    int size;
    string name;
    unsigned int age;
    unsigned int course;
    unsigned int gender;
    double grades;
    string subject;

public:
    StudentsDatabase();
    StudentsDatabase(const string& name, unsigned int age, unsigned int course, unsigned int gender, double grades, const string& subject);
    StudentsDatabase(const StudentsDatabase& other);
    StudentsDatabase(StudentsDatabase&& other);
    ~StudentsDatabase();

    void add_student();

    void out_students_database();

    void write_binary_file_db();

    void read_binary_file_db();

    void find_student(int index);

    void Determine_underachieving_students(unsigned int course, string& subject);

    string getName() const;
    unsigned int getAge() const;
    unsigned int getCourse() const;
    unsigned int getGender() const;
    double getGrades() const;
    string getSubject() const;

};
