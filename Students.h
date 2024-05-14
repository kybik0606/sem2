#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
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
    void load_binaryfile(int index);
    void save_binaryfile();
    void output_to_the_screen();

    string get_name() const;
    unsigned int get_age() const;
    unsigned int get_course() const;
    unsigned int get_gender() const;
    double get_grades() const;
    string get_subject() const;
};
