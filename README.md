# TMPS Laboratory Work #3 - Behavioral Design Patterns

## Author - Lupan Lucian, FAF-221

# Objectives:
* Learn about Behavioral Design Patterns;
* Implement a behavioral pattern in a project;
* Extend on the previous laboratory with the new design pattern.

# Introduction to Behavioral Design Patterns
Behavioral design patterns are a category of design patterns that focus on the interactions and communication between objects. They help define how objects collaborate and distribute responsibility among them, making it easier to manage complex control flow and communication in a system. 

# Used Design Patterns
1. Memento

# What is the 'Memento' Design Pattern?
A Memento Pattern says that "to restore the state of an object to its previous state". But it must do this without violating Encapsulation. Such case is useful in case of error or failure. The Memento pattern is also known as Token. Undo or backspace or ctrl+z is one of the most used operation in an editor. Memento design pattern is used to implement the undo operation. This is done by saving the current state of the object as it changes state.

## Benefits:
1.  It preserves encapsulation boundaries.
2.  It simplifies the originator.

## Usage:
1.  It is used in Undo and Redo operations in most software.
2.  It is also used in database transactions.

# Implementation:
This laboratory work expands on the previous laboratory work. In order to implement memento, previously defined classes had to be redefined in order to be able to handle the functionality of saving a snapshot. To achieve this, the base class - **IVehicleBuilder**, had to be modified with getter methods (for use in the car/truck builders):
```
virtual int getSeatCount() const = 0;
virtual int getWheelCount() const = 0;
virtual int getMaxSpeed() const = 0;
virtual std::string getName() const = 0;
virtual std::string getEngineType() const = 0;
virtual std::string getHonkSound() const = 0;
```

These are simple getter methods which are required in order to get the data needed for making a memento/snapshot of a vehicle. Since **IVehicleBuilder** is the main interface, **CarBuilder** and **TruckBuilder** also had to be modified to include & implement those methods:
```
int CarBuilder::getSeatCount() const {
    return seatCount;
}

int CarBuilder::getWheelCount() const {
    return wheelCount;
}

int CarBuilder::getMaxSpeed() const {
    return maxSpeed;
}

std::string CarBuilder::getName() const {
    return modelName;
}

std::string CarBuilder::getEngineType() const {
    return engineName;
}

std::string CarBuilder::getHonkSound() const {
    return sound;
}
```

After modifying the base classes, the additional functionality for saving/undoing a snapshot could be implemeneted in a separate header file - **VehicleSnapshot**, which in order to save a snapshot, would use the IVehicleBuilder object as a parameter and scrape all the data from it, pushing it into a stack (in the **VehicleOriginator** class):
```
VehicleOriginator(IVehicleBuilder* builder) : builder(builder) {}

void makeSnapshot() {
    VehicleSnapshot snapshot(builder->getSeatCount(), builder->getWheelCount(), 
                                builder->getMaxSpeed(), builder->getName(), 
                                builder->getEngineType(), builder->getHonkSound());
    snapshots.push(snapshot);
}
```

The **VehicleSnapshot** class is used as a template for storing/retrieving objects into/from the stack. When the user calls undo(), the top object is loaded into the VehicleSnapshot class, thus effectively getting the previous state of the object:
```
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
```

Lastly, we implement a **VehicleCaretaker** class, which manages the snapshots, but is unable to modify the data inside of them. It modifies the data by using the methods inside of the **VehicleSnapshot** class (undo() & makeSnapshot()):
```
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
```

# Conclusion
After finishing this laboratory work, I learnt about how behavioral design patterns could be implemented in projects that work with classes. Generally speaking, they simplify the communication process between classes, making them very useful in big projects that require the implementation of various algorithms operating on the same class - thus having common behaviors. This behavior can be stored in another class that the algorithms can share, simplifying and saving project resources.