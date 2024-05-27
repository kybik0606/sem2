#pragma once

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

class Vector 
{
private:
    int size;
    int* vctr;

public:
    Vector();
    Vector(int size);
    Vector(const Vector& other);
    Vector(const Vector&& other);
    ~Vector();

    void set_vector();
    int get_size();
    int get_element(int index);
    void set_element(int index, int number);
    void add_scalar(int scalar);
    void subtract_scalar(int scalar);
    void multiply_scalar(int scalar);
    void divide_scalar(int scalar);
    void sort_vector();
    void find_scalar_lenght();
    void get_all_elements();
    void set_all_elements();
    void random_elements_of_vector();
    void task(Vector& vctr1);
    int scalar_proizv(Vector& vctr1, Vector& vctr2);
    Vector& operator=(const Vector& vctr1);
};
