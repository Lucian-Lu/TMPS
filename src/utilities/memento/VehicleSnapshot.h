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
class VehicleOriginator : public IVehicleBuilder {
public:
    VehicleOriginator() : seats(0), wheels(0), maxSpeed(0) {}

    void reset() override {
        seats = 0;
        wheels = 0;
        maxSpeed = 0;
        name = "";
        engineType = "";
        honkSound = "";
    }

    void setSeatCount(int vehicleSeats) override {
        seats = vehicleSeats;
    }

    void setWheelCount(int vehicleWheels) override {
        wheels = vehicleWheels;
    }

    void setMaxSpeed(int vehicleMaxSpeed) override {
        maxSpeed = vehicleMaxSpeed;
    }

    void setName(std::string vehicleName) override {
        name = vehicleName;
    }

    void setEngineType(std::string vehicleEngineType) override {
        engineType = vehicleEngineType;
    }

    void honk(std::string vehicleHonkSound) override {
        honkSound = vehicleHonkSound;
    }

    void display() const override {
        std::cout << "Name: " << name << ", Engine: " << engineType
                  << ", Seats: " << seats << ", Wheels: " << wheels
                  << ", Max Speed: " << maxSpeed << ", Honk: " << honkSound << std::endl;
    }

    void makeSnapshot() {
        snapshots.push(VehicleSnapshot(seats, wheels, maxSpeed, name, engineType, honkSound));
    }

    void undo() {
        if (!snapshots.empty()) {
            VehicleSnapshot snapshot = snapshots.top(); // Get the snapshot
            seats = snapshot.getSeats();
            wheels = snapshot.getWheels();
            maxSpeed = snapshot.getMaxSpeed();
            name = snapshot.getName();
            engineType = snapshot.getEngineType();
            honkSound = snapshot.getHonkSound();
            snapshots.pop();
        } else {
            std::cout << "No snapshots saved in memory." << std::endl;
        }
    }

private:
    int seats;
    int wheels;
    int maxSpeed;
    std::string name;
    std::string engineType;
    std::string honkSound;
    std::stack<VehicleSnapshot> snapshots;
};

#endif
