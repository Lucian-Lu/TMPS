#ifndef FACTORYMANAGER_H
#define FACTORYMANAGER_H

#include "CarFactory.h"
#include "TruckFactory.h"

class FactoryManager {
public:
    FactoryManager(const FactoryManager&) = delete;
    FactoryManager& operator=(const FactoryManager&) = delete;

    // Getting the singleton instance
    static FactoryManager& getInstance() {
        static FactoryManager factoryManager;
        return factoryManager; 
    }

    CarFactory* getCarFactory() { return &carFactory; }
    TruckFactory* getTruckFactory() { return &truckFactory; }

private:
    // Private constructor to avoid instance creation
    FactoryManager() {}
    CarFactory carFactory;
    TruckFactory truckFactory;
};

#endif
