#include "FuelTank.h"
#include <iostream>
#include "TankManager.h"

using namespace std;

int FuelTank::tankCount = 0;

void FuelTank::setConnection(bool isConnected_) {
    /*!
        Set the connection status of the fuel tank.
        \param isConnected_ Boolean indicating whether the tank is connected.
    */
    isConnected = isConnected_;
}

int FuelTank::getNumberofTank() {
    /*!
        Get the current count of connected fuel tanks.
        \return The number of connected fuel tanks.
    */
    return tankCount;
}

void FuelTank::decreaseTankCount() {
    /*!
        Decrement the count of connected fuel tanks.
    */
    tankCount--;
}

void FuelTank::increaseTankCount() {
    /*!
        Increment the count of connected fuel tanks.
    */
    tankCount++;
}

Valve* FuelTank::getValve() {
    /*!
        Get a pointer to the valve associated with the fuel tank.
        \return Pointer to the Valve object.
    */
    return (&valve);
}

void FuelTank::deleteTank() {
    /*!
        Decrement the count of connected fuel tanks when a tank is deleted.
    */
    tankCount--;
}

bool FuelTank::getConnection() {
    /*!
        Get the connection status of the fuel tank.
        \return Boolean indicating whether the tank is connected.
    */
    return isConnected;
}

bool FuelTank::checkTank() {
    /*!
        Check if the fuel tank is in a valid state (valve open, connected, not broken).
        \return Boolean indicating whether the tank is in a valid state.
    */
    return (valve.getStatus() && getConnection() && !getBroken());
}

void FuelTank::setQuantity(double quantity) {
    /*!
        Set the fuel quantity of the tank.
        \param quantity The quantity of fuel to set.
    */
    fuel_quantity = quantity;
}

double* FuelTank::getQuantity() {
    /*!
        Get a pointer to the fuel quantity of the tank.
        \return Pointer to the fuel quantity.
    */
    return (&fuel_quantity);
}

double* FuelTank::getCapacity() {
    /*!
        Get a pointer to the capacity of the tank.
        \return Pointer to the tank capacity.
    */
    return (&capacity);
}

void FuelTank::setBroken(bool _broken) {
    /*!
        Set the broken status of the tank.
        \param _broken Boolean indicating whether the tank is broken.
    */
    broken = _broken;
}

bool FuelTank::getBroken() {
    /*!
        Get the broken status of the tank.
        \return Boolean indicating whether the tank is broken.
    */
    return broken;
}

int FuelTank::getId() {
    /*!
        Get the unique identifier of the tank.
        \return The tank identifier.
    */
    return id;
}

void FuelTank::setIsDeleted(bool _isDeleted) {
    /*!
        Set the deleted status of the tank.
        \param _isDeleted Boolean indicating whether the tank is deleted.
    */
    isDeleted = _isDeleted;
}

bool FuelTank::getIsDeleted() {
    /*!
        Get the deleted status of the tank.
        \return Boolean indicating whether the tank is deleted.
    */
    return isDeleted;
}
