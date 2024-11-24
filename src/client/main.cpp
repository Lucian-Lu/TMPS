#include <iostream>
#include "../domain/models/IVehicleBuilder.h"
#include "../domain/builder/CarBuilder.h"
#include "../domain/builder/TruckBuilder.h"
#include "../utilities/memento/VehicleSnapshot.h"
#include "../utilities/memento/VehicleCaretaker.h"

int main() {
    // Creating a car builder 
    CarBuilder carBuilder;
    // Assigning the car builder to the originator & making a caretaker
    VehicleOriginator vehicle(&carBuilder);
    VehicleCaretaker caretaker;

    // Setting the initial vehicle details
    carBuilder.setName("Car 1");
    carBuilder.setEngineType("Engine V1");
    carBuilder.setSeatCount(4);
    carBuilder.setWheelCount(4);
    carBuilder.setMaxSpeed(150);
    carBuilder.honk("Beep");
    carBuilder.display();

    // Making a snapshot of the initial vehicle
    vehicle.makeSnapshot();

    // Modifying the vehicle
    carBuilder.setName("Car 2");
    carBuilder.setEngineType("Engine V2");
    carBuilder.setMaxSpeed(180);
    carBuilder.honk("Beep Beep");
    carBuilder.display();
    
    // Making a snapshot of the modified vehicle
    vehicle.makeSnapshot();

    // Modifying the modified the vehicle
    carBuilder.setName("Car 3");
    carBuilder.setEngineType("Engine V3");
    carBuilder.setMaxSpeed(210);
    carBuilder.honk("Beep Beep Beep");
    carBuilder.display();
    
    // Reverting to the modified vehicle
    vehicle.undo();
    std::cout << "After first undo (Modified car):" << std::endl;
    carBuilder.display();

    // Reverting to the initial vehicle
    vehicle.undo();
    std::cout << "After second undo (Initial car):" << std::endl;
    carBuilder.display();

    return 0;
}
