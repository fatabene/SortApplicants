#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Applicant {
    string name;
    string age;
    string email;
    float grade;
    string program;
};

// Jämförelsefunktion för att sortera i stigande ordning efter betyg
bool compareByGrade(const Applicant& a, const Applicant& b) {
    return a.grade > b.grade; // Sortera i stigande ordning efter betyg
}

int main() {
    ifstream myfile("Aplicant.txt");
    vector<Applicant> applicants;

    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            Applicant applicant;
            // Antag att data är separerad med kommatecken och är i följande ordning: name, age, email, grade, program
            size_t pos = line.find(",");
            if (pos != string::npos) {
                applicant.name = line.substr(0, pos);
                line.erase(0, pos + 1);
                pos = line.find(",");
                if (pos != string::npos) {
                    applicant.age = line.substr(0, pos);
                    line.erase(0, pos + 1);
                    pos = line.find(",");
                    if (pos != string::npos) {
                        applicant.email = line.substr(0, pos);
                        line.erase(0, pos + 1);
                        pos = line.find(",");
                        if (pos != string::npos) {
                            applicant.grade = stof(line.substr(0, pos));
                            line.erase(0, pos + 1);
                            applicant.program = line;
                            applicants.push_back(applicant);
                        }
                    }
                }
            }
        }
        myfile.close();

        // Sortera vektorn av sökande efter betyg
        sort(applicants.begin(), applicants.end(), compareByGrade);

        // Skriv över sökande till separata filer baserat på program
        ofstream DTA_file("DTAStudent.txt");        
        ofstream NIT_file("NITStudent.txt");
        int count_DTA = 0;
        int count_NIT = 0;
        if (DTA_file.is_open() && NIT_file.is_open()) {
            for (const auto& applicant : applicants) {
                
                if (applicant.program == "DTA" && count_DTA < 60) {
                    DTA_file << applicant.name << "," << applicant.age << "," << applicant.email << "," << applicant.grade << "," << applicant.program << '\n';
                    count_DTA++;
                    //cout << applicant.name << "," << applicant.age << "," << applicant.email << "," << applicant.grade << "," << applicant.program << '\n';
                }
                
                else if (applicant.program == "NIT" && count_NIT < 85) {
                    NIT_file << applicant.name << "," << applicant.age << "," << applicant.email << "," << applicant.grade << "," << applicant.program << '\n';
                    cout << applicant.name << "," << applicant.age << "," << applicant.email << "," << applicant.grade << "," << applicant.program << '\n';
                    count_NIT++;               
                }
            }
            DTA_file.close();
            NIT_file.close();
        }
        else {
            
            cout << "Could not open DTAStudent.txt or NITStudent.txt\n";
        }
    }
    else {
        cout << "Could not open file\n";
    }

    return 0;
}
