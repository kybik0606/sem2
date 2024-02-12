/*1.2. ВЫЧИСЛЕНИЕ ЗНАЧЕНИЯ МНОГОЧЛЕНА
Выполнить задания, оформив их через функции. Все необходимые данные для 
функций должны передаваться в качестве параметров. 
Вычислить значение многочлена для заданного n в точках хi c [х0; хm] 
(хi = х0 + iх, i = 0,1,…), суммируя элементы по возрастанию степени x.
Варниант 10*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void counting(double x0, double xm, double dx, int n);

int main()
{
    setlocale(LC_ALL, "RU");
    double x0 = 0, xm = 3, dx = 0.5;
    int n;
    cout << "Введите степень, n: ";
    cin >> n;
    cout << left << setw(5) << "x" << left << setw(5) << "y" << endl;
    counting(x0, xm, dx, n);
    return 0;
}

void counting(double x0, double xm, double dx, int n)
{
    double y = 0, xi = 0;
    for (int i = 0; xi < xm; i++)
    {
        xi = x0 + i * dx;
        cout << setw(5) << xi;
        for (int j = 1; j <= n; j++)
        {
            y += pow(-1, j) * j * pow(xi, j);
        }
        cout << left << setw(5) << y << endl;
        y = 0;  
    }
}