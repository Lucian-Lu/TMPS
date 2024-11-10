#include <iostream>
#include "../models/IVehicleBuilder.h"
using namespace std;


// Factory to construct different types of cars
class ICarFactory {
    public:
        virtual ~ICarFactory() {}
        virtual IVehicleBuilder* createLuxuryCar() = 0;
        virtual IVehicleBuilder* createHybridCar() = 0;
        virtual IVehicleBuilder* createElectricCar() = 0;
};