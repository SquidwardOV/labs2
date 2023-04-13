#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

struct Employee {
    string surname;
    string position;
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
        

        {"Иванов", "Программист", 5, 0, 0},
        {"Кручинин", "Тестировщик", 3, 0, 0},
        {"Михалёв", "Аналитик", 4, 0, 0},
        {"Колобов", "Менеджер", 10, 0, 0},
        {"Кузнечиков", "Программист", 2, 0, 0},
        {"Евстигнеев", "Программист", 6, 0, 0},
        {"Межцев", "Менеджер", 1, 0, 0},
        {"Мазур", "Аналитик", 7, 0, 0},
        {"Курбатов", "Тестировщик", 6, 0, 0},
    };

    // вычисление зарплаты и премии для каждого сотрудника
    for (int i = 0; i < m; i++) {
        float zp = 30000 * coeffs[0]; 
        float premiya = 0; 
        if (employees[i].position == "Программист") {
            zp *= coeffs[0]; 
            premiya = (zp + premiya) * employees[i].experience * 0.05; 
        }
        else if (employees[i].position == "Тестировщик") {
            zp *= coeffs[1]; 
            premiya = (zp + premiya) * employees[i].experience * 0.05; 
        }
        else if (employees[i].position == "Аналитик") {
            zp *= coeffs[2]; 
            premiya = (zp + premiya) * employees[i].experience * 0.05; 
        }
        else if (employees[i].position == "Менеджер") {
            zp *= coeffs[3]; 
            premiya = (zp + premiya) * employees[i].experience * 0.05; 
        }
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
        if (employees[i].position == "Программист") {
            index = 0;
        }
        else if (employees[i].position == "Тестировщик") {
            index = 1;
        }
        else if (employees[i].position == "Аналитик") {
            index = 2;
        }
        else if (employees[i].position == "Менеджер") {
            index = 3;
        }
        if (employees[i].zp > best[index].zp) {
            best[index] = employees[i];
        }
    }

    // вывод результатов
    cout << "Наиболее высокооплачиваемый программист: ";
    cout << best[0].surname << " (зарплата = " << best[0].zp << ", премия = " << best[0].premiya << ")" << endl;

    cout << "Наиболее высокооплачиваемый тестировщик: ";
    cout << best[1].surname << " (зарплата = " << best[1].zp << ", премия = " << best[1].premiya << ")" << endl;

    cout << "Наиболее высокооплачиваемый аналитик: ";
    cout << best[2].surname << " (зарплата = " << best[2].zp << ", премия = " << best[2].premiya << ")" << endl;

    cout << "Наиболее высокооплачиваемый менеджер: ";
    cout << best[3].surname << " (зарплата = " << best[3].zp << ", премия = " << best[3].premiya << ")" << endl;



}
