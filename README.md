🔌 # Executable-Weight-Adjuster
 This program allows you to add weight to another program. First, specify the path to your .exe file, then choose to add weight or decrease the weight of the file - you're done! Good luck using the program!
📱 Screenshots
![image](https://github.com/Lightweith/Executable-Weight-Adjuster/assets/170258245/5155d8be-b864-4e8a-8b7e-322999df2151)

❓ # How it Works?
void increaseWeight(const string& filePath, int kbToAdd) {
    // Open the file for reading in binary mode
    ifstream file(filePath, ios::binary | ios::ate);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Get the file size
    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    // Allocate buffer to read the file
    char* buffer = new char[fileSize];
    file.read(buffer, fileSize);

    // Close the file
    file.close();

    // Open the file for writing in append mode
    ofstream outFile(filePath, ios::binary | ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        delete[] buffer;
        return;
    }

    // Add the required number of zero bytes to the end of the file
    for (int i = 0; i < kbToAdd * 1024; ++i) {
        outFile << '0';
    }

    // Close the file
    outFile.close();

    // Free the memory allocated for the buffer
    delete[] buffer;
}

void decreaseWeight(const string& filePath, int kbToSubtract) {
    // Open the file for reading in binary mode
    ifstream file(filePath, ios::binary | ios::ate);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Get the file size
    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);

    // Allocate buffer to read the file
    char* buffer = new char[fileSize];
    file.read(buffer, fileSize);

    // Close the file
    file.close();

    // Open the file for writing in binary mode
    ofstream outFile(filePath, ios::binary);
    if (!outFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        delete[] buffer;
        return;
    }

    // Calculate the new file size after subtraction
    streampos newSize = fileSize - static_cast<streampos>(kbToSubtract) * 1024;

    // Write the file content to a new file without the specified number of kilobytes
    for (streampos i = 0; i < newSize; i += 1) {
        outFile << buffer[i];
    }

    // Close the file
    outFile.close();

    // Free the memory allocated for the buffer
    delete[] buffer;
}
