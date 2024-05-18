#include "CommandReader.h"
#include <string>
#include <sstream>

using namespace std;

double CommandReader::checkLastInput(string a) {
    /*! Check if the last input is a valid positive integer or a semicolon.
        \param a The string to be checked.
        \return If valid, return the converted double value; otherwise, return -1.
    */
    for (int i = 0; i < a.length(); i++) {
        if ((!isdigit(a[i]) && a[i] != ';') || (a[i] == ';' && i != a.length() - 1)) {
            return -1;
        }
    }
    /*! Convert the input string to a double; if it's zero, return -1 */
    double value = stoi(a);
    if (value == 0) return -1;
    return value;
}

double CommandReader::checkInput(string a) {
    /*! Check if the input is a valid positive integer.
        \param a The string to be checked.
        \return If valid, return the converted double value; otherwise, return -1.
    */
    for (int i = 0; i < a.length(); i++) {
        if (!isdigit(a[i])) {
            return -1;
        }
    }
    /*! Convert the input string to a double; if it's zero, return -1 */
    double value = stoi(a);
    if (value == 0) return -1;
    return value;
}

Command CommandReader::readCommand() {
    /*! Read a command from the input and parse it into a Command object.
        \return The Command object representing the parsed command.
    */
    string commandLine = readLine();
    int spaceCount = 0;
    for (char character : commandLine) {
        if (character == ' ') {
            spaceCount++;
        }
    }
    string com;
    Command comm;
    istringstream stream(commandLine);
    int flag = 0;
    double checkLastInt, checkInt;
    for (int i = 0; i <= spaceCount; i++) {
        stream >> com;
        if (i == 0) comm.setCommand(com);
        else if (spaceCount == 1 && i == 1) {
            checkLastInt = checkLastInput(com);
            comm.setParameters(checkLastInt);
        }
        else {
            if ((i != spaceCount && i >= 1)) {
                checkInt = checkInput(com);
                comm.setParameters(checkInt);
            }
            else {
                checkLastInt = checkLastInput(com);
                comm.setParameters(checkLastInt);
            }
        }
    }
    return comm;
}
