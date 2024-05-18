#pragma once
#include "Command.h"
#include "FileReader.h"
#include <iostream>

using namespace std;

/*!
 * \class CommandReader
 * \brief Reads commands from an input file and validates their format.
 */
class CommandReader : public FileReader {
public:
    /*!
     * \brief Reads a command from the input file, validates its format, and returns a Command object.
     * \return A Command object representing the read command.
     */
    Command readCommand();

    /*!
     * \brief Checks if the given string is a valid integer input.
     * \param a The string to be checked.
     * \return The converted double value if valid, or -1 otherwise.
     */
    double checkInput(string a);

    /*!
     * \brief Checks if the given string is a valid integer input for the last parameter in a command.
     * \param a The string to be checked.
     * \return The converted double value if valid, or -1 otherwise.
     */
    double checkLastInput(string a);
};

