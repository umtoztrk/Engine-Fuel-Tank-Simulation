#pragma once
#include "Engine.h"
using namespace std;

class Simulation {
public:
    /*! Stop the simulation by exiting the program. */
    void stopSimulation();

    /*! Start the engine associated with the provided TankManager.
        \param tm Pointer to the TankManager managing the engine.
    */
    void startEngine(TankManager* tm);

    /*! Stop the engine associated with the provided TankManager.
        \param tm Pointer to the TankManager managing the engine.
    */
    void stopEngine(TankManager* tm);

    /*! Simulate a wait action by consuming fuel from the engine associated with the provided TankManager.
        \param tm Pointer to the TankManager managing the engine.
        \param i Integer indicating the duration of the wait action.
    */
    void wait(TankManager* tm, int i);
};

