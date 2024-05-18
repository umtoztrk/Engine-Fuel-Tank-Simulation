#include "Simulation.h"

using namespace std;

void Simulation::startEngine(TankManager* tm) {
    /*! Start the engine in the simulation by setting its status to true.
        \param tm Pointer to the TankManager object managing the simulation.
    */
    tm->getEngine()->setStatus(true);
}

void Simulation::stopEngine(TankManager* tm) {
    /*! Stop the engine in the simulation by setting its status to false.
        \param tm Pointer to the TankManager object managing the simulation.
    */
    tm->getEngine()->setStatus(false);
}

void Simulation::stopSimulation() {
    /*! Stop the entire simulation and exit the program. */
    exit(1);
}

void Simulation::wait(TankManager* tm, int i) {
    /*! Simulate a waiting period in the simulation, consuming fuel from the tanks.
        \param tm Pointer to the TankManager object managing the simulation.
        \param i The duration of the wait, influencing the amount of fuel consumed.
    */
    tm->consumeFuel(i);
}
