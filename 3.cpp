#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

// Функция для определения буквенного состава слова
vector<char> get_letters(string word) {
    vector<char> letters;
    for (char c : word) {
        if (isalpha(c)) { // Если символ является буквой
            c = tolower(c); // Приводим его к нижнему регистру
            if (find(letters.begin(), letters.end(), c) == letters.end()) { // Если такой буквы еще нет в векторе
                letters.push_back(c); // Добавляем ее
            }
        }
    }
    return letters;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    string sentence1, sentence2;
    getline(cin, sentence1); // Считываем первое предложение
    getline(cin, sentence2); // Считываем второе предложение

    // Разбиваем предложения на слова
    vector<string> words1, words2;
    size_t pos1 = 0, pos2 = 0;
    while ((pos1 = sentence1.find(' ', pos1)) != string::npos) {
        words1.push_back(sentence1.substr(pos2, pos1 - pos2));
        pos2 = ++pos1;
    }
    words1.push_back(sentence1.substr(pos2));
    pos1 = pos2 = 0;
    while ((pos1 = sentence2.find(' ', pos1)) != string::npos) {
        words2.push_back(sentence2.substr(pos2, pos1 - pos2));
        pos2 = ++pos1;
    }
    words2.push_back(sentence2.substr(pos2));

    // Определяем множество одинаковых букв для первых слов
    vector<char> common_letters;
    vector<char> letters1 = get_letters(words1[0]);
    vector<char> letters2 = get_letters(words2[0]);
    for (char c : letters1) {
        if (find(letters2.begin(), letters2.end(), c) != letters2.end() && find(common_letters.begin(), common_letters.end(), c) == common_letters.end()) {
            common_letters.push_back(c);
        }
    }

    // Определяем буквы, которые встречаются только в одном из последних слов
    vector<char> unique_letters;
    letters1 = get_letters(words1.back());
    letters2 = get_letters(words2.back());
    for (char c : letters1) {
        if (find(letters2.begin(), letters2.end(), c) == letters2.end() && find(unique_letters.begin(), unique_letters.end(), c) == unique_letters.end()) {
            unique_letters.push_back(c);
        }
    }
    for (char c : letters2) {
        if (find(letters1.begin(), letters1.end(), c) == letters1.end() && find(unique_letters.begin(), unique_letters.end(), c) == unique_letters.end()) {
            unique_letters.push_back(c);
        }
    }

    // Выводим результаты
    cout << "Одинаковые буквы в первых словах:";
    for (char c : common_letters) {
        cout << " " << c;
    }
    cout << endl;

    cout << "Уникальные буквы в последних словах:" << endl;
    for (char c : unique_letters) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
