#ifndef CARFACTORY_H
#define CARFACTORY_H

#include <iostream>
#include "ICarFactory.h"
#include "../models/CarBuilder.h"

class CarFactory : public ICarFactory {
public:
    IVehicleBuilder* createLuxuryCar() override;
    IVehicleBuilder* createHybridCar() override;
    IVehicleBuilder* createElectricCar() override;
};

#endif
