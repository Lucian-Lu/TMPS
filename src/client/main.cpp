#include <iostream>
#include "../domain/models/IVehicleBuilder.h"
#include "../domain/builder/CarBuilder.h"
#include "../domain/builder/TruckBuilder.h"
#include "../utilities/composite/VehicleComposite.h"
#include "../utilities/decorator/VehicleColorDecorator.h"
#include "../utilities/facade/VehicleMaintenance.h"

int main() {
    CarBuilder carBuilder;
    TruckBuilder truckBuilder;

    // Using the color decorator on a car & truck
    std::string color1 = "Yellow";
    VehicleColorDecorator car(&carBuilder, color1);
    car.setName("Cool car");
    car.setSeatCount(4);
    car.setWheelCount(4);
    car.setMaxSpeed(210);
    car.setEngineType("V8");
    car.honk("Womp");
    car.display();

    std::string color2 = "Blue";
    VehicleColorDecorator truck(&truckBuilder, color2);
    truck.setName("Heavy Duty Truck");
    truck.setSeatCount(2);
    truck.setWheelCount(12);
    truck.setMaxSpeed(140);
    truck.setEngineType("Diesel");
    truck.honk("HooOOnk");
    truck.display();

    // Making a composite of the vehicles
    VehicleComposite fleet;
    fleet.addVehicle(&car);
    fleet.addVehicle(&truck);

    std::cout << "Displaying vehicles:" << std::endl;
    fleet.display();

    // Using the facade for easy changes to the objects
    VehicleMaintenance mechanic(truckBuilder, carBuilder);
    mechanic.upgradeCar();
    mechanic.upgradeTruck();

    std::cout << "Displaying upgraded vehicles:" << std::endl;
    fleet.display();

    return 0;
}
