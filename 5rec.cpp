#include <iostream>
#include <cmath>
using namespace std;

double calculate_a(int i) {
    if (i == 0) {
        return 1;
    }
    else if (i == 1) {
        return 1;
    }
    else {
        double a_i_1 = calculate_a(i - 1);
        double a_i_2 = calculate_a(i - 2);
        double result = a_i_2 + (a_i_1 / pow(2, i - 2));
        return result;
    }
}

double calculate_product(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        double a_n = calculate_a(n);
        double product_n_minus_1 = calculate_product(n - 1);
        return product_n_minus_1 * a_n;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    double result = calculate_product(n);
    cout << "The product of a_1 to a_" << n << " is " << result << endl;
    return 0;
}
