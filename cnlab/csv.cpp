#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

vector<string> split (const string& s, char delimeter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream, token, delimeter)) {
        if(!token.empty() && token.front() == '"') token.erase(0,1);
        if(!token.empty() && token.back() == '"') token.erase(token.size()-1);
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    ifstream file("./packets2.csv");
    if(!file.is_open()) {
        cerr << "Error: Could not open file" << endl;
        return 1;
    }

    string line;
    bool isHeader = true;

    cout << left << setw(15) << "Source IP" 
         << setw(15) << "Dest IP" 
         << setw(10) << "S-Port" 
         << setw(10) << "D-Port" 
         << "HTTP Info" << endl;
    cout << string(80, '-') << endl;

    while(getline(file, line)) {
        if(line.empty()) continue;

        if(isHeader) {
            isHeader = false;
            continue;
        }

        vector<string> columns = split(line, ',');

        if (columns.size() >= 7) {
            string srcIP = columns[2];
            string destIP = columns[3];
            string info = columns[6];

            cout << left << setw(15) << srcIP 
                    << setw(15) << destIP 
                    << setw(10) << "See Info" 
                    << setw(10) << "See Info" 
                    << info << endl;
        }
    }

    

    file.close();
    return 0;
}