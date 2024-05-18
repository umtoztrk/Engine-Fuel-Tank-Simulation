#pragma once
#include "FileReader.h"
#include "TankManager.h"

using namespace std;

class FileWriter {
private:
    /*! Output file stream for writing to "output.txt" */
    ofstream output; 
public:
    /*!
        Constructor for FileWriter class. Opens the "output.txt" file for writing.
    */
    FileWriter() {
        output.open("output.txt");
    }

    /*!
        Print information about a device.
        \param i Device object.
        \param a Integer parameter.
        \return A string containing device information.
    */
    string print(Device& i, int a) {
        return i.printInfo(a);
    }

    /*!
        Write to the output file indicating that the engine has been started.
    */
    void startEngine() {
        output << "Engine has been started.\n";
    }

    /*!
        Write to the output file indicating that the engine is already started.
    */
    void alreadyStarted() {
        output << "Already Started. \n";
    }

    /*!
        Write to the output file indicating that the engine has been stopped.
    */
    void stopEngine() {
        output << "Engine has been stopped.\n";
    }

    /*!
        Write to the output file indicating that fuel has been given back.
    */
    void giveBackFuel() {
        output << "Yakit geri verildi.\n";
    }

    /*!
        Write to the output file indicating that a fuel tank has been added.
    */
    void addFuelTank() {
        output << "Tank eklendi\n";
    }

    /*!
        Write to the output file listing all fuel tanks.
    */
    void listFuelTanks() {
        for (int i = 0; i < FuelTank::getNumberofTank(); i++) {
            output << "fuel_tank_" << i + 1 << "\n";
        }
    }

    /*!
        Write to the output file the count of fuel tanks.
    */
    void printFuelTankCount() {
        output << FuelTank::getNumberofTank() << "\n";
    }

    /*!
        Write to the output file indicating that a tank has been removed.
    */
    void removeTank() {
        output << "Tank silindi.\n";
    }

    /*!
        Write to the output file indicating that a tank has been connected to the engine.
    */
    void connectTankToEngine() {
        output << "Tank baglandi.\n";
    }

    /*!
        Write to the output file indicating that a tank has been disconnected from the engine.
    */
    void disconnectTankToEngine() {
        output << "Tank baglantisi kesildi.\n";
    }

    /*!
        Write to the output file listing all connected tanks.
    */
    void listConnectedTanks(TankManager* tm) {
        for (int i = 0; i < FuelTank::getNumberofTank(); i++) {
            if (tm->getTanks()[i].getConnection() == true) {
                output << "fuel_tank_" << i + 1 << "\n";
            }
        }
    }

    /*!
        Write to the output file the total fuel quantity in all tanks.
    */
    void printTotalFuelQuantity(TankManager* tm) {
        double totalFuel = 0;
        for (int i = 0; i < FuelTank::getNumberofTank(); i++) {
            totalFuel += *(tm->getTanks()[i].getQuantity());
        }
        totalFuel += *(tm->getEngine()->getIntTank()->getQuantity());
        output << "toplam yakit : " << totalFuel << "\n";
    }

    /*!
        Write to the output file the total consumed fuel quantity.
    */
    void printTotalConsumedFuelQuantity(TankManager* tm) {
        output << "toplam harcanan yakit : " << *(tm->getEngine()->getConsumedFuel()) << "\n";
    }

    /*!
        Write to the output file information about a specific tank.
    */
    void printTankInfo(TankManager* tm, int a) {
        output << print(*tm, a);
    }

    /*!
        Write to the output file indicating that a tank has been filled.
    */
    void fillTank() {
        output << "Tank dolduruldu.\n";
    }

    /*!
        Write to the output file indicating that a valve has been opened.
    */
    void openValve() {
        output << "Vana acildi.\n";
    }

    /*!
        Write to the output file indicating that a valve has been closed.
    */
    void closeValve() {
        output << "Vana kapandi.\n";
    }

    /*!
        Write to the output file indicating that a tank has been broken.
    */
    void breakTank() {
        output << "Tank bozuldu.\n";
    }

    /*!
        Write to the output file indicating that a tank has been repaired.
    */
    void repairTank() {
        output << "Tank tamir edildi.\n";
    }

    /*!
        Write to the output file indicating that the simulation has been stopped.
    */
    void stopSimulation() {
        output << "Simulasyon durduruldu.\n";
    }

    /*!
        Write to the output file indicating an error due to invalid parameters or commands.
    */
    void error() {
        output << "Hatali parametre/komut.\n";
    }
};
