# TMPS Laboratory Work #2 - Structural Design Patterns

## Author - Lupan Lucian, FAF-221

# Objectives:
* Learn about Structural Design Patterns and their uses;
* Implement the patterns in a simple project;
* Make use of the previous lab files by extending it with the new design patterns.

# Introduction to Structual Design Patterns
Structural Design Patterns are solutions in software design that focus on how classes and objects are organized to form larger, functional structures. These patterns help developers simplify relationships between objects, making code more efficient, flexible, and easy to maintain. By using structural patterns, you can better manage complex class hierarchies, reuse existing code, and create scalable architectures.

# What are the benefits of Structural Design Patterns?
1. This pattern is particularly useful for making independently developed class libraries work together.
2. Structural Design Patterns describe ways to compose objects to realize new functionality.
3. The added flexibility of object composition comes from the ability to change the composition at run-time, which is impossible with static class composition.

# Used Design Patterns
1. Composite
2. Decorator
3. Facade



# Implementation:
This laboratory work expands on the previous laboratory work. Since structural design patterns manipulate existing data structure (in our case - Car & Truck Builder/Factory), we can implement the design patterns without altering the already existing code from Lab1.
1. **Composite** - Composite pattern is used where we need to treat a group of objects in similar way as a single object. It's implemented by adding a vector list which can be used to store other instances of a Builder (car/truck):
```
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
```
This approach allows us to, for example, store vehicle objects with similar behaviour in another object, and make use of all of them at once.
\
2. **Decorator** - Decorator pattern allows a user to add new functionality to an existing object without altering its structure. In this context, the decorator basically allows us to store an additional field, not included in the vehicle builder class - color:
```
// Setting the color in a constructor
VehicleColorDecorator(IVehicleBuilder* vehicleBuilder, std::string& vehicleColor)
        : builder(vehicleBuilder), color(vehicleColor) {}

// Printing the color
void display() const override {
        builder->display();
        std::cout << "Color: " << color << std::endl;
    }
```
By using the decorator, we can change existing car/truck objects without having to modify the base classes (i.e., IVehicleBuilder).
\
3. **Facade** - Facade pattern hides the complexities of the system and provides an interface to the client using which the client can access the system. To implement this design pattern, we simply modify some of the parameters of our objects, while providing an abstract/vague explanation to the user (upgradeCar/Truck):
```
public:
    VehicleMaintenance(TruckBuilder& truckBuilder, CarBuilder& carBuilder)
        : truck(truckBuilder), car(carBuilder) {}

    void upgradeCar() {
        car.setEngineType("Car Engine V2");
        car.setMaxSpeed(250);
    }

    void upgradeTruck() {
        truck.setEngineType("Truck Engine V2");
        truck.setMaxSpeed(150);
    }

private:
    TruckBuilder& truck;
    CarBuilder& car;
```
The abstraction of this design pattern lets the client use methods without having to worry about their implementation.

# Conclusion
After finishing this laboratory work, I learnt about the various structural design patterns, and how they could be used in OOP projects. Compared to the creational design patterns, the structural design patterns's role is to modify the existing objects, either by adding new functionalities, allowing incompatible objects to operate, or optimizing the current designs (i.e., reducing memory usage with the help of flyweight pattern).