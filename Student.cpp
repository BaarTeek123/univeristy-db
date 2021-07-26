//
// Created by bartek on 7/16/21.
//

#include "Student.hpp"

Student::Student(const std::string & forename,const std::string & name,const std::string & pesel, const Gender& gen, const std::string& index, const Address& address):
        Person(forename, name, pesel, gen,address ), index_number_(index)
{}

Student::Student(const Person & person, const std::string &index) :
        Person(person), index_number_(index)
{}

const std::string &Student::getIndexNumber() const {
    return index_number_;
}

void Student::setIndexNumber(const std::string &indexNumber) {
    index_number_ = indexNumber;
}

Student::Student():
        Person(), index_number_("000000"){}

std::ostream& operator << (std::ostream& os, const Student& student) {
    if (student.getGender()==Gender::Female)
        return os<<"Female: " << student.getForename() << " " << student.getName() << " \nPESEL: " << student.getPeselNumber()<<"\nIndex: "<<student.getIndexNumber();

    else if (student.getGender()==Gender::Male)
        return os <<"Male: "<< student.getForename() << " " << student.getName() << " \nPESEL: " << student.getPeselNumber()<<"\nIndex: "<<student.getIndexNumber();
    else
        return os << student.getForename() << " " << student.getName() << " \nPESEL: " << student.getPeselNumber()<<"\nIndex: "<<student.getIndexNumber();
}
