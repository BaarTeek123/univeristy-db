//
// Created by bartek on 7/16/21.
//

#include "Address.hpp"

const std::string &Address::getPostCode() const {
    return postCode_;
}

void Address::setPostCode(const std::string &postCode) {
    postCode_ = postCode;
}

const std::string &Address::getPostCodeTown() const {
    return postCodeTown_;
}

void Address::setPostCodeTown(const std::string &postCodeTown) {
    postCodeTown_ = postCodeTown;
}

const std::string &Address::getStreet() const {
    return street_;
}

void Address::setStreet(const std::string &street) {
    Address::street_ = street;
}

const std::string Address::getBulidingNumber() const {
    return bulidingNumber_;
}

void Address::setBulidingNumber(const std::string& bulidingNumber) {
    bulidingNumber_ = bulidingNumber;
}

std::string Address::getFlatNumber() const {
    return flatNumber_;
}

void Address::setFlatNumber(std::string flatNumber) {
    flatNumber_ = flatNumber;
}

const std::string &Address::getTown() const {
    return town_;
}

void Address::setTown(const std::string &town) {
    Address::town_ = town;
}

Address::Address(const std::string & street, const std::string & buildingNum, const std::string& flatNum, const std::string& town,const std::string &postCode , const std::string & postCodeTown) :
        street_(street),
        bulidingNumber_(buildingNum),
        flatNumber_(flatNum),
        postCode_(postCode),
        town_(town),
        postCodeTown_(postCodeTown){}

Address::Address (const std::string & street, const std::string & buildingNum, const std::string& town, const std::string & postCode , const std::string &postCodeTown) :
        street_(street),
        bulidingNumber_(buildingNum),
        postCode_(postCode),
        town_(town),
        postCodeTown_(postCodeTown){}

Address::Address():
        street_("Legnicka"),
        bulidingNumber_("10a"),
        flatNumber_("1"),
        postCode_(""),
        town_("Wroclaw"),
        postCodeTown_("Wroclaw"){}

std::ostream &operator<<(std::ostream &os, const Address &address) {
    if (address.flatNumber_!="0")
        return os<<address.getTown()<<", street: "<<address.getStreet()<<" "<<address.getBulidingNumber()<<"/"<<address.getFlatNumber()<<"\n"<<address.postCode_<<" "<<address.postCodeTown_;

    return os<<address.getTown()<<", street: "<<address.getStreet()<<" "<<address.getBulidingNumber()<<"\n"<<address.postCode_<<" "<<address.postCodeTown_;
}

std::istream &operator >> (std::istream &is, Address &address) {
    std::cout<<"Town: ";
    is >> address.town_;
    std::cout<<"Street: ";
    is >> address.street_;
    std::cout<<"Builing number: ";
    is >> address.bulidingNumber_;
    std::cout<<"Flat number(if there is not, input '0': ";
    is >> address.flatNumber_;
    std::cout<<"Post code number: ";
    is >> address.postCode_;
    std::cout<<"Post code town: ";
    is >> address.postCodeTown_;
    return is;
}

Address setAddress(Address& address){
    std::cout<<"Town: ";
    std:: string tmp;
    std::getline(std::cin, tmp, '\n');
    address.setTown(tmp);
    std::cout<<"Street: ";
    std::getline(std::cin, tmp, '\n');
    address.setStreet(tmp);
    std::cout<<"Builing number: ";
    std::getline(std::cin, tmp, '\n');
    address.setBulidingNumber(tmp);
    bool isFlatCorrect = false;
    while (!isFlatCorrect) {
        std::cout << "Flat number(if there is not, input '0': ";
        for (int i = 0 ; i<  tmp.size(); i++){
            if (isdigit(int(tmp[i]))){
                address.setFlatNumber(tmp);
                std::getline(std::cin, tmp);
                isFlatCorrect = true;
                break;
            }
            std::cout<<"Your data is probably wrong. Try again.\n";
        }


    }
    std::cout<<"Post code number: ";
    std::getline(std::cin, tmp, '\n');
    address.setPostCode(tmp);
    std::cout<<"Post code town: ";
    std::getline(std::cin, tmp, '\n');
    address.setPostCodeTown(tmp);
    return address;
}

