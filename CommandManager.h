#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "CommandReader.h"
#include "Command.h"
#include "FileWriter.h"
#include "Simulation.h"
#include "TankManager.h"
#include <list>
using namespace std;

class Simulation;
class CommandReader;
class FileWriter;
class TankManager;

/*!
 * \class CommandManager
 * \brief Manages a list of commands and coordinates their execution.
 */
class CommandManager {
    /*! List to store the commands received by the CommandManager. */
    list<Command> commandList; 

public:
    /*!
     * \brief Manages the execution of commands based on their types and parameters.
     * \param cr Pointer to the CommandReader for reading commands.
     * \param s Pointer to the Simulation for managing simulation actions.
     * \param fw Pointer to the FileWriter for writing output.
     * \param tm Pointer to the TankManager for managing fuel tanks and engine.
     * \param eng Pointer to the Engine for coordinating engine-related actions.
     */
    void manageCommand(CommandReader* cr, Simulation* s, FileWriter* fw, TankManager* tm, Engine* eng);
};

