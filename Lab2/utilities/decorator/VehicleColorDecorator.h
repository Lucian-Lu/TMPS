#ifndef VEHICLE_COLOR_DECORATOR_H
#define VEHICLE_COLOR_DECORATOR_H

#include "../../domain/models/IVehicleBuilder.h"
#include <iostream>
#include <string>

class VehicleColorDecorator : public IVehicleBuilder {
public:
    VehicleColorDecorator(IVehicleBuilder* vehicleBuilder, std::string& vehicleColor)
        : builder(vehicleBuilder), color(vehicleColor) {}

    void reset() override {
        builder->reset(); 
    }

    void setSeatCount(int seats) override {
        builder->setSeatCount(seats);
    }

    void setWheelCount(int wheels) override {
        builder->setWheelCount(wheels); 
    }

    void setMaxSpeed(int speed) override {
        builder->setMaxSpeed(speed); 
    }

    void setName(std::string model) override {
        builder->setName(model); 
    }

    void setEngineType(std::string engine) override {
        builder->setEngineType(engine); 
    }

    void honk(std::string sound) override {
        builder->honk(sound); 
    }

    void display() const override {
        builder->display();
        std::cout << "Color: " << color << std::endl;
    }
    
private:
    IVehicleBuilder* builder;
    std::string color;
};

#endif
