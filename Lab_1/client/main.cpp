#include <iostream>
#include "../domain/models/Director.h"
#include "../domain/factory/FactoryManager.h"

int main() {
    Director director;

    // Using the Factory Manager Instance Singleton to only create one instance for both factories
    CarFactory* carFactory = FactoryManager::getInstance().getCarFactory();
    TruckFactory* truckFactory = FactoryManager::getInstance().getTruckFactory();

    // Using the car factory singleton
    IVehicleBuilder* luxuryCarBuilder = carFactory->createLuxuryCar();
    director.createLuxuryCar(*luxuryCarBuilder);
    luxuryCarBuilder->display();
    delete luxuryCarBuilder;

    // Using the truck factory singleton
    IVehicleBuilder* longMileageTruckBuilder = truckFactory->createLongMileageTruck();
    director.createLongMileageTruck(*longMileageTruckBuilder);
    longMileageTruckBuilder->display();
    delete longMileageTruckBuilder;

    return 0;
}
