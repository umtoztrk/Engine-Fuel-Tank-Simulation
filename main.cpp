#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "CommandManager.h"
#include "Simulation.h"
#include "TankManager.h"
#include "FileWriter.h"
#include "FileReader.h"
#include "CommandReader.h"
#include <clocale>
#include "FuelTank.h"
#include "Engine.h"

using namespace std;

/*! Create readFile to read command from input file*/
Engine* Engine::instance = nullptr;

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    Engine* engine = Engine::getInstance();
    Simulation* s = new Simulation();
    TankManager* tm = new TankManager();
    FileWriter* fw = new FileWriter();
    CommandReader* cr = new CommandReader();
    CommandManager* cm = new CommandManager();
    cm->manageCommand(cr, s, fw, tm,engine);
    return 0;
}