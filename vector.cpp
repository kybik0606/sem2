#include "vector.h"

using namespace std;

Vector::Vector() 
{
    size = 0;
    vctr = nullptr;
}

Vector::Vector(int size) 
{
    this->size = size;
    vctr = new int[size];
}

Vector::Vector(const Vector& other) 
{
    size = other.size;
    vctr = new int[size];
    for (int i = 0; i < size; i++) 
    {
        vctr[i] = other.vctr[i];
    }
}

Vector::Vector(const Vector&& other)
{
    size = other.size;
    vctr = new int[size];
    for (int i = 0; i < size; i++) 
    {
        vctr[i] = other.vctr[i];
        other.vctr[i] = 0;
    }
}

Vector::~Vector() 
{
    delete[] vctr;
}

void Vector::set_vector() 
{
    cout << "Введите размер вектора: ";
    cin >> size;
    vctr = new int[size];
    cout << endl;
}

int Vector::get_size() 
{
    return size;
    cout << endl;
}

int Vector::get_element(int index)
{
    if (index >= size) 
    {
        cout << "Вы вышли за пределы размерности вектора." << endl;
        return 0;
    }

    return vctr[index];
    cout << endl;
}

void Vector::set_element(int index, int number)
{
    if (index < size)
    {
        vctr[index] = number;
        cout << endl;
    }
    else
    {
        cout << "Вы вышли за пределы размерности вектора." << endl;
    }
}

void Vector::add_scalar(int scalar) 
{
    cout << "прибавление " << scalar << ": ";
    for (int i = 0; i < size; i++) 
    {
        vctr[i] += scalar;
    }
}

void Vector::subtract_scalar(int scalar) 
{
    cout << "вычитание " << scalar << ": ";
    for (int i = 0; i < size; i++) 
    {
        vctr[i] -= scalar;
    }
}

void Vector::multiply_scalar(int scalar) 
{
    cout << "умножение на " << scalar << ": ";
    for (int i = 0; i < size; i++) 
    {
        vctr[i] *= scalar;
    }
}

void Vector::divide_scalar(int scalar) 
{
    if (scalar != 0) 
    {
        cout << "деление на " << scalar << ": ";
        for (int i = 0; i < size; i++) 
        {
            vctr[i] = static_cast<double>(vctr[i]) / scalar;
        }
    }
    else 
    {
        cout << "Ошибка: деление на ноль." << endl;
    }
}

void Vector::find_scalar_lenght() 
{
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += vctr[i] * vctr[i];
    }
    double length = sqrt(sum);
    cout << "Длина вектора : " << length << endl << endl;
}


void Vector::get_all_elements() 
{
    cout << "Значения всех элементов вектора: ";
    for (int i = 0; i < size; i++) 
    {
        cout << vctr[i] << " ";
    }
    cout << endl << endl;
}

void Vector::set_all_elements() 
{
    cout << "Введите элементы вектора: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> vctr[i];
    }
    cout << endl;
}

void Vector::random_elements_of_vector()
{
    srand(time(0));
    for (int i = 0; i < size; i++) 
    {
        vctr[i] = rand() % 10 - 0 + 1;
    }
}


void Vector::task(Vector& vctr1) 
{
    
    size = vctr1.size;
    this->vctr = new int[size];

    int* sortedX = new int[size];
    copy(vctr1.vctr, vctr1.vctr + size, sortedX);
    sort(sortedX, sortedX + size);
    copy(sortedX, sortedX + size, vctr);

    delete[] sortedX;

    cout << "Полученный вектор Y (упорядоченный по возрастанию значений элементов X): ";
    for (int i = 0; i < size; i++)
    {
        cout << vctr[i] << " ";
    }
}

int Vector::scalar_proizv(Vector& vctr1, Vector& vctr2)
{
    
    size = vctr2.size;
    this->vctr = new int[size];

    int scalarProduct = 0;
    for (int i = 0; i < size; i++) 
    {
        scalarProduct += vctr1.vctr[i] * vctr2.vctr[i];
    }
    delete[] this->vctr;
    return(scalarProduct);
}

Vector& Vector::operator=(const Vector& vector)
{
    if (this != &vector)
    {
        if (size != vector.size)
        {
            delete[] this->vctr;
            size = vector.size;
            this->vctr = new int[size];
        }
        for (int i = 0; i < size; ++i)
            this->vctr[i] = vector.vctr[i];
    }
    return *this;
}
