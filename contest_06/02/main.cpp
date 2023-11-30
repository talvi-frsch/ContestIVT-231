#include <cmath>

class Employee {
protected:
    std::string name;
    std::string post;
    int stdSalary;
	int bonSalary;

public:
    Employee(std::string name_e, std::string post_e, int stdSalary_e) {
        name = name_e;
        post = post_e;
        stdSalary = stdSalary_e;
    	bonSalary = 0;
    }

    virtual int bonus(double perc) {
        bonSalary = round(stdSalary * perc);
        return bonSalary;
    }

    int salary() {
        bonus(bonuses[post]);
        return stdSalary + bonSalary;
    }

    friend std::ostream& operator << (std::ostream& os, Employee& employee) {
        return os << employee.name << " (" << employee.post << "): " << employee.salary();
    }
};

class Manager : public Employee {
public:
    Manager(std::string name, int salary = 16242)
        : Employee(name, "manager", salary) {}

    int bonus(double perc) {
        if (perc < 0.1) {
            perc = 0.1;
            bonSalary = round(stdSalary * perc);
            return bonSalary;
        }
        else {
            bonSalary = round(stdSalary * perc);
            return bonSalary;
        }
    } 
}; // ?
