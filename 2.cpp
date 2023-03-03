#include <iostream>
#include <string>
#include <set>

using namespace std;

// Функция для нахождения множества одинаковых букв в двух словах
set<char> findCommonChars(string word1, string word2) {
    set<char> commonChars;

    for (char c : word1) {
        if (word2.find(c) != string::npos) {
            commonChars.insert(c);
        }
    }

    return commonChars;
}

// Функция для нахождения букв, которые встречаются только в одном слове
set<char> findUniqueChars(string word1, string word2) {
    set<char> uniqueChars;

    for (char c : word1) {
        if (word2.find(c) == string::npos) {
            uniqueChars.insert(c);
        }
    }

    for (char c : word2) {
        if (word1.find(c) == string::npos) {
            uniqueChars.insert(c);
        }
    }

    return uniqueChars;
}

int main() {
    string sentence1, sentence2;

    // Ввод двух предложений
    cout << "Введите первое предложение: ";
    getline(cin, sentence1);

    cout << "Введите второе предложение: ";
    getline(cin, sentence2);

    // Разделение предложений на слова
    string word1 = sentence1.substr(0, sentence1.find(' '));
    string word2 = sentence2.substr(0, sentence2.find(' '));
    string lastWord1 = sentence1.substr(sentence1.rfind(' ') + 1);
    string lastWord2 = sentence2.substr(sentence2.rfind(' ') + 1);

    // Нахождение множества одинаковых букв в первых словах
    set<char> commonChars = findCommonChars(word1, word2);

    // Нахождение букв, которые встречаются только в последних словах
    set<char> uniqueChars = findUniqueChars(lastWord1, lastWord2);

    // Вывод результатов
    cout << "Множество одинаковых букв в первых словах: ";
    for (char c : commonChars) {
        cout << c << " ";
    }
    cout << endl;

    cout << "Буквы, которые встречаются только в одном из последних слов: ";
    for (char c : uniqueChars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
