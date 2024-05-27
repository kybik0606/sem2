#pragma once

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

class vector {
private:
    int size;
    int* vctr;

public:
    vector();
    vector(int size);
    vector(const vector& other);
    vector(const vector&& other);
    ~vector();

    void set_vector();
    int get_size();
    int get_element(int index);
    void set_element(int index, int number);
    void actions_with_scalar();
    void find_scalar_lenght();
    void get_all_elements();
    void set_all_elements();
    void random_elements_of_vector();
    void task(vector& vctr1);
    int scalar_proizv(vector& vctr1, vector& vctr2);
    vector& operator=(const vector& vctr1);
};
