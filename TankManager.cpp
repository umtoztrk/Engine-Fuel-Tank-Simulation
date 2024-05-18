#include "TankManager.h"

using namespace std;

TankManager::TankManager() {
    engine = Engine::getInstance();
}

bool TankManager::checkTanks() {
    /*! Check if any of the connected fuel tanks have open valves and are in a usable state. */
    /*! Return true if at least one tank is usable, false otherwise.*/
    for (int i = 0;i < getTanks().size();i++) {
        if (getTanks()[i].checkTank())
            return true;
    }
    return false;
}

Engine* TankManager::getEngine() {
    return (engine);
}

void TankManager::absorbFuel() {
    /*! Function to absorb fuel from connected fuel tanks to the internal tank if the internal tank level is below 20 units.*/

    if (*(engine->getIntTank())->getQuantity() < 20) {

        /*! Identify connected and active fuel tanks */

        vector<int> connectedTankIds;
        for (int i = 0;i < getTanks().size();i++) {
            if (getTanks()[i].checkTank() && !getTanks()[i].getIsDeleted()) {
                connectedTankIds.push_back(i);
            }
        }

        /*! Randomly select a connected fuel tank to absorb fuel from */
        for (auto k : connectedTankIds) {
            vector<size_t> selectedIndices;
            size_t i;
            do {
                i = rand() % connectedTankIds.size();
            } while (find(selectedIndices.begin(), selectedIndices.end(), i) != selectedIndices.end());;
            selectedIndices.push_back(i);

            /*! Perform fuel absorption based on the quantity in the selected tank */
            if ((*getTanks()[connectedTankIds[i]].getQuantity()) >= 55) {
                getTanks()[i].setQuantity(*getTanks()[connectedTankIds[i]].getQuantity() - 55.0 + *(engine->getIntTank())->getQuantity());
                engine->getIntTank()->setQuantity(55.0);
                break;
            }
            else if (*getTanks()[connectedTankIds[i]].getQuantity() < 55) {
                if (*getTanks()[connectedTankIds[i]].getQuantity() + *(engine->getIntTank())->getQuantity() < 55) {
                    engine->getIntTank()->setQuantity(*(engine->getIntTank())->getQuantity() + *getTanks()[connectedTankIds[i]].getQuantity());
                    getTanks()[connectedTankIds[i]].setQuantity(0.0);
                }
                else {
                    getTanks()[connectedTankIds[i]].setQuantity(*getTanks()[connectedTankIds[i]].getQuantity() - 55.0 + *(engine->getIntTank())->getQuantity());
                    engine->getIntTank()->setQuantity(55.0);
                    break;
                }
            }
        }
    }
}

void TankManager::consumeFuel(int time = 1) {
    /*! Function to simulate fuel consumption over a specified time period.*/
    while (time > 0) {
        /*! Check and absorb fuel if the internal tank level is below 20 units */
        if (*(engine->getIntTank())->getQuantity() < 20) absorbFuel();

        /*! Deduct fuel consumption rate from the internal tank */
        engine->getIntTank()->setQuantity(*(engine->getIntTank())->getQuantity() - 5.5);

        /*! Check if the internal tank is depleted*/
        if (*(engine->getIntTank())->getQuantity() < 0) {
            engine->getIntTank()->setQuantity(0.0);
            engine->setStatus(false); /*! Turn off the engine when the internal tank is empty */
            break;
        }
        engine->setConsumedFuel(*(engine->getConsumedFuel()) + 5.5); /*! Accumulate consumed fuel */
        time--;
    }

}

vector<FuelTank>& TankManager::getTanks() {
    /*! Function to get a reference to the vector of connected fuel tanks.*/
    return tanks;
}
bool TankManager::giveBackFuel(double quantity) {
    /*! Function to return unused fuel from the internal tank to the connected fuel tank with the least amount of fuel.*/
    FuelTank* minTank = nullptr; /*! Pointer to the fuel tank with the least amount of fuel */
    int flag = 0; /*! Flag to track the presence of eligible fuel tanks */

    /*! Iterate through all fuel tanks to find eligible tanks for returning fuel */
    for (int i = 0; i < tanks.size(); i++) {
        if ((tanks[i]).checkTank() && !(tanks[i]).getIsDeleted() && ((tanks[i]).getQuantity() != (tanks[i]).getCapacity())) {
            /*! If it's the first eligible tank, set it as the minimum tank */
            if (flag == 0) {
                minTank = &(tanks[i]);
                flag++;
                continue;
            }

            /*! Update the minimum tank if the current tank has less fuel */
            if ((*minTank).getQuantity() > (tanks[i]).getQuantity()) {
                minTank = &(tanks[i]);
            }
        }
    }

    /*! If no eligible tanks are found, return false */
    if (flag == 0) return false;

    /*! Adjust the quantity to be returned if it exceeds the internal tank level */
    if (quantity > *(engine->getIntTank()->getQuantity())) quantity = *(engine->getIntTank()->getQuantity());
    double* IntTank = engine->getIntTank()->getQuantity();
    /*! Return fuel to the selected tank */
    if (quantity > ((*minTank).getCapacity() - (*minTank).getQuantity())) {
        *IntTank -= (*minTank).getCapacity() - (*minTank).getQuantity();
        (*minTank).setQuantity(*minTank->getCapacity());
    }
    else {
        (*minTank).setQuantity(*(*minTank).getQuantity() + quantity);
        *IntTank -= (quantity);
    }
    return true; /*! Successfully returned fuel */
}

