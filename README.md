# TMPS Laboratory Works

README file for the laboratory works at the TMPS course. All laboratories are/will be written in the C++ language (unless some requirements can't be met).

## Table of Contents

1. [Lab 0: Solid Principles](#lab-0-solid-principles)
2. [Lab 1: Creational Design Patterns](#lab-1-creational-design-patterns)

## Lab Summaries

### Lab 0: Solid Principles

# Introduction to SOLID
SOLID is an acronym for the first five object-oriented design (OOD) principles by Robert C. Martin (also known as Uncle Bob). These principles establish practices for developing software with considerations for maintaining and extending it as the project grows. Adopting these practices can also help avoid code smells, refactor code, and develop Agile or Adaptive software.

# What are the SOLID Principles?
1. Single-responsibility Principle - A class should have one and only one reason to change, meaning that a class should have only one job.
2. Open-closed Principle - Objects or entities should be open for extension but closed for modification.
3. Liskov Substitution Principle - Let q(x) be a property provable about objects of x of type T. Then q(y) should be provable for objects y of type S where S is a subtype of T.
4. Interface Segregation Principle - A client should never be forced to implement an interface that it doesn’t use, or clients shouldn’t be forced to depend on methods they do not use.
5. Dependency Inversion Principle - Entities must depend on abstractions, not on concretions. It states that the high-level module must not depend on the low-level module, but they should depend on abstractions.

# Objectives:
Implement 2 SOLID principles in a simple project.

# Implementation:
This laboratory work features a simple class - "Company". This class has functions designed for hiring/firing employees and increasing/decreasing profits. These functions are split in 2 different classes - HumanResources and FinanceDepartment, which inherit from the EmployeeManagement and ProfitManagement classes respectively. This is done in order to:
1. Respect the Single-responsibility Principle, by ensuring that every class has one single functionality (HumanResources manages employees, FinanceDepartment manages profits);
2. Adheres to the Open-closed Principle, by allowing for future expansion without having to rewrite existing code (ex. adding a double profits function to the FinanceDepartment class)
3. Complies with Liskov Substitution Principle, as any subclass of the interfaces(IEmployeeManagement & IProfitManagement) can be used interchangeably with their parent types without altering the correctness of the program.

# Conclusion
This laboratory work has reminded me of the importance of SOLID principles, previously learned at OOP classes. Although some of them are more intuitive and easier to integrate than others, implementing all 5 principles in a project ensures that the code is both easy to understand and change. Researching & implementing SOLID has taught me how to better handle OOP projects, by creating interfaces, as well as subclasses for individual responsibilies.  

### Lab 1: Creational Design Patterns

# Creational Design Patterns - Theory:
In software engineering, the creational design patterns are the general solutions that deal with object creation, trying to create objects in a manner suitable to the situation. The basic form of object creation could result in design problems or added complexity to the design. Creational design patterns solve this problem by optimizing, hiding or controlling the object creation.

# What are the Creational Design Patterns?
1. **Factory Method** is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.
2. **Abstract Factory** is a creational design pattern that lets you produce families of related objects without specifying their concrete classes.
3. **Builder** is a creational design pattern that lets you construct complex objects step by step. The pattern allows you to produce different types and representations of an object using the same construction code.
4. **Prototype** is a creational design pattern that lets you copy existing objects without making your code dependent on their classes.
5. **Singleton** is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.
6. The **object pool pattern** is a software creational design pattern that uses a set of initialized objects kept ready to use – a "pool" – rather than allocating and destroying them on demand

# Objectives:
1. Choose an OO programming language and a suitable IDE or Editor (No frameworks/libs/engines allowed).
2. Select a domain area for the sample project.
3. Define the main involved classes and think about what instantiation mechanisms are needed.
4. Based on the previous point, implement atleast 3 creational design patterns in your project.

# Implementation:
This laboratory work implements 3 creational design patterns - factory method, builder & singleton.\
The first design pattern - the builder - starts off with the **IVehicleBuilder** interface, which provides the standard structure of how a vehicle should look. The concrete builder implementations - **CarBuilder** and **TruckBuilder** classes are the prototypes for the factory implementations, which can be used to create objects without the need of lengthy constructors. Also, we implement a **Director** class, which defines the concrete objects for the factories.\
The second creational design pattern is the factory method. By creating interfaces for both factories (car & truck), after following a standard design - **IVehicleBuilder** interface, we can split our subclasses designs, while still operating with the same object type in the superclass. The concrete factory implementations - **CarFactory** and **TruckFactory** each work with 3 concrete objects, which are referencing the superclass type of IVehicleBuilder.\
The last creational design pattern is the Singleton. To implement this, a new header file - **FactoryManager** was created, which has a private contructor, making it impossible to instantiate the class outside of the 'getInstance' function. This class manages the instances of the **CarFactory** and **TruckFactory**, making it necessary to rely on the singleton instances in order to create objects. 

# Conclusion
This laboratory work has taught me about creational design patterns, how to implement them, what their benefits are, and gave me a better idea of how to better manage classes and instances in OOP languages. Although some of the creational design patterns are harder & more time consuming to implement than others, for bigger projects they can help save time by allowing for more flexibility, as well as code reusability.