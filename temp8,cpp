#include <iostream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 100;

// Определение типа данных для должности сотрудника
enum Position {
    PROGRAMMER,
    TESTER,
    ANALYST,
    MANAGER
};

// Определение типа данных для сотрудника
struct Employee {
    string lastName;
    Position position;
    int experience;
    double salary;
};

// Функция для вычисления заработной платы сотрудника
double calculateSalary(Position position) {
    switch (position) {
    case PROGRAMMER:
        return 0.8 * 30000;
    case TESTER:
        return 0.5 * 30000;
    case ANALYST:
        return 0.4 * 30000;
    case MANAGER:
        return 1.2 * 30000;
    default:
        return 0;
    }
}

// Функция для вычисления премии сотрудника
double calculateBonus(Employee* employees, int numEmployees, Position position) {
    double totalSalary = 0;
    int count = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].position == position) {
            totalSalary += employees[i].salary;
            count++;
        }
    }
    double avgSalary = totalSalary / count;
    return avgSalary * employees[0].experience * 0.05;
}

// Функция для поиска самого высокооплачиваемого сотрудника для данной должности
Employee findHighestPaidEmployee(Employee* employees, int numEmployees, Position position) {
    Employee highestPaidEmployee;
    double highestSalary = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].position == position && employees[i].salary > highestSalary) {
            highestSalary = employees[i].salary;
            highestPaidEmployee = employees[i];
        }
    }
    return highestPaidEmployee;
}

int main() {
    // Создание списка сотрудников компании
    Employee employees[MAX_EMPLOYEES] = {
        {"Ivanov", PROGRAMMER, 2, calculateSalary(PROGRAMMER)},
        {"Petrov", PROGRAMMER, 5, calculateSalary(PROGRAMMER)},
        {"Sidorov", TESTER, 3, calculateSalary(TESTER)},
        {"Kuznetsov", ANALYST, 1, calculateSalary(ANALYST)},
        {"Smirnov", ANALYST, 4, calculateSalary(ANALYST)},
        {"Fedorov", MANAGER, 7, calculateSalary(MANAGER)},
        {"Popov", MANAGER, 3, calculateSalary(MANAGER)}
    };

    int numEmployees = 7;

    // Вывод информации о самом высокооплачиваемом сотруднике каждой должности
    cout << "Highest paid employees by position:" << endl;
    for (int i = 0; i < 4; i++) {
        Position position = static_cast<Position>(i);
        Employee highestPaidEmployee = findHighestPaidEmployee(employees, numEmployees, position);
        double bonus = calculateBonus(employees, numEmployees, position);
        cout << "Position: ";
        switch (position) {
        case PROGRAMMER:
            cout << "Programmer";
            break;
        case TESTER:
            cout << "Tester";
            break;
        case ANALYST:
            cout << "Analyst";
            break;
        case MANAGER:
            cout << "Manager";
            break;
        default:
            cout << "Unknown";
        }
        cout << endl;
        cout << "Last name: " << highestPaidEmployee.lastName << endl;
        cout << "Salary: " << highestPaidEmployee.salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << endl;
    }

    return 0;
}
