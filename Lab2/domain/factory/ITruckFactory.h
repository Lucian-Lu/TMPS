#include <iostream>
#include "../models/IVehicleBuilder.h"

// Factory to construct different types of trucks
class ITruckFactory {
    public:
        virtual ~ITruckFactory() {}
        virtual IVehicleBuilder* createHeavyLoadTruck() = 0;
        virtual IVehicleBuilder* createLongMileageTruck() = 0;
        virtual IVehicleBuilder* createBalancedTruck() = 0;
};