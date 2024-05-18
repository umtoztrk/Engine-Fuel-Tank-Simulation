#include <iostream>
#include "Valve.h"
using namespace std;

Valve::Valve() : status(false) {
    /*! Constructor for the Valve class, initializes the status to false (closed). */
}

void Valve::setStatus(bool newValve) {
    /*! Set the status of the valve (open/closed).
        \param newValve Boolean indicating the new status of the valve.
    */
    status = newValve;
}

bool Valve::getStatus() const {
    /*! Get the current status of the valve.
        \return Boolean indicating whether the valve is open (true) or closed (false).
    */
    return status;
}
