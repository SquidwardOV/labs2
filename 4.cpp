#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

double integral(int n, double x) {

    double a = 2.0;

    if (n > 1) return (pow(x, n) * exp(a * x)) / a - (n / a) * integral(n - 1, x);
    
    if (n == 1) return (exp(a * x) * (a * x - 1)) / (pow(a, 2));



}
int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int a, b, n;

    cout << "Введите пределы интегрирования (a,b): " << endl;
    cin >> a >> b;
    cout << endl;

    cout << "Введите степень (n): " << endl;
    cin >> n;
    cout << endl;

    cout << integral(n, b) - integral(n, a);

    return 0;
}
