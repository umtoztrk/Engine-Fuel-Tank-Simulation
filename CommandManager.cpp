#include "CommandManager.h"

/*!
    This function manages incoming commands.
    \param cr CommandReader object for reading commands.
    \param s Simulation object for controlling the simulation.
    \param fw FileWriter object for writing outputs to a file.
    \param tm TankManager object for managing tanks.
    \param eng Engine object representing the motor.
*/
void CommandManager::manageCommand(CommandReader* cr, Simulation* s, FileWriter* fw, TankManager* tm, Engine* eng) {
    while (1) {
        /*! Add commands to the list */
        commandList.push_back(cr->readCommand());

        /*!
            Check the start engine command.
            The "start_engine;" command should have no parameters and the engine should be connected.
        */
        if (commandList.back().getCommand() == "start_engine;" && commandList.back().getParameters().size() == 0 && tm->getEngine()->getConnection()) {
            if (tm->getEngine()->getStatus()) {
                fw->alreadyStarted();
                continue;
            }
            // Start the engine
            s->startEngine(tm);
            tm->consumeFuel(1);
            fw->startEngine();
        }
        /*!
            Check the stop engine command.
            The "stop_engine;" command should have no parameters and the engine should be running.
        */
        else if (commandList.back().getCommand() == "stop_engine;" && commandList.back().getParameters().size() == 0 && tm->getEngine()->getStatus()) {
            tm->consumeFuel(1);
            // Stop the engine
            s->stopEngine(tm);
            fw->stopEngine();
        }
        /*!
            Check the stop simulation command.
            The "stop_simulation;" command should have no parameters.
        */
        else if (commandList.back().getCommand() == "stop_simulation;" && commandList.back().getParameters().size() == 0) {
            fw->stopSimulation();
            s->stopSimulation();
        }
        /*!
            Check the give back fuel command.
            The "give_back_fuel" command should have one parameter and the engine should be connected and running.
        */
        else if (commandList.back().getCommand() == "give_back_fuel" && commandList.back().getParameters().size() == 1 && tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
            double doubleNumber = static_cast<double>(commandList.back().getParameters().back());
            if (doubleNumber > *(eng->getIntTank()->getQuantity())) {
                fw->error();
                continue;
            }
            tm->consumeFuel(1);
            tm->giveBackFuel(commandList.back().getParameters().front());
            fw->giveBackFuel();
        }
        /*!
            Check the add fuel tank command.
            The "add_fuel_tank" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "add_fuel_tank" && commandList.back().getParameters().size() == 1) {
            tm->addFuelTank(commandList.back().getParameters().front());
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->addFuelTank();
        }
        /*!
            Check the list fuel tanks command.
            The "list_fuel_tanks;" command should have no parameters.
        */
        else if (commandList.back().getCommand() == "list_fuel_tanks;" && commandList.back().getParameters().size() == 0) {
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->listFuelTanks();
        }
        /*!
            Check the print fuel tank count command.
            The "print_fuel_tank_count;" command should have no parameters.
        */
        else if (commandList.back().getCommand() == "print_fuel_tank_count;" && commandList.back().getParameters().size() == 0) {
            tm->printFuelTankCount();
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->printFuelTankCount();
        }
        /*!
            Check the connect fuel tank to engine command.
            The "connect_fuel_tank_to_engine" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "connect_fuel_tank_to_engine" && commandList.back().getParameters().size() == 1) {
            if ((!tm->getTanks()[commandList.back().getParameters().front() - 1].getIsDeleted()) &&
                (!tm->getTanks()[commandList.back().getParameters().front() - 1].getConnection()) &&
                (tm->getTanks()[commandList.back().getParameters().front() - 1].getValve()->getStatus())) {
                tm->connectFuelTankToEngine(commandList.back().getParameters().front());
                fw->connectTankToEngine();
            }
            else {
                fw->error();
            }
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
        }
        /*!
            Check the disconnect fuel tank from engine command.
            The "disconnect_fuel_tank_from_engine" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "disconnect_fuel_tank_from_engine" && commandList.back().getParameters().size() == 1) {
            if ((!tm->getTanks()[commandList.back().getParameters().front() - 1].getIsDeleted()) &&
                (tm->getTanks()[commandList.back().getParameters().front() - 1].getConnection()) &&
                (tm->getTanks()[commandList.back().getParameters().front() - 1].getValve()->getStatus())) {
                tm->disconnectFuelTankFromEngine(commandList.back().getParameters().front());
                fw->disconnectTankToEngine();
            }
            else {
                fw->error();
            }
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
        }
        /*!
            Check the list connected tanks command.
            The "list_connected_tanks;" command should have no parameters.
        */
        else if (commandList.back().getCommand() == "list_connected_tanks;" && commandList.back().getParameters().size() == 0) {
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->listConnectedTanks(tm);
        }
        /*!
            Check the print total fuel quantity command.
            The "print_total_fuel_quantity;" command should have no parameters.
        */
        else if (commandList.back().getCommand() == "print_total_fuel_quantity;" && commandList.back().getParameters().size() == 0) {
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->printTotalFuelQuantity(tm);
        }
        /*!
            Check the print total consumed fuel quantity command.
            The "print_total_consumed_fuel_quantity;" command should have no parameters.
        */
        else if (commandList.back().getCommand() == "print_total_consumed_fuel_quantity;" && commandList.back().getParameters().size() == 0) {
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->printTotalConsumedFuelQuantity(tm);
        }
        /*!
            Check the print tank info command.
            The "print_tank_info" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "print_tank_info" && commandList.back().getParameters().size() == 1) {
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->printTankInfo(tm, commandList.back().getParameters().front());
        }
        /*!
            Check the fill tank command.
            The "fill_tank" command should have two parameters.
        */
        else if (commandList.back().getCommand() == "fill_tank" && commandList.back().getParameters().size() == 2 &&
            commandList.back().getParameters().front() <= tm->getTanks().size() && commandList.back().getParameters().front() != 0) {
            tm->fillTank(commandList.back().getParameters().front(), commandList.back().getParameters().back());
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->fillTank();
        }
        /*!
            Check the remove fuel tank command.
            The "remove_fuel_tank" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "remove_fuel_tank" && commandList.back().getParameters().size() == 1) {
            tm->removeFuelTank(commandList.back().getParameters().front());
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->removeTank();
        }
        /*!
            Check the open valve command.
            The "open_valve" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "open_valve" && commandList.back().getParameters().size() == 1 &&
            commandList.back().getParameters().front() <= tm->getTanks().size() && commandList.back().getParameters().front() != 0) {
            tm->openValve(commandList.back().getParameters().front());
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->openValve();
        }
        /*!
            Check the close valve command.
            The "close_valve" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "close_valve" && commandList.back().getParameters().size() == 1 &&
            commandList.back().getParameters().front() <= tm->getTanks().size() && commandList.back().getParameters().front() != 0) {
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            tm->closeValve(commandList.back().getParameters().front());
            fw->closeValve();
        }
        /*!
            Check the break fuel tank command.
            The "break_fuel_tank" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "break_fuel_tank" && commandList.back().getParameters().size() == 1 &&
            commandList.back().getParameters().front() <= tm->getTanks().size() && commandList.back().getParameters().front() != 0) {
            tm->breakFuelTank(commandList.back().getParameters().front());
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->breakTank();
        }
        /*!
            Check the repair fuel tank command.
            The "repair_fuel_tank" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "repair_fuel_tank" && commandList.back().getParameters().size() == 1 &&
            commandList.back().getParameters().front() <= tm->getTanks().size() && commandList.back().getParameters().front() != 0) {
            tm->repairFuelTank(commandList.back().getParameters().front());
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                tm->consumeFuel(1);
            }
            fw->repairTank();
        }
        /*!
            Check the wait command.
            The "wait" command should have one parameter.
        */
        else if (commandList.back().getCommand() == "wait" && commandList.back().getParameters().size() == 1) {
            if (tm->getEngine()->getConnection() && tm->getEngine()->getStatus()) {
                s->wait(tm, commandList.back().getParameters().front());
            }
        }
        else {
            /*! Print an error message in case of an invalid command */
            fw->error(); 
        }
    }
};
