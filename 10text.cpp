#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct FileInfo {
    string filename;
    string extension;
    int day;
    int month;
    int year;
    int size;
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
    while (infile >> fileinfo.filename >> fileinfo.extension >> fileinfo.day 
           >> fileinfo.month >> fileinfo.year >> fileinfo.size) {
        if (fileinfo.extension == extension) {
            outfile << fileinfo.filename << " " << fileinfo.extension << " "
                    << fileinfo.day << "." << fileinfo.month << "." 
                    << fileinfo.year << " " << fileinfo.size << endl;
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
