#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "IVehicleBuilder.h"

class Director {
public:
    void createLuxuryCar(IVehicleBuilder& builder);
    void createHybridCar(IVehicleBuilder& builder);
    void createElectricCar(IVehicleBuilder& builder);
    void createHeavyLoadTruck(IVehicleBuilder& builder);
    void createLongMileageTruck(IVehicleBuilder& builder);
    void createBalancedTruck(IVehicleBuilder& builder);
};

#endif