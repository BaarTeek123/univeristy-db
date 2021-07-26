//
// Created by bartek on 7/16/21.
//

#ifndef UNIVERSITY_DB_STUDENT_HPP
#define UNIVERSITY_DB_STUDENT_HPP


#include "Person.hpp"


class Student: public Person{
    std::string index_number_;
public:
    const std::string &getIndexNumber() const;
    void setIndexNumber(const std::string &indexNumber);
    Student();
    Student(const Person&, const std::string&);
    Student(const std::string &,const std::string&,const std::string&, const Gender&, const std::string&, const Address& address);
    friend std::ostream& operator << (std::ostream& os, const Student& student);

};


#endif //UNIVERSITY_DB_STUDENT_HPP
