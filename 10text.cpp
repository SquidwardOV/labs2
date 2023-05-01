#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct FileInfo {
    string filename;
    string extension;
    string day;
    string month;
    string year;
    string size;
};

const string INPUT_FILE = "catalog.txt";
const string OUTPUT_FILE = "result.txt";

int main() {
    string extension;
    cout << "Enter the extension of the files you want to find: ";
    cin >> extension;

    ifstream infile(INPUT_FILE);
    ofstream outfile(OUTPUT_FILE);

    if (!infile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }
    if (!outfile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    FileInfo fileinfo;
    while (!infile.eof()) {
        getline(infile, fileinfo.filename);
        getline(infile, fileinfo.extension);
        getline(infile, fileinfo.day);
        getline(infile, fileinfo.month);
        getline(infile, fileinfo.year);
        getline(infile, fileinfo.size);
        if (fileinfo.extension == extension) {
            outfile << fileinfo.filename << " " << fileinfo.extension << " " << fileinfo.day << "." << fileinfo.month << "." << fileinfo.year << " " << fileinfo.size << endl;
        }

    }
}
