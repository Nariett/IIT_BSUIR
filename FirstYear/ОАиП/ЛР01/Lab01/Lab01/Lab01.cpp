#include <iostream>
double factorial(int num)
{
    double result = 1;
    for (int i = 1; i <= num; ++i)
    {
        result *= i;
    }
    return result;
}

double power(double num, int degree)
{
    double result = 1.0;
    for (int i = 0; i < degree; ++i)
    {
        result *= num;
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double x, e;
    int a;

    do {
        std::cout << "Введите число x (x != 0): ";
        std::cin >> x;
        if (x == 0) {
            std::cout << "X не должно быть равно 0." << std::endl;
        }
    } while (x == 0);

    do {
        std::cout << "Введите число e (e > 0): ";
        std::cin >> e;
        if (e <= 0) {
            std::cout << "e должно быть положительным." << std::endl;
        }
    } while (e <= 0);

    do {
        std::cout << "Введите число a (|a| < 10^6): ";
        std::cin >> a;
        if (abs(a) >= 1000000) {
            std::cout << "|a| должно быть меньше 10^6." << std::endl;
        }
    } while (abs(a) >= 1000000);

    double a_factorial = factorial(a);

    double sum = 0.0;
    int count = 0;
    int k = 1;

    while (true) {
   
        double b = (k % 2 == 1) ? a_factorial : 0.0;
        double term = (cos(k * x) / power(k, 2)) * b;

        if (fabs(term) < e) {
            break;
        }

        sum += term;
        ++count;
        ++k;
    }

    if (count == 0) {
        std::cout << "Ни одно слагаемое не было учтено (все слагаемые меньше e)." << std::endl;
    }
    else {
        std::cout.precision(8);
        std::cout << "Сумма S = " << std::fixed << sum << std::endl;
        std::cout << "Количество учтённых слагаемых: " << count << std::endl;
    }
    return 0;
}
