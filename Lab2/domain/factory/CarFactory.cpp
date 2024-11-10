#include "CarFactory.h"

IVehicleBuilder* CarFactory::createLuxuryCar() {
    return new CarBuilder();
}

IVehicleBuilder* CarFactory::createHybridCar() {
    return new CarBuilder();
}

IVehicleBuilder* CarFactory::createElectricCar() {
    return new CarBuilder();
}
