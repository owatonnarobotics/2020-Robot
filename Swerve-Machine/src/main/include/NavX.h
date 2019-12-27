/*
class NavX

Constructors

    NavX(const int&): Creates a NavX on the specified interface (kUSB, kMXP)

Public Methods

    double getYaw(): Returns the yaw value.
    double getRate(): Returns the rate value as degrees.
    double getAngle(): Returns the angle value.
    double getAbsoluteAngle(): Returns the absolute value of the angle value.
    void resetYaw(): Sets the yaw value to zero.
*/

#pragma once

#include <cmath>

#include <SPI.h>

#include "AHRS.h"

class NavX {

    public:
        NavX(const int &connectionType) {

            if (connectionType == 0) {

                navX = new AHRS(SPI::kOnboardCS0);
            }
            else if (connectionType == 4) {

                navX = new AHRS(SPI::kMXP);
            }
            else {

                navX = new AHRS(SPI::kMXP);
            }
        }

        double getYaw() {

            return navX->GetYaw();
        }
        double getRate() {

            //Convert the rate to degrees and return it
            return (navX->GetRate()) * (180/M_PI);
        }
        double getAngle() {

            return navX->GetAngle();
        }
        double getAbsoluteAngle() {

            if (navX->GetAngle() < 0) {

                return ((navX->GetAngle()) - (2 * (navX->GetAngle())));
            }
            else {

                return navX->GetAngle();
            }
        }
        void resetYaw() {

            navX->ZeroYaw();
        }

        enum ConnectionType {

            kUSB,
            kMXP = 4
        };

    private:
        AHRS *navX;
};