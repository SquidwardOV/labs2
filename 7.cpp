#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

bool search(int x[], int size, int k) {

    if (size == 0) {
        return false;
    }


    if (x[0] == k) {
        return true;
    }
    else {
       
        return search(x + 1, size - 1, k);
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    srand(time(0));

   
    int x[10];
    for (int i = 0; i < 10; i++) {
        x[i] = rand() % 100;
    }

   
    cout << "Массив: ";
    for (int i = 0; i < 10; i++) {
        cout << x[i] << " ";
    }
    cout << endl;


    int k = rand() % 100;
    cout << "Ищем число " << k << " в массиве..." << endl;
    if (search(x, 10, k)) {
        cout << "Число найдено!" << endl;
    }
    else {
        cout << "Число не найдено." << endl;
    }

    return 0;
}
