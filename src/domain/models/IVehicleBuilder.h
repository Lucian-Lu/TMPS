#ifndef IVEHICLEBUILDER_H
#define IVEHICLEBUILDER_H

#include <iostream>

// Builder that will be used instead of constructors
class IVehicleBuilder {
    public:
        virtual void reset() = 0;
        virtual void setSeatCount(int seats) = 0;
        virtual void setWheelCount(int wheels) = 0;
        virtual void setMaxSpeed(int speed) = 0;
        virtual void setName(std::string model) = 0;
        virtual void setEngineType(std::string engine) = 0;
        virtual void honk(std::string sound) = 0;
        virtual void display() const = 0;
        virtual ~IVehicleBuilder() {}
        virtual int getSeatCount() const = 0;
        virtual int getWheelCount() const = 0;
        virtual int getMaxSpeed() const = 0;
        virtual std::string getName() const = 0;
        virtual std::string getEngineType() const = 0;
        virtual std::string getHonkSound() const = 0;
};

#endif