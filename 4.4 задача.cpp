#include <iostream>
#include <fstream>
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    vector vctr1;
    vctr1.set_vector();
    vctr1.random_elements_of_vector();
    vctr1.get_all_elements();
    vctr1.find_scalar_lenght();
    vector vctr2;
    vctr2.set_vector();
    vctr2.random_elements_of_vector();
    vctr2.get_all_elements();
    cout << endl;
    vctr1.actions_with_scalar();
    vctr1.find_scalar_lenght();

    vector vctr;
    if (vctr1.get_size() != vctr2.get_size()) 
    {
        cout << "Векторы разных размеров. " << endl;
    }
    else 
    {
        cout << endl << "Скалярное произведение векторов X и Y: " << vctr.scalar_proizv(vctr1, vctr2) << endl << endl;
    }
    vctr.task(vctr1);
    vctr2 = vctr1;
    cout << endl;
    vctr2.get_all_elements();
    return 0;
}