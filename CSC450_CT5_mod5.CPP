Please be sure to append your data to this text file.

If these first three lines are deleted, then your program is not functioning as expected.


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// reverse function
string reverseString(const string& str) {
    return string(str.rbegin(), str.rend());
}

int main() {
    string userInput;
    const string inputFile = "CSC450_CT5_mod5.txt";
    const string outputFile = "CSC450-mod5-reverse.txt";
    
    // input
    cout << "Enter text to append to the file: ";
    getline(cin, userInput);
    
    // append
    ofstream fileAppend(inputFile, ios::app);
    if (!fileAppend) {
        cerr << "Error opening file for appending!" << endl;
        return 1;
    }
    fileAppend << userInput << endl;
    fileAppend.close();
    
    // read
    ifstream fileRead(inputFile);
    if (!fileRead) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    
    string fileContent;
    string line;
    while (getline(fileRead, line)) {
        fileContent += line + "\n";
    }
    fileRead.close();
    
    // reverse
    string reversedContent = reverseString(fileContent);
    
    // write new content
    ofstream fileReverse(outputFile);
    if (!fileReverse) {
        cerr << "Error opening reverse file for writing!" << endl;
        return 1;
    }
    fileReverse << reversedContent;
    fileReverse.close();
    
    cout << "Operations completed successfully!" << endl;
    cout << "1. Original text appended to: " << inputFile << endl;
    cout << "2. Reversed text written to: " << outputFile << endl;
    
    return 0;
}
