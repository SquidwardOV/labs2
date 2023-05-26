#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

void remove(std::string file_name, std::string file_name_bin) {
	std::ifstream file(file_name, std::ios::binary | std::ios::in);
	std::ofstream file_bin(file_name_bin, std::ios::binary | std::ios::out);
	char tx;
	if (file.is_open()) {
		while (!file.eof()) {
			file.read((char*)&tx, sizeof(tx));
			file_bin.write((char*)&tx, sizeof(tx));
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string file_name = "catalog.txt";
	std::string file_name_bin = "bn.bin";
	std::string text;
	std::string* arr = new std::string[6];
	std::string base;
	int score = 0;
	char tx;
	std::cout << "Введите нужное разрешение:" << std::endl;
	std::cin >> base;
	remove(file_name, file_name_bin);
	std::ifstream file_bin(file_name_bin, std::ios::binary | std::ios::in);
	std::ofstream file_result("result.bin", std::ios::binary | std::ios::out);
	if (file_bin.is_open()) {
		while (!file_bin.eof()) {
			file_bin.read((char*)&tx, sizeof(tx));
			if (tx != '\n') {
				text += tx;
			}
			else {
				arr[score] = text;
				text = "";
				score++;
			}
			if (score == 6) {
				if (arr[1] == base + "\r") {
					std::cout << "\n";
					for (int i = 0; i < 6; ++i) {
						std::cout << arr[i] << std::endl;
						for (int j = 0; j < arr[i].size(); ++j) {
							file_result.write((char*)&arr[i][j], sizeof(arr[i][j]));
						}
					}
					score = 0;
				}
				else {
					score = 0;
				}
			}
		}
	}
	delete[]arr;
}
