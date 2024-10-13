#include <iostream>


// Implementing 2 solid principles in a basic company class
class EmployeeManagement {
    public:
        // Getter and setter for employees
        int getEmployeeCount() {
            return employeeCount;
        }

        void setEmployeeCount(int employeeCount) {
            this->employeeCount = employeeCount;
        }
    private:
        int employeeCount = 0;
};

class HumanResources : public EmployeeManagement{
    public:
        // Functions to modify nr. of employees
        void fireEmployee() {
            setEmployeeCount(this->getEmployeeCount() - 1);
        }

        void hireEmployee() {
            setEmployeeCount(this->getEmployeeCount() + 1);
        }
};

class ProfitManagement {
    public:
        // Getter and setter for profits
        int getProfit() {
            return profit;
        }

        void setProfit(int profit) {
            this->profit = profit;
        }
    private:
        int profit = 0;
};

class FinanceDepartment : public ProfitManagement {
    public:
        // Functions to modify profits
        void decreaseProfits() {
            setProfit(this->getProfit() - 100);
        }

        void increaseProfits() {
            setProfit(this->getProfit() + 100);
        }
};

class Company {
    public:
        // Constructor
        Company(int employeeCount, int profit) {
            humanResources.setEmployeeCount(employeeCount);
            financeDepartment.setProfit(profit);
        }

        // Getter methods 
        int getEmployeeCount() {
            return humanResources.getEmployeeCount();
        }

        int getProfit() {
            return financeDepartment.getProfit();
        }

        // Company functions
        void hireEmployee() {
            humanResources.hireEmployee();
        }

        void fireEmployee() {
            humanResources.fireEmployee();
        }

        void increaseProfits() {
            financeDepartment.increaseProfits();
        }

        void decreaseProfits() {
            financeDepartment.decreaseProfits();
        }

    private:
        HumanResources humanResources;
        FinanceDepartment financeDepartment;
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