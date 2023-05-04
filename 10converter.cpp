#include <iostream>
#include <fstream>

int main() {
   
    std::ifstream input_file("catalog.txt");
    if (!input_file.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return 1;
    }

   
    std::ofstream output_file("catalog.bin", std::ios::binary);
    if (!output_file.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return 1;
    }

    // Читаем из текстового файла и записываем в бинарный
    char c;
    while (input_file.get(c)) {
        output_file.write(&c, sizeof(c));
    }

    
    input_file.close();
    output_file.close();

    std::cout << "Конвертация завершена!" << std::endl;
    return 0;
}
