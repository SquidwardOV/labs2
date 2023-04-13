#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

enum Position { Программист, Тестировщик, Аналитик, Менеджер };

struct Employee {
    string surname;
    Position position;
    int experience;
    float zp;
    float premiya;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 4; // количество должностей
    const float coeffs[n] = { 0.8, 0.5, 0.4, 1.2 }; // коэффициенты зарплат для каждой должности

    const int m = 9; // количество сотрудников

    Employee employees[m] = {
        {"Иванов", Программист, 5, 0, 0},
        {"Кручинин", Тестировщик, 3, 0, 0},
        {"Михалёв", Аналитик, 4, 0, 0},
        {"Колобов", Менеджер, 10, 0, 0},
        {"Кузнечиков", Программист, 2, 0, 0},
        {"Евстигнеев", Программист, 6, 0, 0},
        {"Смирнов", Менеджер, 1, 0, 0},
        {"Мазур", Аналитик, 7, 0, 0},
        {"Евстигнеев", Тестировщик, 6, 0, 0},
    };

    // вычисление зарплаты и премии для каждого сотрудника
    for (int i = 0; i < m; i++) {
        float zp = 30000 * coeffs[0];
        float premiya = 0;
        switch (employees[i].position) {
        case Программист:
            zp *= coeffs[0];
            break;
        case Тестировщик:
            zp *= coeffs[1];
            break;
        case Аналитик:
            zp *= coeffs[2];
            break;
        case Менеджер:
            zp *= coeffs[3];
            break;
        }
        premiya = (zp + premiya) * employees[i].experience * 0.05;
        employees[i].zp = zp;
        employees[i].premiya = premiya;
    }

    // поиск лучших сотрудников для каждой должности
    Employee best[n];
    for (int i = 0; i < n; i++) {
        best[i].zp = -1;
    }
    for (int i = 0; i < m; i++) {
        int index = -1;
        switch (employees[i].position) {
        case Программист:
            index = 0;
            break;
        case Тестировщик:
            index = 1;
            break;
        case Аналитик:
            index = 2;
            break;
        case Менеджер:
            index = 3;
            break;
        }
        if (employees[i].zp > best[index].zp) {
            best[index] = employees[i];
        }
    }

    // вывод результатов
    cout << "Наиболее высокооплачиваемый программист: ";
    cout << best[Программист].surname << " (зарплата = " << best[Программист].zp << "руб., премия = " << best[Программист].premiya << "руб.)" << endl;
    cout << "Наиболее высокооплачиваемый тестировщик: ";
    cout << best[Тестировщик].surname << " (зарплата = " << best[Тестировщик].zp <<
        "руб., премия = " << best[Тестировщик].premiya << "руб.)" << endl;

    cout << "Наиболее высокооплачиваемый аналитик: ";
    cout << best[Аналитик].surname << " (зарплата = " << best[Аналитик].zp <<
        "руб., премия = " << best[Аналитик].premiya << "руб.)" << endl;

    cout << "Наиболее высокооплачиваемый менеджер: ";
    cout << best[Менеджер].surname << " (зарплата = " << best[Менеджер].zp <<
        "руб., премия = " << best[Менеджер].premiya << "руб.)" << endl;

    return 0;
}
