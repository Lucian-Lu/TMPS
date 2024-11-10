#include "TruckFactory.h"

IVehicleBuilder* TruckFactory::createHeavyLoadTruck() {
    return new TruckBuilder();
}

IVehicleBuilder* TruckFactory::createLongMileageTruck() {
    return new TruckBuilder();
}

IVehicleBuilder* TruckFactory::createBalancedTruck() {
    return new TruckBuilder();
}
