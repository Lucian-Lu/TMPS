# TMPS Laboratory Works

README file for the laboratory works at the TMPS course. All laboratories are/will be written in the C++ language (unless some requirements can't be met).

## Table of Contents

1. [Lab 0: Solid Principles](#lab-0-solid-principles)

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
