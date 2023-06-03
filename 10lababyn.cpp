#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

struct FileInfo {
    char filename[10];
    char extension[5];
    char day[4];
    char month[4];
    char year[6];
    char size[14];
};

bool sr(char arr1[3], char arr2[3]) {
    for (int i = 0; i < 3; ++i) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void remove(std::string file_name, std::string file_name_bin) {
    std::ifstream file(file_name, std::ios::binary | std::ios::in);
    std::ofstream file_bin(file_name_bin, std::ios::binary | std::ios::out);
    FileInfo tx;
    if (file.is_open()) {
        while (!file.eof()) {
            file.read((char*)&tx, sizeof(tx));
            file_bin.write((char*)&tx, sizeof(tx));
        }
    }
}
void result(std::string file_name_bin,char base[5]) {
    std::ifstream file_bin(file_name_bin, std::ios::binary | std::ios::in);
    std::ofstream file_result("result.bin", std::ios::binary | std::ios::out);
    FileInfo tx;
    if (file_bin.is_open()) {
        while (!file_bin.eof()) {
            file_bin.read((char*)&tx, sizeof(tx));
            if (sr(base, tx.extension)) {
                file_result.write((char*)&tx, sizeof(tx));
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string file_name = "catalog.txt";
    std::string file_name_bin = "bn.bin";
    char base[5];
    int score = 0;
    FileInfo tx;
    char t;
    std::cout << "Введите нужное разрешение:" << std::endl;
    std::cin >> base;
    base[3] = '\r';
    base[4] = '\n';
    remove(file_name, file_name_bin);
    result(file_name_bin, base);
    std::ifstream file_result("result.bin", std::ios::binary | std::ios::in);
    if (file_result.is_open()) {
        while (!file_result.eof()) {
            file_result.read((char*)&t, sizeof(t));
            std::cout << t;
        }
    }
}
