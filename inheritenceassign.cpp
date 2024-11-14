#include <iostream> 
#include <string> 
 
using namespace std; 
 
// Base class 
class Employee { 
protected: 
    string Ename; 
    int EmpID; 
 
public: 
    // Default constructor 
    Employee() : Ename(""), EmpID(0) {} 
 
    // Parameterized constructor 
    Employee(string name, int id) : Ename(name), EmpID(id) {} 
 
    // Virtual func ons 
    virtual void accept() { 
        cout << "Enter employee name: "; 
        cin >> Ename; 
        cout << "Enter employee ID: "; 
        cin >> EmpID; 
    } 
 
    virtual void display() const { 
        cout << "Name: " << Ename << endl; 
        cout << "ID: " << EmpID << endl; 
    } 
 
    // Pure virtual func on 
    virtual double earnings() const = 0; 
 
    virtual ~Employee() {} 
}; 
 
// Derived class SalariedEmployee 
class SalariedEmployee : public Employee { 
private: 
    double weeklySalary; 
 
public: 
    // Default constructor 
    SalariedEmployee() : Employee(), weeklySalary(0.0) {} 
 
    // Parameterized constructor 
    SalariedEmployee(string name, int id, double salary) 
        : Employee(name, id), weeklySalary(salary) {} 
 
    // Overriding the accept method 
    void accept() override { 
        Employee::accept(); 
        cout << "Enter weekly salary: "; 
        cin >> weeklySalary; 
    } 
 
    // Overriding the display method 
    void display() const override { 
        Employee::display(); 
        cout << "Weekly Salary: $" << weeklySalary << endl; 
    } 
 
    // Overriding the earnings method 
    double earnings() const override { 
        return weeklySalary; 
    } 
}; 
 
// Derived class HourlyEmployee 
class HourlyEmployee : public Employee { 
private: 
    double wage; 
    double hours; 
    double hourlySalary; 
 
public: 
    // Default constructor 
    HourlyEmployee() : Employee(), wage(0.0), hours(0.0), hourlySalary(0.0) {} 
 
    // Parameterized constructor 
    HourlyEmployee(string name, int id, double wage, double hours) 
        : Employee(name, id), wage(wage), hours(hours) { 
        calculateHourlySalary(); 
    } 
 
    // Overriding the accept method 
    void accept() override { 
        Employee::accept(); 
        cout << "Enter hourly wage: "; 
        cin >> wage; 
        cout << "Enter hours worked: "; 
        cin >> hours; 
        calculateHourlySalary(); 
    } 
 
    // Overriding the display method 
    void display() const override { 
        Employee::display(); 
        cout << "Hourly Wage: $" << wage << endl; 
        cout << "Hours Worked: " << hours << endl; 
        cout << "Hourly Salary: $" << hourlySalary << endl; 
    } 
 
    // Overriding the earnings method 
    double earnings() const override { 
        return hourlySalary; 
    } 
 
private: 
    void calculateHourlySalary() { 
        if (hours < 40) { 
            hourlySalary = hours * wage; 
        } else { 
            hourlySalary = 40 * wage + (hours - 40) * wage * 1.5; 
        } 
    } 
}; 
 
// Derived class CommissionEmployee 
class CommissionEmployee : public Employee { 
private: 
    double grossSales; 
    double commissionRate; 
    double commissionSalary; 
 
public: 
    // Default constructor 
    CommissionEmployee() : Employee(), grossSales(0.0), commissionRate(0.0), 
commissionSalary(0.0) {} 
 
    // Parameterized constructor 
    CommissionEmployee(string name, int id, double sales, double rate) 
        : Employee(name, id), grossSales(sales), commissionRate(rate) { 
        calculateCommissionSalary(); 
    } 
 
    // Overriding the accept method 
    void accept() override { 
        Employee::accept(); 
        cout << "Enter gross sales: "; 
        cin >> grossSales; 
        cout << "Enter commission rate: "; 
        cin >> commissionRate; 
        calculateCommissionSalary(); 
    } 
 
    // Overriding the display method 
    void display() const override { 
        Employee::display(); 
        cout << "Gross Sales: $" << grossSales << endl; 
        cout << "Commission Rate: " << commissionRate * 100 << "%" << endl; 
        cout << "Commission Salary: $" << commissionSalary << endl; 
    } 
 
    // Overriding the earnings method 
    double earnings() const override { 
        return commissionSalary; 
    } 
 
private: 
    void calculateCommissionSalary() { 
        commissionSalary = grossSales * commissionRate; 
    } 
}; 
 
// Main func on to demonstrate the classes 
int main() { 
    // Create objects of derived classes 
    SalariedEmployee salariedEmp; 
    HourlyEmployee hourlyEmp; 
    CommissionEmployee commissionEmp; 
 
    // Accept and display data for SalariedEmployee 
    cout << "Salaried Employee:\n"; 
    salariedEmp.accept(); 
    salariedEmp.display(); 
    cout << "Earnings: $" << salariedEmp.earnings() << endl; 
 
    // Accept and display data for HourlyEmployee 
    cout << "\nHourly Employee:\n"; 
    hourlyEmp.accept(); 
    hourlyEmp.display(); 
    cout << "Earnings: $" << hourlyEmp.earnings() << endl; 
 
    // Accept and display data for CommissionEmployee 
    cout << "\nCommission Employee:\n"; 
    commissionEmp.accept(); 
    commissionEmp.display(); 
    cout << "Earnings: $" << commissionEmp.earnings() << endl; 
 
    return 0; 
} 