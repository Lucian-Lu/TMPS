#include "CarBuilder.h"


CarBuilder::CarBuilder() {
    reset();
}

void CarBuilder::reset() {
    seatCount = 0;
    wheelCount = 0;
    maxSpeed = 0;
    modelName = "";
    engineName = "";
    sound = "";
}

void CarBuilder::setSeatCount(int seats) {
    seatCount = seats;
}

void CarBuilder::setWheelCount(int wheels) {
    wheelCount = wheels;
}

void CarBuilder::setMaxSpeed(int speed) {
    maxSpeed = speed;
}

void CarBuilder::setName(std::string model) {
    modelName = model;
}

void CarBuilder::setEngineType(std::string engine) {
    engineName = engine;
}

void CarBuilder::honk(std::string sound) {
    this->sound = sound;
    std::cout << "The car goes " << this->sound << std::endl; 
}

void CarBuilder::display() const {
    std::cout << "Car Model: " << modelName << ", Seats: " << seatCount
              << ", Wheels: " << wheelCount << ", Max Speed: " << maxSpeed
              << ", Engine: " << engineName << std::endl;
}
