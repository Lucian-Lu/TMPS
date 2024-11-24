#ifndef VEHICLE_SNAPSHOT_H
#define VEHICLE_SNAPSHOT_H

#include "../../domain/models/IVehicleBuilder.h"
#include <stack>

// Class that stores a snapshot, returning saved values via getters
class VehicleSnapshot {
public:
    VehicleSnapshot(int vehicleSeats, int vehicleWheels, int vehicleMaxSpeed, 
                    std::string vehicleName, std::string vehicleEngineType, std::string vehicleHonkSound)
        : seats(vehicleSeats), wheels(vehicleWheels), maxSpeed(vehicleMaxSpeed), 
          name(vehicleName), engineType(vehicleEngineType), honkSound(vehicleHonkSound) {}

    int getSeats() const {
        return seats;
    }

    int getWheels() const {
        return wheels;
    }

    int getMaxSpeed() const {
        return maxSpeed;
    }

    std::string getName() const {
        return name;
    }

    std::string getEngineType() const {
        return engineType;
    }

    std::string getHonkSound() const {
        return honkSound;
    }

private:
    int seats;
    int wheels;
    int maxSpeed;
    std::string name;
    std::string engineType;
    std::string honkSound;
};

// Class that creates snapshots using stacks
class VehicleOriginator {
public:
    VehicleOriginator(IVehicleBuilder* builder) : builder(builder) {}

    void makeSnapshot() {
        VehicleSnapshot snapshot(builder->getSeatCount(), builder->getWheelCount(), 
                                  builder->getMaxSpeed(), builder->getName(), 
                                  builder->getEngineType(), builder->getHonkSound());
        snapshots.push(snapshot);
    }

    void undo() {
        if (!snapshots.empty()) {
            VehicleSnapshot snapshot = snapshots.top();
            snapshots.pop();

            builder->setSeatCount(snapshot.getSeats());
            builder->setWheelCount(snapshot.getWheels());
            builder->setMaxSpeed(snapshot.getMaxSpeed());
            builder->setName(snapshot.getName());
            builder->setEngineType(snapshot.getEngineType());
            builder->honk(snapshot.getHonkSound());
        } else {
            std::cout << "No snapshots saved in memory." << std::endl;
        }
    }

private:
    IVehicleBuilder* builder;
    std::stack<VehicleSnapshot> snapshots;
};

#endif
