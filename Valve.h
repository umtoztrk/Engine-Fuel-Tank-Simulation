#pragma once

/*!
 * \class Valve
 * \brief Represents a valve that can be open or closed.
 */
class Valve {
private:
    /*! Boolean indicating the current status of the valve (open or closed). */
    bool status; 

public:
    /*!
     * \brief Default constructor for Valve. Initializes the valve status to closed.
     */
    Valve();

    /*!
     * \brief Get the current status of the valve.
     * \return Boolean indicating whether the valve is open (true) or closed (false).
     */
    bool getStatus() const;

    /*!
     * \brief Set the status of the valve.
     * \param newValve Boolean indicating the new status of the valve (true for open, false for closed).
     */
    void setStatus(bool newValve);
};

