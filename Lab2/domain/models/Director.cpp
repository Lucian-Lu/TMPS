#include "Director.h"
#include <iostream>

void Director::createLuxuryCar(IVehicleBuilder& builder) {
    builder.reset();
    builder.setSeatCount(4);
    builder.setWheelCount(4);
    builder.setMaxSpeed(240);
    builder.setName("Mercedes-Benz GLA");
    builder.setEngineType("OM 651 DE 22 LA");
    builder.honk("bop bop");
}

void Director::createHybridCar(IVehicleBuilder& builder) {
    builder.reset();
    builder.setSeatCount(4);
    builder.setWheelCount(4);
    builder.setMaxSpeed(180);
    builder.setName("Toyota Prius");
    builder.setEngineType("M20A-FXS");
    builder.honk("beep beep");
}

void Director::createElectricCar(IVehicleBuilder& builder) {
    builder.reset();
    builder.setSeatCount(4);
    builder.setWheelCount(4);
    builder.setMaxSpeed(230);
    builder.setName("Tesla Model 3");
    builder.setEngineType("Electric Motor (RWD & AWD)");
    builder.honk("beem beem");
}

void Director::createHeavyLoadTruck(IVehicleBuilder& builder) {
    builder.reset();
    builder.setSeatCount(2);
    builder.setWheelCount(18);
    builder.setMaxSpeed(110);
    builder.setName("Freightliner Cascadia 126");
    builder.setEngineType("Detroit DD15 Diesel Engine");
    builder.honk("hooonk hooonk");
}

void Director::createLongMileageTruck(IVehicleBuilder& builder) {
    builder.reset();
    builder.setSeatCount(2);
    builder.setWheelCount(18);
    builder.setMaxSpeed(130);
    builder.setName("Volvo VNL 860");
    builder.setEngineType("Volvo D13 Turbo Compound Diesel Engine");
    builder.honk("hoooooooonk");
}

void Director::createBalancedTruck(IVehicleBuilder& builder) {
    builder.reset();
    builder.setSeatCount(2);
    builder.setWheelCount(10);
    builder.setMaxSpeed(125);
    builder.setName("Kenworth T680");
    builder.setEngineType("PACCAR MX-13 Diesel Engine");
    builder.honk("honk honk");
}
