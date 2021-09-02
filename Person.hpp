#include <iostream>
#include "Address.hpp"

enum class Gender {
    Female,
    Male,
    I_do_not_want_to_pass
};


class Person {
protected:
    std::string forename_;
    std::string  name_;
    std::string peselNumber_;
    Gender gender_;
    Address address_;
public:
    const Address &getAddress() const;
    Person();
    Person(const std::string & forename,const std::string & name,const std::string & pesel, const Gender& gender, const Address& adress);
    Person (const std::string&, const std::string&,const std::string&, const Address&);
    Person (const std::string&, const std::string&);
    const std::string &getForename() const;
    void setForename(const std::string &forename);
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getPeselNumber() const;
    void setPeselNumber(const std::string &peselNumber);
    Gender getGender() const;
    Gender setGender();
    void setGender(const Gender& gender);
    friend std::ostream& operator << (std::ostream& os, const Person& person);
    Person addPerson();
};
