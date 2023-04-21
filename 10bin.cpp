#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct FileInfo {
    char filename[9];
    char extension[4];
    int day;
    int month;
    int year;
    int size;
};

const string INPUT_FILE = "catalog.dat";
const string OUTPUT_FILE = "result.dat";

int main() {
    string extension;
    cout << "Enter the extension of the files you want to find: ";
    cin >> extension;

    ifstream infile(INPUT_FILE, ios::binary);
    ofstream outfile(OUTPUT_FILE, ios::binary);

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    FileInfo fileinfo;
    while (infile.read(reinterpret_cast<char*>(&fileinfo), sizeof(fileinfo))) {
        if (string(fileinfo.extension) == extension) {
            outfile.write(reinterpret_cast<char*>(&fileinfo), sizeof(fileinfo));
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
