#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "Device.h"
#include "Valve.h"
using namespace std;

class FuelTank : public Device{
private:
    /*! Capacity of the fuel tank. */
    double capacity;    
    /*! Current fuel quantity in the tank. */
    double fuel_quantity;
    /*! Status of the tank valve (open or closed). */
    bool valve_open;
    /*! Status of the tank (broken or not). */
    bool broken;   
    /*! Status of the tank (deleted or not). */
    bool isDeleted;      
    /*! Status of the tank connection to the engine. */
    bool isConnected;
    /*! Unique identifier for the fuel tank. */
    int id;       

    Valve valve;

public:
    
    static int tankCount;
    /*! Constructor for the FuelTank class. */
    FuelTank(int _id = 0, double _capacity = 0.0, bool _valveopen = false, bool _broken = false, bool _isConnected = false) : id(_id), capacity(_capacity), fuel_quantity(0.0), valve_open(_valveopen), broken(_broken), isConnected(_isConnected), isDeleted(false) {}

    void deleteTank();

    Valve* getValve();

    static int getNumberofTank();

    static void decreaseTankCount();

    static void increaseTankCount();

    /*! Set connection function to be accessed from the external class. */
    void setConnection(bool);

    /*! Get connection status function to retrieve the value from the external class. */
    bool getConnection(); 

    /*! Getter for the tank identifier. */
    int getId();

    /*! Setter for the tank broken status. */
    void setBroken(bool);

    /*! Getter for the tank broken status. */
    bool getBroken();

    /*! Setter for the tank deletion status. */
    void setIsDeleted(bool);

    /*! Getter for the tank deletion status. */
    bool getIsDeleted();

    /*! Getter for the tank capacity. */
    double *getCapacity();

    /*! Setter for the tank fuel quantity. */
    void setQuantity(double);

    /*! Getter for the tank fuel quantity. */
    double *getQuantity();

    /*! Method to check the overall status of the tank. */
    bool checkTank();

    // Add other methods as needed
};