//
// Created by bartek on 7/16/21.
//

#ifndef UNIVERSITY_DB_UI_HPP
#define UNIVERSITY_DB_UI_HPP

#include <iostream>
#include "DataManager.hpp"

class UI {
    DataManager dataManager;
public:
    DataManager &getDataManager();
    UI (const DataManager&);
    UI ();
    void showMenu();
    std::string chooseMainOptions()const ;
    void showSortMenu();
    void showDeleteMenu();
    void showSearchMenu();
    void showDisplayMenu();
    std::string chooseSortOptions()const ;
    std::string chooseDeleteOptions()const ;
    std::string chooseSearchOptions()const ;
    std::string chooseDisplayOptions()const ;
    void addStudent();
    void addPerson();
    void addEmployee();


};


#endif //UNIVERSITY_DB_UI_HPP
