//
// Created by bartek on 8/25/21.
//

#ifndef UNIVERSITY_DB_EMPLOYEE_HPP
#define UNIVERSITY_DB_EMPLOYEE_HPP

#include "Person.hpp"
class Employee : public Person{
  size_t salary_;

public:
  size_t getSalary() const;
  void setSalary(size_t salary);

public:
  Employee(const Person& person, size_t sallary);
  Employee(const std::string & forename,const std::string & name,const std::string & pesel, const Gender& gender, const Address& adress,size_t sallary);
  void display() const;






};

#endif // UNIVERSITY_DB_EMPLOYEE_HPP