void TankManager::addFuelTank(double cap) {
    /*!
        Add a new fuel tank to the tanks list with the given capacity.
    */
    tanks.push_back(FuelTank(tanks.size(), cap));
    /*!
        Increase the total number of fuel tanks in the FuelTank class.
    */
    FuelTank::increaseTankCount();
}

void TankManager::printFuelTankCount() {
    /*!
        Get and return the total number of fuel tanks from the FuelTank class.
    */
    FuelTank::getNumberofTank();
}

void TankManager::removeFuelTank(int i) {
    /*!
        Mark the specified tank as deleted and decrease the total number of fuel tanks.
    */
    tanks[i - 1].setIsDeleted(true);
    /*!
        Decrease the total number of fuel tanks.
    */
    FuelTank::decreaseTankCount();
}

void TankManager::fillTank(int i, int cap) {
    /*!
        Check if the total quantity after filling exceeds the tank capacity.
    */
    if (tanks[i - 1].getCapacity() < tanks[i - 1].getQuantity() + cap) {
        /*!
            If yes, set the tank quantity to its capacity.
        */
        tanks[i - 1].setQuantity(*(tanks[i - 1].getCapacity()));
    }
    else {
        /*!
            If no, increment the tank quantity by the given amount.
        */
        tanks[i - 1].setQuantity(*tanks[i - 1].getQuantity() + cap);
    }
}

void TankManager::connectFuelTankToEngine(int i) {
    /*!
        If the engine is not already connected, set the engine connection to true.
    */
    if (!(*engine).getConnection()) {
        (*engine).setConnection(true);
    }
    /*!
        Set the specified tank's connection status to true.
    */
    tanks[i - 1].setConnection(true);
}

void TankManager::disconnectFuelTankFromEngine(int i) {
    /*!
        Set the specified tank's connection status to false.
    */
    tanks[i - 1].setConnection(false);

    /*!
        Check if any tank is still connected to the engine.
    */
    int flag2 = 0;
    for (int i = 0; i < FuelTank::getNumberofTank(); i++) {
        if (tanks[i].getConnection() == true) {
            flag2++;
            break;
        }
    }

    /*!
        If no tank is connected, set the engine connection to false.
    */
    if (flag2 == 0) (*engine).setConnection(false);
}

void TankManager::openValve(int i) {
    /*!
        If the tank valve is closed, set its status to open.
    */
    if (!(tanks[i - 1].getValve()->getStatus())) tanks[i - 1].getValve()->setStatus(true);
}

void TankManager::closeValve(int i) {
    /*!
        If the tank valve is open, set its status to closed.
    */
    if (tanks[i - 1].getValve()->getStatus()) tanks[i - 1].getValve()->setStatus(false);
}

void TankManager::breakFuelTank(int i) {
    /*!
        Set the specified tank's broken status to true.
    */
    tanks[i - 1].setBroken(true);
}

void TankManager::repairFuelTank(int i) {
    /*!
        Set the specified tank's broken status to false.
    */
    tanks[i - 1].setBroken(false);
}

string TankManager::printInfo(int id) {
    /*!
        Return a string containing information about the specified tank.
    */
    return "tank id : " + to_string(id) + "\n" +
        "tank capacity : " + to_string(*(tanks[id - 1].getCapacity())) + "\n" +
        "fuel quantity : " + to_string(*(tanks[id - 1].getQuantity())) + "\n" +
        "tank valve is open? : " + to_string(tanks[id - 1].getValve()->getStatus()) + "\n" +
        "tank is broken? : " + to_string(tanks[id - 1].getBroken()) + "\n" +
        "tank is connected? : " + to_string(tanks[id - 1].getConnection()) + "\n";
}
