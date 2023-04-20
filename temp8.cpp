#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    string surname;
    int experience;
    int position;
    double salary;
};

void calculateSalary(Employee& emp) {
    double coefficient;
    switch (emp.position) {
    case 1: coefficient = 0.8; break;
    case 2: coefficient = 0.5; break;
    case 3: coefficient = 0.4; break;
    case 4: coefficient = 1.2; break;
    default: coefficient = 1.0;
    }
    emp.salary = 30000 * coefficient;
}

void calculateBonus(Employee& emp, Employee* employees, int numEmployees) {
    double totalSalary = 0.0;
    int numWorkers = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].position == emp.position) {
            totalSalary += employees[i].salary;
            numWorkers++;
        }
    }
    double averageSalary = totalSalary / numWorkers;
    emp.salary += averageSalary * emp.experience * 0.05;
}

void printHighestPaid(Employee* employees, int numEmployees, int position) {
    double highestSalary = 0.0;
    double highestBonus = 0.0;
    string highestSurname = "";
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].position == position && employees[i].salary > highestSalary) {
            highestSalary = employees[i].salary;
            highestBonus = employees[i].salary * employees[i].experience * 0.05;
            highestSurname = employees[i].surname;
        }
    }
    cout << "Highest paid " << (position == 1 ? "programmer" : (position == 2 ? "tester" : (position == 3 ? "analyst" : "manager")))
        << ": " << highestSurname << " (salary: " << highestSalary << " rubles, bonus: " << highestBonus << " rubles)" << endl;
}


int main() {
    Employee employees[MAX_EMPLOYEES] = {
        {"Ivanov", 3, 1, 0.0},
        {"Petrov", 5, 1, 0.0},
        {"Sidorov", 2, 2, 0.0},
        {"Smirnov", 4, 2, 0.0},
        {"Kuznetsov", 1, 3, 0.0},
        {"Popov", 3, 3, 0.0},
        {"Vasilyev", 2, 4, 0.0},
        {"Goncharov", 6, 4, 0.0}
    };
    int numEmployees = sizeof(employees) / sizeof(Employee);
    for (int i = 0; i < numEmployees; i++) {
        calculateSalary(employees[i]);
        calculateBonus(employees[i], employees, numEmployees);
    }
    printHighestPaid(employees, numEmployees, 1);
    printHighestPaid(employees, numEmployees, 2);
    printHighestPaid(employees, numEmployees, 3);
    printHighestPaid(employees, numEmployees, 4);
    return 0;
}

