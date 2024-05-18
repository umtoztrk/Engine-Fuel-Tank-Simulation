#include "Engine.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

Engine* Engine::getInstance() {
    /*!
     * Singleton design pattern implementation.
     * If an instance of the Engine does not exist, create a new one; otherwise, return the existing instance.
     */
    if (!instance) {
        instance = new Engine();
    }
    return instance;
}

void Engine::setConnection(bool isConnected_) {
    /*!
     * Set the connection status of the engine.
     * \param isConnected_ Boolean indicating whether the engine is connected.
     */
    isConnected = isConnected_;
}

bool Engine::getConnection() {
    /*!
     * Get the connection status of the engine.
     * \return Boolean indicating whether the engine is connected.
     */
    return this->isConnected;
}

bool Engine::getStatus() {
    /*!
     * Get the status of the engine (on/off).
     * \return Boolean indicating the current status of the engine.
     */
    return status;
}

vector<FuelTank>& Engine::getConnectedTanks() {
    /*!
     * Get a reference to the vector of connected fuel tanks.
     * \return Reference to the vector containing connected fuel tanks.
     */
    return connectedTankList;
}

void Engine::setStatus(bool status_) {
    /*!
     * Set the status of the engine (on/off).
     * \param status_ Boolean indicating the new status of the engine.
     */
    status = status_;
}

FuelTank* Engine::getIntTank() {
    /*!
     * Get a pointer to the internal fuel tank of the engine.
     * \return Pointer to the internal fuel tank.
     */
    return &intTank;
}

void Engine::setConsumedFuel(double _consumedFuel) {
    /*!
     * Set the total amount of fuel consumed by the engine.
     * \param _consumedFuel The new total consumed fuel value.
     */
    consumedFuel = _consumedFuel;
}

bool Engine::statusControl() {
    /*!
     * Check and return the current status of the engine (on/off).
     * \return Boolean indicating the current status of the engine.
     */
    return status;
}

double* Engine::getConsumedFuel() {
    /*!
     * Get a pointer to the total amount of fuel consumed by the engine.
     * \return Pointer to the total consumed fuel value.
     */
    return &consumedFuel;
}
