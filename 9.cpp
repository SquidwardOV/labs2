#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int ROWS = 100;
    const int COLS = 100;
    int matrix[ROWS][COLS];


    ifstream input("input.txt");
    if (!input) {
        cout << "Не удалось открыть файл для чтения" << endl;
        return 1;
    }

 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            input >> matrix[i][j];
        }
    }

 
    int m;
    cout << "Введите номер столбца (от 1 до 100): ";
    cin >> m;

    // Создание нового файла для записи
    ofstream output("output.txt");
    if (!output) {
        cout << "Не удалось открыть файл для записи" << endl;
        return 1;
    }

    // Запись данных в новый файл
    for (int i = 0; i < ROWS; i++) {
        output << matrix[i][m - 1] << endl;
    }

    // Закрытие файлов
    input.close();
    output.close();

    return 0;
}
