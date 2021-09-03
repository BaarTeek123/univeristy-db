//
// Created by bartek on 7/16/21.
//

#ifndef UNIVERSITY_DB_DATAMANAGER_HPP
#define UNIVERSITY_DB_DATAMANAGER_HPP
#pragma once




#include <iostream>
#include <memory>
#include <deque>
#include <vector>
#include "Student.hpp"

class DataManager {
    std::deque <std::shared_ptr<Person>> deqOfPersons;
    std::string lastIndex="210000000" ;
public:
    const std::string &getLastIndex() const;
    void addToDec(const std::shared_ptr<Person>&);
    //bool deleteByIndex(const std::string&);
    bool deleteByName(const std::string&);
    bool deleteByPesel(const std::string&);
    bool searchByName(const std::string &, std::vector<std::shared_ptr<Person>>&);
    bool searchByPesel(const std::string &, std::vector<std::shared_ptr<Person>>&);
   // bool searchByIndex(const std::string &, std::vector<std::shared_ptr<Person>>&);
    bool sortByName();
    bool sortByPesel();
//    bool sortByIndex();
    void showShortWholeBase() const;
    void showLongWholeBase() const;
    void generateData(const std::vector<std::string> &, const std::vector<std::string> &,
                      const std::vector<std::string> &, const int);
    bool isPeselUnique(const std::string&);
//    bool isIndexUnique(const std::string&);
    void updateIndex();
};

/*
 * Przechowywanie rekordów studentów o strukturze: Imię, nazwisko, adres, nr indeksu, PESEL, płeć
Dodawanie nowych studentów
Wyświetlanie całej bazy danych
Wyszukiwanie po nazwisku
Wyszukiwanie po numerze PESEL
Sortowanie po numerze PESEL
Sortowanie po nazwisku
Usuwanie po numerze indeksu
 *
 */

#endif //UNIVERSITY_DB_DATAMANAGER_HPP
