//
// Created by bartek on 7/16/21.
//

#include "DataManager.hpp"
#include <algorithm>
#include <ctime>
#include <string>
#include <random>

bool caseIgnoreStringCompare(const std::string&, const std::string&);


void DataManager::showShortWholeBase () const {
    if (deqOfStudents.empty())
        std::cout<<"The base is empty. There is no data to show.\n";
    else{
        int i =1;
        for (auto &student:deqOfStudents){
            std::cout<<i<<". "<<*student<<std::endl;
            i++;
        }
    }
}

void DataManager::showLongWholeBase() const {
    if (deqOfStudents.empty())
        std::cout<<"The base is empty. There is no data to show.\n";
    else{
        int i =1;
        for (auto &student:deqOfStudents){
            std::cout<<i<<". "<<*student<<std::endl;
            std::cout<<(*student).getAddress()<<std::endl;
            i++;
        }
    }
}

void DataManager::addToDec(const std::shared_ptr<Student>&student_ptr) {
    deqOfStudents.push_back(student_ptr);
}

bool DataManager::deleteByIndex(const std::string &index) {
    if (deqOfStudents.empty())
        return false;
    auto it = deqOfStudents.begin();
    for (auto&student: deqOfStudents){
        if (index == student->getIndexNumber()) {
            deqOfStudents.erase(it);
            return true;
        }
        std::advance(it,1);
    }
    return false;
}

bool DataManager::deleteByName(const std::string &name) {
    if (deqOfStudents.empty())
        return false;
    auto it = deqOfStudents.begin();
    int amount = 0;
    for (auto&student: deqOfStudents){
        if (name == student->getName()) {
            deqOfStudents.erase(it);
            amount ++;
        }
        std::advance(it,1);
    }
    if (amount != 0)
        return true;
    return false;
}

bool DataManager::deleteByPesel(const std::string &pesel) {
    if (deqOfStudents.empty())
        return false;
    auto it = deqOfStudents.begin();
    for (auto&student: deqOfStudents){
        if (pesel == student->getPeselNumber()) {
            deqOfStudents.erase(it);
            return true;
        }
        std::advance(it,1);
    }
    return false;
}

bool DataManager::searchByName (const std::string &letters, std::vector<std::shared_ptr<Student>>& vec) {
    vec.clear();
    for (auto& student:deqOfStudents){
        if (caseIgnoreStringCompare(letters, student->getName().substr(0,letters.size())))
        {
            vec.push_back(student);
        }
    }
    vec.shrink_to_fit();
    if (vec.empty())
        return false;
    return true;
}

bool DataManager::searchByPesel(const std::string & pesel, std::vector<std::shared_ptr<Student>> & vec) {
    vec.clear();
    for (auto& student:deqOfStudents){
        if (pesel == student->getPeselNumber().substr(0,pesel.size())){
            vec.push_back(student);
        }
    }
    vec.shrink_to_fit();
    if (vec.empty())
        return false;
    return true;
}

bool DataManager::searchByIndex(const std::string & index , std::vector<std::shared_ptr<Student>> & vec) {
    vec.clear();
    for (auto& student:deqOfStudents){
        if (index == student->getIndexNumber().substr(0,index.size())){
            vec.push_back(student);
        }
    }
    vec.shrink_to_fit();
    if (vec.empty())
        return false;
    return true;
}

struct less_than_key_name
{
    inline bool operator() (const std::shared_ptr<Student>& student_1, const std::shared_ptr<Student>&  student_2)
    {
        return (*student_1).getName()< (*student_2).getName();
    }
};

struct less_than_key_pesel
{
    inline bool operator() (const std::shared_ptr<Student>& student_1, const std::shared_ptr<Student>&  student_2)
    {
        return (*student_1).getPeselNumber()< (*student_2).getPeselNumber();
    }
};

struct less_than_key_index
{
    inline bool operator() (const std::shared_ptr<Student>& student_1, const std::shared_ptr<Student>&  student_2)
    {
        return (*student_1).getIndexNumber()< (*student_2).getIndexNumber();
    }
};

bool DataManager::sortByName() {
    if (deqOfStudents.empty())
        return false;
    std::sort(deqOfStudents.begin(), deqOfStudents.end(), less_than_key_name());
    return true;
}

bool DataManager::sortByPesel() {
    if (deqOfStudents.empty())
        return false;
    std::sort(deqOfStudents.begin(), deqOfStudents.end(), less_than_key_pesel());
    return true;
}

bool DataManager::sortByIndex(){
    if (deqOfStudents.empty())
        return false;
    std::sort(deqOfStudents.begin(), deqOfStudents.end(), less_than_key_index());
    return true;
}

void show_vec (const std::vector<std::shared_ptr<Student>>&vec)  {
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
        lastIndex = std::to_string(std::stoll(lastIndex) + 1);
        Student student = Student(vecOfFornames[(std::rand() + i) % vecOfFornames.size()], vecOfNames[(std::rand() + i) % vecOfNames.size()],
                                  vecOfPesels[(std::rand() + i) % vecOfPesels.size()], gender, lastIndex, Address());
        deqOfStudents.push_back(std::make_shared<Student>(student));
    }
}
bool DataManager::isPeselUnique(const std::string & pesel) {
    for (auto&student: deqOfStudents){
        if (pesel == student->getPeselNumber())
            return false;
    }
    return true;
}

bool DataManager::isIndexUnique(const std::string &index) {
    for (auto&student: deqOfStudents){
        if (index == student->getIndexNumber())
            return false;
    }
    return true;
}

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
