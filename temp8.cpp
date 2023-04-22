#include <iostream>
#include <string>
#include <windows.h>

const int programmer = 0;
const int tester = 1;
const int analyst = 2;
const int manager = 3;

struct Employee {
    std::string surname;
    int position;
    int experience;
};

const double zp_coef[] = { 0.8, 0.5, 0.4, 1.2 };

int main() {
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int NUM_EMPLOYEES = 10;
    Employee employees[NUM_EMPLOYEES] = {
        {"Иванов", programmer, 3},
        {"Петров", programmer, 3},
        {"Сидоров", tester, 10},
        {"Кузнецов", tester, 5},
        {"Орлов", analyst, 4},
        {"Попов", analyst, 2},
        {"Фёдоров", manager, 6},
        {"Семёнов", manager, 3},
        {"Козлов", programmer, 2},
        {"Миронов", tester, 15}
    };

    const int num_pos = 4;
    double sumzp[num_pos] = { 0 };
    int num_employees[num_pos] = { 0 };

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        int pos = employees[i].position;
        double zp = 30000 * zp_coef[pos];
        sumzp[pos] += zp;
        num_employees[pos]++;
    }

    double srednzp = 0;
    int num_all_employees = 0;
    for (int i = 0; i < num_pos; i++) {
        srednzp += sumzp[i];
        num_all_employees += num_employees[i];
    }
    srednzp /= num_all_employees;

    for (int i = 0; i < num_pos; i++) {
        double maxzp = 0;
        int maxzp_idx = -1;
        for (int j = 0; j < NUM_EMPLOYEES; j++) {
            if (employees[j].position == i) {
                double salary = 30000 * zp_coef[i];
                double premia = srednzp * zp_coef[i] * employees[j].experience * 0.05;
                salary += premia;
                if (salary > maxzp) {
                    maxzp = salary;
                    maxzp_idx = j;
                }
            }
        }
        std::string position;
        if (i == programmer) {
            position = "программист";
        }
        else if (i == tester) {
            position = "тестировщик";
        }
        else if (i == analyst) {
            position = "аналитик";
        }
        else if (i == manager) {
            position = "менеджер";
        }
        else {
            position = "";
        }
        std::cout << "Самый высокооплачиваемый " << position
            << ": " << employees[maxzp_idx].surname
            << ", зарплата: " << maxzp
            << ", премия: " << srednzp * zp_coef[i] * employees[maxzp_idx].experience * 0.05 << std::endl;

    }

    return 0;
}
