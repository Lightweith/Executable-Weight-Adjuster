🔌 Executable-Weight-Adjuster


 This program allows you to add weight to another program. First, specify the path to your .exe file, then choose to add weight or decrease the weight of the file - you're done! Good luck using the program!


📱 Screenshots
![image](https://github.com/Lightweith/Executable-Weight-Adjuster/assets/170258245/5155d8be-b864-4e8a-8b7e-322999df2151)



❓ How it Works?


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
