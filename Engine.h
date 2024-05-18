#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "FuelTank.h"
#include "Device.h"
#include "TankManager.h"
using namespace std;

class TankManager;

class Engine : public Device {
private:
    /*! Singleton instance of the Engine. */
    static Engine* instance; 
    /*! true for on, false for off */
    bool status;              
    /*! Fuel consumption rate per second. */
    const double fuel_per_second; 
    /*! Connection status of the engine. */
    bool isConnected; 
    /*! Total fuel consumed by the engine. */
    double consumedFuel; 
    /*! Internal fuel tank of the engine. */
    FuelTank intTank; 
    /*! Vector of connected external fuel tanks. */
    vector<FuelTank> connectedTankList; 
    /*! Pointer to the TankManager managing the engine. */
    TankManager* tank; 

    /*! Private constructor for the Engine. Initializes default values. */
    Engine() : status(false), fuel_per_second(5.5), isConnected(false), consumedFuel(0.0), intTank(FuelTank(-1, 55.0, true, false, true)) {}

public:
    /*! Get the instance of the Engine (singleton pattern). */
    static Engine* getInstance();

    /*! Set connection status for external access.
        \param isConnected_ Boolean indicating the new connection status.
    */
    void setConnection(bool isConnected_);

    /*! Get a reference to the vector of connected external fuel tanks.
        \return Vector of FuelTank objects representing the connected external fuel tanks.
    */
    vector<FuelTank>& getConnectedTanks();

    /*! Get a pointer to the internal fuel tank of the engine.
        \return Pointer to the FuelTank object representing the internal fuel tank.
    */
    FuelTank* getIntTank();

    /*! Get the connection status of the engine.
        \return Boolean indicating whether the engine is connected (true) or not (false).
    */
    bool getConnection();

    /*! Get a pointer to the total fuel consumed by the engine.
        \return Pointer to the double representing the total fuel consumed by the engine.
    */
    double* getConsumedFuel();

    /*! Set the total fuel consumed by the engine.
        \param _consumedFuel Double representing the new total fuel consumed by the engine.
    */
    void setConsumedFuel(double _consumedFuel);

    /*! Check and return the current status of the engine (on/off).
        \return Boolean indicating whether the engine is on (true) or off (false).
    */
    bool statusControl();

    /*! Get the current status of the engine (on/off).
        \return Boolean indicating whether the engine is on (true) or off (false).
    */
    bool getStatus();

    /*! Set the status of the engine (on/off).
        \param status_ Boolean indicating the new status of the engine.
    */
    void setStatus(bool status_);
};
