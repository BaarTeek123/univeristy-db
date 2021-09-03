//
// Created by bartek on 7/16/21.
//

#ifndef UNIVERSITY_DB_ADDRESS_HPP
#define UNIVERSITY_DB_ADDRESS_HPP
#pragma once

#include <iostream>

class Address {
    std::string street_;
    std::string bulidingNumber_;
    std::string flatNumber_;
    std::string town_;
    std::string postCode_;
    std::string postCodeTown_;
public:
    const std::string &getPostCode() const;
    void setPostCode(const std::string &postCode);
    const std::string &getPostCodeTown() const;
    void setPostCodeTown(const std::string &postCodeTown);
    const std::string &getStreet() const;
    void setStreet(const std::string &street);
    const std::string getBulidingNumber() const;
    void setBulidingNumber(const std::string& bulidingNumber);
    std::string getFlatNumber() const;
    void setFlatNumber(std::string flatNumber);
    const std::string &getTown() const;
    void setTown(const std::string &town);
    Address();
    Address(const std::string&,const std::string & , const std::string&, const std::string&,const std::string&, const std::string&);
    Address(const std::string&,const std::string & ,const std::string&, const std::string&,const std::string&);
    friend std::ostream& operator << (std::ostream&, const Address&);
    friend std::istream& operator >> (std::istream&,  Address&);
};



#endif //UNIVERSITY_DB_ADDRESS_HPP
