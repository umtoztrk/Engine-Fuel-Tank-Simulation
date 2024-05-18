#include "FileReader.h"

using namespace std;

FileReader::FileReader() {
    /*! Prompt the user to enter the file name. */
    cout << "Enter file name: ";
    cin >> filePath;
    system("cls");  /*! Clear the console screen.*/

    /*! Open the input file using the provided file path. */
    input.open(filePath);

    /*! Check if files are opened successfully. */
    if (!input.is_open()) {
        cerr << "Error opening files!" << endl;
        return;
    }
}

string FileReader::readLine() {
    /*! Read a line from the input file.
        \return The read line as a string.
    */
    while (getline(input, command)) {
        return command;
    }
    return "finish";  /*! Return "finish" if the end of the file is reached. */
}
