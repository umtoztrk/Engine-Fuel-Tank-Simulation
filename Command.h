#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

class Command {
private:
    /*! The main command string. */
    string command;         
    /*! List of parameters associated with the command. */
    list<int> parameters;     

public:
    /*! Set the main command string.
        \param _command The string representing the main command.
    */
    void setCommand(string _command) {
        command = _command;
    }

    /*! Add a parameter to the list of parameters.
        \param i The integer parameter to be added to the list.
    */
    void setParameters(int i) {
        parameters.push_back(i);
    }

    /*! Get the main command string.
        \return The string representing the main command.
    */
    string getCommand() const {
        return command;
    }

    /*! Get the list of parameters associated with the command.
        \return List of integers representing the parameters.
    */
    list<int> getParameters() {
        return parameters;
    }
};
