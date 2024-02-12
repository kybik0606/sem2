/*1.1. ПЕРЕДАЧА ПАРАМЕТРОВ ПО ЗНАЧЕНИЮ И ПО ССЫЛКЕ 
Выполнить задания, оформив их через функции. Все необходимые данные для
функций должны передаваться в качестве параметров.
Результат функции получить тремя способами: через механизм return, через параметр-указатель, через 
ссылочный параметр.
Вариант 10: Определите номер максимального элемента последовательности Фибоначчи, 
попадающего в диапазон допустимых значений типа unsigned char*/

#include <iostream>
#include <limits.h>
using namespace std;

int findmax_fibonacci_return();
void findmax_fibonacci_indicator(int* pb);
void findmax_fibonacci_link(int& pb);

int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Введите номер: 1 - return, 2 - указатель, 3 - ссылка" << endl;
    int x;
    cin >> x;
    switch (x)
    {
        case (1):
        {
            cout << findmax_fibonacci_return();
            break;
        }
        case (2):
        {
            int b = 1;
            findmax_fibonacci_indicator(&b);
            cout << "Значение максимального элемента: " << b;
            break;
        }
        case (3):
        {
            int b = 1;
            findmax_fibonacci_link(b);
            cout << "Значение максимального элемента: " << b;
            break;
        }
        default:
        {
            cout << "Введено неверное значение";
            break;
        }
    }

    return 0;
    
}

int findmax_fibonacci_return()
{
    int a = 0;
    int b = 1;
    for (int i = 0; a + b <= UCHAR_MAX; i++)
    {
        int s;
        s = a + b;
        a = b;
        b = s;
    }
    cout << "Значение максимального элемента: ";
    return b;
}

void findmax_fibonacci_indicator(int* pb)
{
    int a = 0;
    for (int i = 0; a + *pb <= UCHAR_MAX; i++)
    {
        int s;
        s = a + *pb;
        a = *pb;
        *pb = s;
    }
}

void findmax_fibonacci_link(int& pb)
{
    int a = 0;
    for (int i = 0; a + pb <= UCHAR_MAX; i++)
    {
        int s;
        s = a + pb;
        a = pb;
        pb = s;
    }
}