//
// Created by bartek on 7/16/21.
//

#include "DataManager.hpp"
#include "Employee.hpp"
#include <algorithm>
#include <ctime>
#include <random>
#include <string>

bool caseIgnoreStringCompare(const std::string&, const std::string&);


void DataManager::showShortWholeBase () const {
    if (deqOfPersons.empty())
        std::cout<<"The base is empty. There is no data to show.\n";
    else{
        int i =1;
        for (auto &student: deqOfPersons){
            std::cout<<i<<". "<<*student<<std::endl;
            i++;
        }
    }
}

void DataManager::showLongWholeBase() const {
    if (deqOfPersons.empty())
        std::cout<<"The base is empty. There is no data to show.\n";
    else{
        int i =1;
        for (auto &student: deqOfPersons){
            std::cout<<i<<". "<<*student<<std::endl;
            std::cout<<(*student).getAddress()<<std::endl;
            i++;
        }
    }
}

void DataManager::addToDec(const std::shared_ptr<Person>&person_ptr) {
  deqOfPersons.push_back(person_ptr);
}

/*
bool DataManager::deleteByIndex(const std::string &index) {
    if (deqOfPersons.empty())
        return false;
    auto it = deqOfPersons.begin();
    for (auto&person: deqOfPersons){
      if (typeid(*person).name() == "Student"){
        if (index == person->getIndexNumber()) {
          deqOfPersons.erase(it);
            return true;
        }
        std::advance(it,1);
    }
    return false;
}
*/

bool DataManager::deleteByName(const std::string &name) {
    if (deqOfPersons.empty())
        return false;
    auto it = deqOfPersons.begin();
    int amount = 0;
    for (auto&student: deqOfPersons){
        if (name == student->getName()) {
          deqOfPersons.erase(it);
            amount ++;
        }
        std::advance(it,1);
    }
    if (amount != 0)
        return true;
    return false;
}

bool DataManager::deleteByPesel(const std::string &pesel) {
    if (deqOfPersons.empty())
        return false;
    auto it = deqOfPersons.begin();
    for (auto&student: deqOfPersons){
        if (pesel == student->getPeselNumber()) {
          deqOfPersons.erase(it);
            return true;
        }
        std::advance(it,1);
    }
    return false;
}

bool DataManager::searchByName (const std::string &letters, std::vector<std::shared_ptr<Person>>& vec) {
    vec.clear();
    for (auto&person : deqOfPersons){
        if (caseIgnoreStringCompare(letters, person->getName().substr(0,letters.size())))
        {
            vec.push_back(person);
        }
    }
    vec.shrink_to_fit();
    if (vec.empty())
        return false;
    return true;
}

bool DataManager::searchByPesel(const std::string & pesel, std::vector<std::shared_ptr<Person>> & vec) {
    vec.clear();
    for (auto&person : deqOfPersons){
        if (pesel == person->getPeselNumber().substr(0,pesel.size())){
            vec.push_back(person);
        }
    }
    vec.shrink_to_fit();
    if (vec.empty())
        return false;
    return true;
}

/*
bool DataManager::searchByIndex(const std::string & index , std::vector<std::shared_ptr<Person>> & vec) {
    vec.clear();
    for (auto& student: deqOfPersons){
        if (index == student->getIndexNumber().substr(0,index.size())){
            vec.push_back(student);
        }
    }
    vec.shrink_to_fit();
    if (vec.empty())
        return false;
    return true;
}
*/

struct less_than_key_name
{
    inline bool operator() (const std::shared_ptr<Person>&person_1, const std::shared_ptr<Person>&person_2)
    {
        return (*person_1).getName()< (*person_2).getName();
    }
};

struct less_than_key_pesel
{
    inline bool operator() (const std::shared_ptr<Person>&person_1, const std::shared_ptr<Person>&person_2)
    {
        return (*person_1).getPeselNumber()< (*person_2).getPeselNumber();
    }
};

/*
struct less_than_key_index
{
    inline bool operator() (const std::shared_ptr<Person>& student_1, const std::shared_ptr<Person>&  student_2)
    {
        return (*student_1).getIndexNumber()< (*student_2).getIndexNumber();
    }
};
*/

bool DataManager::sortByName() {
    if (deqOfPersons.empty())
        return false;
    std::sort(deqOfPersons.begin(), deqOfPersons.end(), less_than_key_name());
    return true;
}

bool DataManager::sortByPesel() {
    if (deqOfPersons.empty())
        return false;
    std::sort(deqOfPersons.begin(), deqOfPersons.end(), less_than_key_pesel());
    return true;
}

/*
bool DataManager::sortByIndex(){
    if (deqOfPersons.empty())
        return false;
    std::sort(deqOfPersons.begin(), deqOfPersons.end(), less_than_key_index());
    return true;
}
*/

void show_vec (const std::vector<std::shared_ptr<Person>>&vec)  {
    for (auto&student:vec){
        std::cout<<*student<<std::endl;
    }
}



void DataManager:: generateData(const std::vector<std::string>&vecOfFornames, const std::vector<std::string>&vecOfNames,
                                const std::vector<std::string>&vecOfPesels, const int amount) {
    for (int i = 0; i < amount; i++) {
        int a = rand() % 3;
        Gender gender;
        if (a == 1) {
            gender = Gender::Female;
        } else if (a == 2) {
            gender = Gender::Male;
        } else
            gender = Gender::I_do_not_want_to_pass;
        a = rand() % 3;
        if (a == 1){
          Person object = Person (vecOfFornames[(std::rand() + i) % vecOfFornames.size()], vecOfNames[(std::rand() + i) % vecOfNames.size()],
                                   vecOfPesels[(std::rand() + i) % vecOfPesels.size()], gender, Address());
          deqOfPersons.push_back(std::make_shared<Person>(object));


        }
        else if (a == 2){
          const int min_salary = 2000;
          Employee object = Employee (vecOfFornames[(std::rand() + i) % vecOfFornames.size()], vecOfNames[(std::rand() + i) % vecOfNames.size()],
                                   vecOfPesels[(std::rand() + i) % vecOfPesels.size()], gender, Address(), ((std::rand() % min_salary)*(std::rand() % 10) + min_salary));
          deqOfPersons.push_back(std::make_shared<Person>(object));

        }
        else {

          lastIndex = std::to_string(std::stoll(lastIndex) + 1);
          Student object = Student(vecOfFornames[(std::rand() + i) % vecOfFornames.size()], vecOfNames[(std::rand() + i) % vecOfNames.size()],
                                   vecOfPesels[(std::rand() + i) % vecOfPesels.size()], gender, lastIndex, Address());
          deqOfPersons.push_back(std::make_shared<Person>(object));



        }

    }
}
bool DataManager::isPeselUnique(const std::string & pesel) {
    for (auto&student: deqOfPersons){
        if (pesel == student->getPeselNumber())
            return false;
    }
    return true;
}

/*
bool DataManager::isIndexUnique(const std::string &index) {
    for (auto&student: deqOfPersons){
        if (index == student->getIndexNumber())
            return false;
    }
    return true;
}
*/

void DataManager:: updateIndex(){
    constexpr int indexSize = 9;
    lastIndex = std::to_string(std::stoll(lastIndex)+1);
    if (lastIndex.size() != indexSize){
        for (int i = 0;i < indexSize - lastIndex.size();i++){
            lastIndex.insert(lastIndex.begin(), '0');
        }
    }
}

const std::string &DataManager::getLastIndex() const {
    return lastIndex;
}
