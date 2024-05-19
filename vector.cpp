#include "vector.h"

using namespace std;

vector::vector() {
    size = 0;
    vctr = nullptr;
}

vector::vector(int size) {
    this->size = size;
    vctr = new int[size];
}

vector::vector(const vector& other) {
    size = other.size;
    vctr = new int[size];
    for (int i = 0; i < size; i++) {
        vctr[i] = other.vctr[i];
    }
}

vector::vector(const vector&& other) {
    size = other.size;
    vctr = new int[size];
    for (int i = 0; i < size; i++) {
        vctr[i] = other.vctr[i];
        other.vctr[i] = 0;
    }
}

vector::~vector() {
    delete[] vctr;
}

void vector::set_vector() {
    cout << "Введите размер вектора: ";
    cin >> size;
    vctr = new int[size];
    cout << endl;
}

int vector::get_size() {
    return size;
    cout << endl;
}

int vector::get_element(int index) {
    if (index >= size) {
        cout << "Вы вышли за пределы размерности вектора." << endl;
        return 0;
    }

    return vctr[index];
    cout << endl;
}

void vector::set_element(int index, int number) {
    if (index < size) {
        vctr[index] = number;
        cout << endl;
    }
    else {
        cout << "Вы вышли за пределы размерности вектора." << endl;
    }
}

void vector::actions_with_scalar() {
    cout << "Введите номер операции, которую вы хотите провести со скаляром:\n1.'+'\n2.'-'\n3.'*'\n4.'" << endl << endl;
    int choice;
    cin >> choice;
    cout << "Введите значение скаляра: ";
    int scalar;
    cin >> scalar;
    cout << endl;
    switch (choice) {
    case 1:
        for (int i = 0; i < size; i++) {
            vctr[i] += scalar;
            cout << vctr[i] << " ";
        }
        break;
    case 2:
        for (int i = 0; i < size; i++) {
            vctr[i] -= scalar;
            cout << vctr[i] << " ";
        }
        break;
    case 3:
        for (int i = 0; i < size; i++) {
            vctr[i] *= scalar;
            cout << vctr[i] << " ";
        }
        break;
    case 4:
        for (int i = 0; i < size; i++) {
            if (scalar != 0) {
                vctr[i] = static_cast<double>(vctr[i]) / scalar;
                cout << vctr[i] << " ";
            }
            else {
                cout << "Ошибка: деление на ноль." << endl;
                break;
            }
        }
        break;
    }
}

void vector::find_scalar_lenght() {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += vctr[i] * vctr[i];
    }
    double length = sqrt(sum);
    cout << "Длина вектора : " << length << endl << endl;
}


void vector::get_all_elements() {
    cout << "Значения всех элементов вектора: ";
    for (int i = 0; i < size; i++) {
        cout << vctr[i] << " ";
    }
    cout << endl << endl;
}

void vector::set_all_elements() {
    cout << "Введите элементы вектора: ";
    for (int i = 0; i < size; i++) {
        cin >> vctr[i];
    }
    cout << endl;
}

void vector::random_elements_of_vector() {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        vctr[i] = rand() % 10 - 0 + 1;
    }
}


void vector::task(vector& vctr1) {
    
    size = vctr1.size;
    this->vctr = new int[size];

    int* sortedX = new int[size];
    copy(vctr1.vctr, vctr1.vctr + size, sortedX);
    sort(sortedX, sortedX + size);
    copy(sortedX, sortedX + size, vctr);

    delete[] sortedX;

    cout << "Полученный вектор Y (упорядоченный по возрастанию значений элементов X): ";
    for (int i = 0; i < size; i++) {
        cout << vctr[i] << " ";
    }
}

int vector::scalar_proizv(vector& vctr1, vector& vctr2) {
    
    size = vctr2.size;
    this->vctr = new int[size];

    int scalarProduct = 0;
    for (int i = 0; i < size; i++) {
        scalarProduct += vctr1.vctr[i] * vctr2.vctr[i];
    }
    delete[] this->vctr;
    return(scalarProduct);
}

vector& vector::operator=(const vector& vector)
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