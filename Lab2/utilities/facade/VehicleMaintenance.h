#ifndef VEHICLE_MAINTENANCE_H
#define VEHICLE_MAINTENANCE_H

#include "../../domain/builder/TruckBuilder.h"
#include "../../domain/builder/CarBuilder.h"

class VehicleMaintenance {
public:
    VehicleMaintenance(TruckBuilder& truckBuilder, CarBuilder& carBuilder)
        : truck(truckBuilder), car(carBuilder) {}

    void upgradeCar() {
        car.setEngineType("Car Engine V2");
        car.setMaxSpeed(250);
    }

    void upgradeTruck() {
        truck.setEngineType("Truck Engine V2");
        truck.setMaxSpeed(150);
    }

private:
    TruckBuilder& truck;
    CarBuilder& car;
};

#endif
