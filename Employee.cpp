//
// Created by bartek on 8/25/21.
//

#include "Employee.hpp"
Employee::Employee(const Person &person, size_t sallary):Person(person), salary_(sallary) {}
Employee::Employee(const std::string &forename, const std::string &name,
                   const std::string &pesel, const Gender &gender,
                   const Address &adress, size_t sallary): Person( forename, name, pesel, gender, adress), salary_(sallary){}


void Employee::display() const {
  std::cout<<(*this);
  std::cout<<"\nSallary: "<< salary_ << " zlotych.\n";
}
size_t Employee::getSalary() const { return salary_; }

void Employee::setSalary(const size_t salary) { salary_ = salary; }
