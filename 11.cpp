#include <iostream>
#include <string>
#include <windows.h>

enum Position { PROGRAMMER, TESTER, ANALYST, MANAGER };

struct Employee {
    std::string last_name;
    Position position;
    int experience;
};

const double SALARY_COEFFICIENT[] = { 0.8, 0.5, 0.4, 1.2 };

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int NUM_EMPLOYEES = 10;
    Employee employees[NUM_EMPLOYEES] = {
        {"Иванов", PROGRAMMER, 13},
        {"Петров", PROGRAMMER, 13},
        {"Сидоров", TESTER, 10},
        {"Кузнецов", TESTER, 5},
        {"Орлов", ANALYST, 4},
        {"Попов", ANALYST, 2},
        {"Фёдоров", MANAGER, 6},
        {"Семёнов", MANAGER, 3},
        {"Козлов", PROGRAMMER, 4},
        {"Миронов", TESTER, 15}
    };

    const int NUM_POSITIONS = 4;
    double sumzp[NUM_POSITIONS] = { 0 };
    int num_employees[NUM_POSITIONS] = { 0 };

    // Общая зарплата для каждой должности
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        int pos = employees[i].position;
        double zp = 30000 * SALARY_COEFFICIENT[pos];
        sumzp[pos] += zp;
        num_employees[pos]++;
    }

    //Средняя зарплата сотрудников всех отделов
    double srednzp = 0;
    int num_all_employees = 0;
    for (int i = 0; i < NUM_POSITIONS; i++) {
        srednzp += sumzp[i];
        num_all_employees += num_employees[i];
    }
    srednzp /= num_all_employees;

    // Вывод самого высокооплачиваемого сотрудника для каждой должности
    for (int i = 0; i < NUM_POSITIONS; i++) {
        double maxzp = 0;
        int maxzp_idx[NUM_EMPLOYEES] = { -1 };
        int num_maxzp = 0;
        for (int j = 0; j < NUM_EMPLOYEES; j++) {
            if (employees[j].position == i) {
                double salary = 30000 * SALARY_COEFFICIENT[i];
                double premia = srednzp * SALARY_COEFFICIENT[i] * employees[j].experience * 0.05;
                salary += premia;
                if (salary > maxzp) {
                    maxzp = salary;
                    num_maxzp = 0;
                    maxzp_idx[num_maxzp++] = j;
                }
                else if (salary == maxzp) {
                    maxzp_idx[num_maxzp++] = j;
                }
            }
        }
        std::string position;
        if (i == PROGRAMMER) {
            position = "программист";
        }
        else if (i == TESTER) {
            position = "тестировщик";
        }
        else if (i == ANALYST) {
            position = "аналитик";
        }
        else if (i == MANAGER) {
            position = "менеджер";
        }
        std::cout << "Самый высокооплачиваемый " << position << ": \n";
        for (int k = 0; k < num_maxzp; k++) {
            std::cout << employees[maxzp_idx[k]].last_name << " - ";
            double salary = 30000 * SALARY_COEFFICIENT[i];
            double premia = srednzp * SALARY_COEFFICIENT[i] * employees[maxzp_idx[k]].experience * 0.05;
            salary += premia;
            std::cout << "зарплата " << salary << " руб. (премия " << premia << " руб.)";
        }
        std::cout << "\n";
    }
}
