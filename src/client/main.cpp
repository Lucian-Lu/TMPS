#include <iostream>
#include "../domain/models/IVehicleBuilder.h"
#include "../utilities/memento/VehicleSnapshot.h"
#include "../utilities/memento/VehicleCaretaker.h"

int main() {
    // Making a vehicle and caretaker objects
    VehicleOriginator vehicle;
    VehicleCaretaker caretaker;

    vehicle.setName("Car 1");
    vehicle.setEngineType("Engine V1");
    vehicle.setSeatCount(4);
    vehicle.setWheelCount(4);
    vehicle.setMaxSpeed(150);
    vehicle.honk("Beep");
    vehicle.display();

    // Making a snapshot of the initial vehicle
    vehicle.makeSnapshot();

    vehicle.setName("Car 2");
    vehicle.setEngineType("Engine V2");
    vehicle.setMaxSpeed(180);
    vehicle.honk("Beep Beep");
    vehicle.display();
    // Making a snapshot of the modified vehicle
    vehicle.makeSnapshot();

    vehicle.setName("Car 3");
    vehicle.setEngineType("Engine V3");
    vehicle.setMaxSpeed(210);
    vehicle.honk("Beep Beep Beep");
    vehicle.display();
    // Reverting to the modified vehicle
    vehicle.undo();
    std::cout << "After first undo:" << std::endl;
    vehicle.display();
    // Reverting to the initial vehicle
    vehicle.undo();
    std::cout << "After second undo:" << std::endl;
    vehicle.display();

    return 0;
}
