#include <iostream>
#include <ctime>
#include "Student.hpp"
#include "DataManager.hpp"
#include "UI.hpp"

void updateIndex(std::string&);



int main() {
    srand(time(NULL));
    std::vector<std::string>names = {"Smith", "Morgan", "Biden", "Obama", "Dzong Un","Ketchum"};
    std::vector<std::string>forenames = {"Alex", "Ali", "Angel", "Ariel", "Ash", "Ashley", "Kim", "Bay", "Billie",
                                         "Blue"};
    std::vector<std::string>pesels = {"019312306296", "019312306297", "019312306298", "01931230629", "019312306230", "019312306231", "019312306232", "01931230623"};

    DataManager dataManager;
    UI userInterface(dataManager);
    userInterface.getDataManager().generateData(forenames,names,pesels, 10);
    userInterface.showMenu();
    return 0;
}

//    userInterface.showMenu();
//

/*
    Person janusz{"Janusz","Kowal","02312306296", Address()};
    Student franek;
    Student janus {janusz, "019253078"};
    Student frania{"Janina","Kowal","01312306296", Gender::Female, "019253067", Address()};
    franek.setIndexNumber("019253068");
    franek.setForename("Pawel");
    franek.setName("Puchacz");
    franek.setPeselNumber("740745655");
    dataManager.addToDec(std::make_shared<Student>(franek));
    dataManager.addToDec(std::make_shared<Student>(janus));
    dataManager.addToDec(std::make_shared<Student>(frania));
    dataManager.showWholeBase();
    void show_vec (const std::vector<std::shared_ptr<Student>>&);
    std::cout<<"\n\n";
    std::vector<std::shared_ptr<Student>>vec;
    dataManager.searchByLetters("Pua", vec);
    show_vec(vec);
    dataManager.sortByName();
    dataManager.showWholeBase();
    dataManager.sortByPesel();
    dataManager.showWholeBase();
*/