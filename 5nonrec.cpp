#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Введите n: ";
    cin >> n;

    double a_i_minus_2 = 1;
    double a_i_minus_1 = 1;
    double a_i = 0;
    double result = 1;

    for (int i = 2; i <= n; i++) {
        a_i = a_i_minus_2 + (a_i_minus_1 / pow(2, i - 2));
        result *= a_i;
        a_i_minus_2 = a_i_minus_1;
        a_i_minus_1 = a_i;
    }

    cout << "Произведение a_1 * a_2 * a_3 * ... * a_n: " << result << endl;

    return 0;
}
