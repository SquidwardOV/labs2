#include <iostream>
#include <string>

const int PROGRAMMER = 0;
const int TESTER = 1;
const int ANALYST = 2;
const int MANAGER = 3;

struct Employee {
    std::string last_name;
    int position;
    int experience;
};

const double SALARY_COEFFICIENT[] = { 0.8, 0.5, 0.4, 1.2 };

int main() {
    const int NUM_EMPLOYEES = 10;
    Employee employees[NUM_EMPLOYEES] = {
        {"Ivanov", PROGRAMMER, 3},
        {"Petrov", PROGRAMMER, 1},
        {"Sidorov", TESTER, 10},
        {"Kuznetsov", TESTER, 5},
        {"Orlov", ANALYST, 4},
        {"Popov", ANALYST, 2},
        {"Fedorov", MANAGER, 6},
        {"Semenov", MANAGER, 3},
        {"Kozlov", PROGRAMMER, 4},
        {"Mironov", TESTER, 15}
    };

    const int NUM_POSITIONS = 4;
    double total_salary[NUM_POSITIONS] = { 0 };
    int num_employees[NUM_POSITIONS] = { 0 };

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        int pos = employees[i].position;
        double salary = 30000 * SALARY_COEFFICIENT[pos];
        total_salary[pos] += salary;
        num_employees[pos]++;
    }

    double avg_salary_all = 0;
    int num_all_employees = 0;
    for (int i = 0; i < NUM_POSITIONS; i++) {
        avg_salary_all += total_salary[i];
        num_all_employees += num_employees[i];
    }
    avg_salary_all /= num_all_employees;

    for (int i = 0; i < NUM_POSITIONS; i++) {
        double max_salary = 0;
        int max_salary_idx = -1;
        for (int j = 0; j < NUM_EMPLOYEES; j++) {
            if (employees[j].position == i) {
                double salary = 30000 * SALARY_COEFFICIENT[i];
                double bonus = avg_salary_all * SALARY_COEFFICIENT[i] * employees[j].experience * 0.05;
                salary += bonus;
                if (salary > max_salary) {
                    max_salary = salary;
                    max_salary_idx = j;
                }
            }
        }
        std::string position;
        if (i == PROGRAMMER) {
            position = "programmer";
        }
        else if (i == TESTER) {
            position = "tester";
        }
        else if (i == ANALYST) {
            position = "analyst";
        }
        else if (i == MANAGER) {
            position = "manager";
        }
        else {
            position = "";
        }
        std::cout << "The highest paid " << position
            << ": " << employees[max_salary_idx].last_name
            << ", salary: " << max_salary
            << ", bonus: " << avg_salary_all * SALARY_COEFFICIENT[i] * employees[max_salary_idx].experience * 0.05 << std::endl;

    }

    return 0;
}
