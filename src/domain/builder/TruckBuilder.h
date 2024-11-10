#ifndef TRUCKBUILDER_H
#define TRUCKBUILDER_H

#include <iostream>
#include "../models/IVehicleBuilder.h"

class TruckBuilder : public IVehicleBuilder {
private:
    int seatCount;
    int wheelCount;
    int maxSpeed;
    std::string modelName;
    std::string engineName;
    std::string sound;

public:
    TruckBuilder();

    void reset() override;
    void setSeatCount(int seats) override;
    void setWheelCount(int wheels) override;
    void setMaxSpeed(int speed) override;
    void setName(std::string model) override;
    void setEngineType(std::string engine) override;
    void honk(std::string sound) override;
    void display() const;
};

#endif
