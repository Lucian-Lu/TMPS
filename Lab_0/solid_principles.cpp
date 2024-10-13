#include <iostream>


// Implementing 2 solid principles in a basic company class
// Interface for Employee Management
class IEmployeeManagement {
    public:
        virtual int getEmployeeCount() const = 0;
        virtual void setEmployeeCount(int employeeCount) = 0;
        virtual void fireEmployee() = 0;
        virtual void hireEmployee() = 0;
    };

// Interface for Profit Management
class IProfitManagement {
    public:
        virtual int getProfit() const = 0;
        virtual void setProfit(int profit) = 0;
        virtual void decreaseProfits() = 0;
        virtual void increaseProfits() = 0;
    };

class EmployeeManagement : public IEmployeeManagement{
    public:
        // Getter and setter for employees
        int getEmployeeCount() const override {
            return employeeCount;
        }

        void setEmployeeCount(int employeeCount) override {
            this->employeeCount = employeeCount;
        }
    private:
        int employeeCount = 0;
};

class HumanResources : public EmployeeManagement{
    public:
        // Functions to modify nr. of employees
        void fireEmployee() override {
            setEmployeeCount(this->getEmployeeCount() - 1);
        }

        void hireEmployee() override {
            setEmployeeCount(this->getEmployeeCount() + 1);
        }
};

class ProfitManagement : public IProfitManagement{
    public:
        // Getter and setter for profits
        int getProfit() const override {
            return profit;
        }

        void setProfit(int profit) override {
            this->profit = profit;
        }
    private:
        int profit = 0;
};

class FinanceDepartment : public ProfitManagement {
    public:
        // Functions to modify profits
        void decreaseProfits() override {
            setProfit(this->getProfit() - 100);
        }

        void increaseProfits() override {
            setProfit(this->getProfit() + 100);
        }
};

class Company {
    public:
        // Constructor
        Company(int employeeCount, int profit) 
            : humanResources(new HumanResources()), 
            financeDepartment(new FinanceDepartment()){
            humanResources->setEmployeeCount(employeeCount);
            financeDepartment->setProfit(profit);
        }

        // Getter methods 
        int getEmployeeCount() {
            return humanResources->getEmployeeCount();
        }

        int getProfit() {
            return financeDepartment->getProfit();
        }

        // Company functions
        void hireEmployee() {
            humanResources->hireEmployee();
        }

        void fireEmployee() {
            humanResources->fireEmployee();
        }

        void increaseProfits() {
            financeDepartment->increaseProfits();
        }

        void decreaseProfits() {
            financeDepartment->decreaseProfits();
        }

    private:
        IEmployeeManagement* humanResources;
        IProfitManagement* financeDepartment;
};


int main() {
    Company company(500, 200000);
    std::cout << "Employee count = " << company.getEmployeeCount() << "\nCompany profit = " << company.getProfit() << "\n" << std::endl;

    company.hireEmployee();
    company.increaseProfits();
    company.increaseProfits();

    std::cout << "Employee count = " << company.getEmployeeCount() << "\nCompany profit = " << company.getProfit() << "\n" << std::endl;

    company.fireEmployee();
    company.fireEmployee();
    company.decreaseProfits();

    std::cout << "Employee count = " << company.getEmployeeCount() << "\nCompany profit = " << company.getProfit() << "\n" << std::endl;
    
    return 0;
}