#include "TruckBuilder.h"

TruckBuilder::TruckBuilder() {
    reset();
}

void TruckBuilder::reset() {
    seatCount = 0;
    wheelCount = 0;
    maxSpeed = 0;
    modelName = "";
    engineName = "";
    sound = "";
}

void TruckBuilder::setSeatCount(int seats) {
    seatCount = seats;
}

void TruckBuilder::setWheelCount(int wheels) {
    wheelCount = wheels;
}

void TruckBuilder::setMaxSpeed(int speed) {
    maxSpeed = speed;
}

void TruckBuilder::setName(std::string model) {
    modelName = model;
}

void TruckBuilder::setEngineType(std::string engine) {
    engineName = engine;
}

void TruckBuilder::honk(std::string sound) {
    this->sound = sound;
    std::cout << "The truck goes " << this->sound << std::endl;
}

void TruckBuilder::display() const {
    std::cout << "Truck Model: " << modelName << ", Seats: " << seatCount
              << ", Wheels: " << wheelCount << ", Max Speed: " << maxSpeed
              << ", Engine: " << engineName << std::endl;
}

int TruckBuilder::getSeatCount() const {
    return seatCount;
}

int TruckBuilder::getWheelCount() const {
    return wheelCount;
}

int TruckBuilder::getMaxSpeed() const {
    return maxSpeed;
}

std::string TruckBuilder::getName() const {
    return modelName;
}

std::string TruckBuilder::getEngineType() const {
    return engineName;
}

std::string TruckBuilder::getHonkSound() const {
    return sound;
}

