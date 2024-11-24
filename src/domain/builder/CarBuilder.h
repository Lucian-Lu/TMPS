#ifndef CARBUILDER_H
#define CARBUILDER_H

#include <iostream>
#include "../models/IVehicleBuilder.h"

class CarBuilder : public IVehicleBuilder {
private:
    int seatCount;
    int wheelCount;
    int maxSpeed;
    std::string modelName;
    std::string engineName;
    std::string sound;

public:
    CarBuilder();

    void reset() override;
    void setSeatCount(int seats) override;
    void setWheelCount(int wheels) override;
    void setMaxSpeed(int speed) override;
    void setName(std::string model) override;
    void setEngineType(std::string engine) override;
    void honk(std::string sound) override;
    void display() const;
    int getSeatCount() const;
    int getWheelCount() const;
    int getMaxSpeed() const;
    std::string getName() const;
    std::string getEngineType() const;
    std::string getHonkSound() const;
};

#endif
