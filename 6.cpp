#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

const double PI = 3.14159265358979323846;
// Площадь круга
float square(float radius) {
    return PI * pow(radius, 2);
}

// Площадь треугольника
float square(float x1, float y1, float x2, float y2, float x3, float y3) {
    float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    float c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Площадь четырехугольника
float square(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    float c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    float d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
    float p = (a + b + c + d) / 2;
    return sqrt((p - a) * (p - b) * (p - c) * (p - d));
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Вычисление площади круга
    float radius = 5.0;
    float squareCircle = square(radius);
    cout << "Площадь круга с радиусом " << radius << " равна " << squareCircle << endl;

    // Вычисление площади треугольника
    float x1 = 0, y1 = 0;
    float x2 = 3, y2 = 0;
    float x3 = 0, y3 = 4;
    float Squaretriangle = square(x1, y1, x2, y2, x3, y3);
    cout << "Площадь треугольника с координатами (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), и (" << x3 << ", " << y3 << ") равна " << Squaretriangle << endl;

  
    // Вычисление площади четырехугольника
    float x4 = 3, y4 = 4;
    float Squarequadrilateral = square(x1, y1, x2, y2, x3, y3, x4, y4);
    cout << "Площадь четырехугольника с координатами (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << "), и (" << x4 << ", " << y4 << ") равна " << Squarequadrilateral << endl;

    return 0;
}
