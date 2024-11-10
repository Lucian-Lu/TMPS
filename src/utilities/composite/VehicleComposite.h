#ifndef VEHICLE_COMPOSITE_H
#define VEHICLE_COMPOSITE_H

#include <vector>
#include "../../domain/models/IVehicleBuilder.h"

class VehicleComposite : public IVehicleBuilder {
public:
    void addVehicle(IVehicleBuilder* vehicle) {
        vehicles.push_back(vehicle);
    }

    void removeVehicle(IVehicleBuilder* vehicle) {
        for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
            if (*it == vehicle) {
                vehicles.erase(it);
                break;
            }
        }
    }

    void reset() override {
        for (auto* vehicle : vehicles) {
            vehicle->reset();
        }
    }

    void setSeatCount(int seats) override {
        for (auto* vehicle : vehicles) {
            vehicle->setSeatCount(seats);
        }
    }

    void setWheelCount(int wheels) override {
        for (auto* vehicle : vehicles) {
            vehicle->setWheelCount(wheels);
        }
    }

    void setMaxSpeed(int speed) override {
        for (auto* vehicle : vehicles) {
            vehicle->setMaxSpeed(speed);
        }
    }

    void setName(std::string model) override {
        for (auto* vehicle : vehicles) {
            vehicle->setName(model);
        }
    }

    void setEngineType(std::string engine) override {
        for (auto* vehicle : vehicles) {
            vehicle->setEngineType(engine);
        }
    }

    void honk(std::string sound) override {
        for (auto* vehicle : vehicles) {
            vehicle->honk(sound);
        }
    }

    void display() const override {
        for (const auto* vehicle : vehicles) {
            vehicle->display();
        }
    }

private:
    std::vector<IVehicleBuilder*> vehicles;
};

#endif
