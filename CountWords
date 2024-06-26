#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <sstream>

using namespace std;

void setWesternEuropeanCodePage() {
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
}

int main() {
    setWesternEuropeanCodePage();
    string filename;
    cout << "File to open: ";
    cin >> filename;

    ifstream myfile(filename);
    if (!myfile.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    int paragraphNumber = 1;
    int wordCount = 0;

    while (getline(myfile, line)) {
        if (line.empty()) {
            if (wordCount > 0) {
                cout << "Stycke " << paragraphNumber << " har " << wordCount << " ord." << endl;
                paragraphNumber++;
                wordCount = 0; // reset word count for the next paragraph
            }
        }
        else {
            stringstream ss(line);
            string word;
            while (ss >> word) {
                wordCount++;
            }
        }
    }

    // To print the last paragraph if file does not end with an empty line
    if (wordCount > 0) {
        cout << "Stycke " << paragraphNumber << " har " << wordCount << " ord." << endl;
    }

    myfile.close();
    return 0;
}
