#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

class Student 
{

    string name;
    unsigned int age;
    unsigned int course;
    unsigned int gender;
    double grades;
    string subject;

public:

    Student();
    Student(const string& name, unsigned int age, unsigned int course, unsigned int gender, double grades, const string& subject);
    Student(const Student& other);
    Student(Student&& other);
    ~Student();

    void fill_data_of_student();
    void load_binaryfile(Student student);
    void save_binaryfile(Student student);
    void output_to_the_screen();

    string getName() const;
    unsigned int getAge() const;
    unsigned int getCourse() const;
    unsigned int getGender() const;
    double getGrades() const;
    string getSubject() const;
};
