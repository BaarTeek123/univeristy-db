//
// Created by bartek on 7/16/21.
//
#include "Person.hpp"

const std::string &Person::getForename() const {
    return forename_;
}

void Person::setForename(const std::string &forename) {
    forename_ = forename;
}

const std::string &Person::getName() const {
    return name_;
}

void Person::setName(const std::string &name) {
    name_ = name;
}

const std::string &Person::getPeselNumber() const {
    return peselNumber_;
}

void Person::setPeselNumber(const std::string &peselNumber) {
    peselNumber_ = peselNumber;
}

Gender Person::getGender() const {
    return gender_;
}

void Person::setGender(const Gender& gender) {
    Person::gender_ = gender;
}

Person::Person(const std::string & forename,const std::string & name,const std::string & pesel, const Gender& gender, const Address& adress):
        forename_(forename), name_(name), peselNumber_(pesel), gender_(gender), address_(adress)
{}

Person ::Person(): Person("John", "Smith","",Gender::I_do_not_want_to_pass, Address()) {}

Person::Person(const std::string & forename,const std::string & name,const std::string & pesel, const Address& address):
        Person(forename, name, pesel, Gender::I_do_not_want_to_pass,address )
{}

Person::Person(const std::string & name,const std::string & pesel):
        Person("", name, pesel, Gender::I_do_not_want_to_pass, Address())
{}

std::ostream& operator << (std::ostream& os, const Person& person) {
    if (person.getGender()==Gender::Female)
        return os<<"Female: " << person.getForename() << " " << person.getName() << " \nPESEL: " << person.getPeselNumber();

    else if (person.getGender()==Gender::Male)
        return os <<"Male: "<< person.getForename() << " " << person.getName() << " \nPESEL: " << person.getPeselNumber();
    else
        return os << person.getForename() << " " << person.getName() << " \nPESEL: " << person.getPeselNumber();
}

const Address &Person::getAddress() const {
    return address_;
}


Address setAddress(Address &);

Person Person::addPerson() {
  std::string forename, name, pesel, choice;
  std::cout << "Please full correctly students' data.\nForname: ";
  std::getline(std::cin, forename);
  std::cout << "Name: ";
  if (std::islower(forename[0]))
    std::toupper(forename[0]);
  if (std::islower(name[0]))
    std::toupper(name[0]);
  for (auto it = forename.begin() + 1; it != forename.end();
       std::advance(it, 1)) {
    if (!std::islower(*it)) {
      std::tolower(*it);
    }
  }
  for (auto it = name.begin() + 1; it != name.end(); std::advance(it, 1)) {
    if (!std::islower(*it)) {
      std::tolower(*it);
    }
  }
  std::getline(std::cin, name);
  Gender gender = setGender();
  std::cout << "Pesel: ";
  std::getline(std::cin, pesel);
  Address address;
  setAddress(address);
  Person person (forename, name, pesel, gender, address);
  return person;
}
Gender Person::setGender() {
  std::cout<<"Gender: "



  return Gender::Female; }
