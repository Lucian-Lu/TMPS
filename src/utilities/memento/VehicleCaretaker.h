#ifndef VEHICLE_CARETAKER_H
#define VEHICLE_CARETAKER_H

#include "VehicleSnapshot.h"
#include <stack>

// Caretaker class to manage snapshots made by originator
class VehicleCaretaker {
public:
    void makeSnapshot(const VehicleSnapshot& snapshot) {
        snapshots.push(snapshot);
    }

    VehicleSnapshot undo() {
        if (!snapshots.empty()) {
            VehicleSnapshot snapshot = snapshots.top();
            snapshots.pop();
            return snapshot;
        } else {
            std::cout << "No snapshots stored in memory." << std::endl;
        }
    }

private:
    std::stack<VehicleSnapshot> snapshots;
};

#endif