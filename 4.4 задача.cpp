#include <iostream>
#include <fstream>
#include "Vector.h"

using namespace std;

int main() 
{
    setlocale(LC_ALL, "");
    Vector vctr1;
    Vector vctr2;
    vctr1.set_vector();
    vctr1.random_elements_of_vector();
    vctr1.get_all_elements();
    vctr1.find_scalar_lenght();
    cout << endl;

    vctr1.add_scalar(5);
    vctr1.get_all_elements();
    vctr1.subtract_scalar(3);
    vctr1.get_all_elements();
    vctr1.multiply_scalar(2);
    vctr1.get_all_elements();
    vctr1.divide_scalar(2);
    vctr1.get_all_elements();

    vctr2.set_vector();
    vctr2.random_elements_of_vector();
    vctr2.get_all_elements();
    vctr2.find_scalar_lenght();

    Vector vctr;
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
