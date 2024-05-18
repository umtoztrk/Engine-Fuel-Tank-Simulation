#pragma once
#include "FuelTank.h"
#include "Engine.h"
#include "Device.h"
class Engine;

/*!
 * \class TankManager
 * \brief Manages a collection of Fuel Tanks and their interactions with an Engine.
 */
class TankManager : public Device {
private:
    /*! Vector to store Fuel Tanks managed by the TankManager. */
    vector<FuelTank> tanks;
    /*! Pointer to the Engine associated with the TankManager. */
    Engine* engine; 

public:
    /*!
     * \brief Default constructor for TankManager.
     */
    TankManager();

    /*!
     * \brief Get a reference to the vector of Fuel Tanks.
     * \return Reference to the vector of Fuel Tanks.
     */
    vector<FuelTank>& getTanks();

    /*!
     * \brief Give back fuel to the connected Engine.
     * \param quantity Amount of fuel to give back.
     * \return Boolean indicating success (true) or failure (false).
     */
    bool giveBackFuel(double quantity);

    /*!
     * \brief Add a new Fuel Tank to the collection.
     * \param cap Capacity of the new Fuel Tank.
     */
    void addFuelTank(double cap);

    /*!
     * \brief Print the count of connected Fuel Tanks.
     */
    void printFuelTankCount();

    /*!
     * \brief Remove a Fuel Tank from the collection.
     * \param i Index of the Fuel Tank to be removed.
     */
    void removeFuelTank(int i);

    /*!
     * \brief Get the pointer to the associated Engine.
     * \return Pointer to the associated Engine.
     */
    Engine* getEngine();

    /*!
     * \brief Fill a specific Fuel Tank with a given amount of fuel.
     * \param i Index of the Fuel Tank to be filled.
     * \param cap Amount of fuel to fill.
     */
    void fillTank(int i, int cap);

    /*!
     * \brief Connect a specific Fuel Tank to the associated Engine.
     * \param i Index of the Fuel Tank to be connected.
     */
    void connectFuelTankToEngine(int i);

    /*!
     * \brief Disconnect a specific Fuel Tank from the associated Engine.
     * \param i Index of the Fuel Tank to be disconnected.
     */
    void disconnectFuelTankFromEngine(int i);

    /*!
     * \brief Open the valve of a specific Fuel Tank.
     * \param i Index of the Fuel Tank whose valve will be opened.
     */
    void openValve(int i);

    /*!
     * \brief Close the valve of a specific Fuel Tank.
     * \param i Index of the Fuel Tank whose valve will be closed.
     */
    void closeValve(int i);

    /*!
     * \brief Break a specific Fuel Tank.
     * \param i Index of the Fuel Tank to be broken.
     */
    void breakFuelTank(int i);

    /*!
     * \brief Check if any of the Fuel Tanks are in a valid state.
     * \return Boolean indicating whether any Fuel Tank is in a valid state.
     */
    bool checkTanks();

    /*!
     * \brief Absorb fuel from connected Fuel Tanks into the associated Engine.
     */
    void absorbFuel();

    /*!
     * \brief Consume fuel from the associated Engine for a specified duration.
     * \param duration Duration for which fuel will be consumed.
     */
    void consumeFuel(int duration);

    /*!
     * \brief Repair a specific Fuel Tank.
     * \param i Index of the Fuel Tank to be repaired.
     */
    void repairFuelTank(int i);

    /*!
     * \brief Print information about a specific Fuel Tank.
     * \param id ID of the Fuel Tank for which information will be printed.
     * \return String containing information about the specified Fuel Tank.
     */
    string printInfo(int id);
};

