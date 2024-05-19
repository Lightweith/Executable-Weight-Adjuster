#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void increaseWeight(const string& filePath, int kbToAdd) {
    ifstream file(filePath, ios::binary | ios::ate);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    char* buffer = new char[fileSize];
    file.read(buffer, fileSize);

    file.close();

    ofstream outFile(filePath, ios::binary | ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        delete[] buffer;
        return;
    }

    for (int i = 0; i < kbToAdd * 1024; ++i) {
        outFile << '0';
    }

    outFile.close();

    delete[] buffer;
}

void decreaseWeight(const string& filePath, int kbToSubtract) {
    ifstream file(filePath, ios::binary | ios::ate);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    char* buffer = new char[fileSize];
    file.read(buffer, fileSize);

    file.close();

    ofstream outFile(filePath, ios::binary);
    if (!outFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        delete[] buffer;
        return;
    }

    streampos newSize = fileSize - static_cast<streampos>(kbToSubtract) * 1024;

    for (streampos i = 0; i < newSize; i += 1) {
        outFile << buffer[i];
    }

    outFile.close();

    delete[] buffer;
}

int main() {
    string filePath;
    cout << "Enter the path to the .exe file: ";
    getline(cin, filePath);

    int choice;
    cout << "Choose an action:\n";
    cout << "1. Increase weight\n";
    cout << "2. Decrease weight\n";
    cin >> choice;

    int kbChange;
    cout << "Enter the number of kilobytes to change: ";
    cin >> kbChange;

    if (choice == 1) {
        increaseWeight(filePath, kbChange);
        cout << "File weight increased by " << kbChange << " KB" << endl;
    } else if (choice == 2) {
        decreaseWeight(filePath, kbChange);
        cout << "File weight decreased by " << kbChange << " KB" << endl;
    } else {
        cout << "Invalid action selection!" << endl;
    }

    return 0;
}
