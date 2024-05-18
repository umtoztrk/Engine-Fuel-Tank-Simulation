#pragma once
#include "FileOperator.h"

using namespace std;

class FileReader : public FileOperator {
protected:
    /*! Input file stream for reading from a file. */
    ifstream input; 
    /*! String to store the read command line from the file. */
    string command; 

public:
    /*! Constructor for FileReader. Asks the user for the file name, opens the input file, and initializes the stream. */
    FileReader();

    /*! Read a line from the input file.
        \return A string containing the read line from the file.
    */
    string readLine();
};

