#ifndef TRUCKFACTORY_H
#define TRUCKFACTORY_H

#include <iostream>
#include "ITruckFactory.h"
#include "../models/TruckBuilder.h"

class TruckFactory : public ITruckFactory {
public:
    IVehicleBuilder* createHeavyLoadTruck() override;
    IVehicleBuilder* createLongMileageTruck() override;
    IVehicleBuilder* createBalancedTruck() override;
};

#endif
