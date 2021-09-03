//
// Created by bartek on 7/16/21.
//

#include "UI.hpp"
#include "Address.hpp"
#include <chrono>
#include <thread>

std::string UI::chooseMainOptions() const {
  system("clear");
  std::cout << "Student Base program. Choose option which You want to do. "
            << std::endl;
  std::cout << "'a'/\"add\"- add student \n";
  std::cout << "'d'/\"display\"- display whole base \n";
  std::cout << "'r'/\"reverse\"- reverse student \n";
  std::cout << "'s'/\"search\"- search";
  std::cout << "\n'p'/\"sort\" - sort base\n";
  std::cout << "'q'/\"quit\" - quit \n";
  std::cout << "Your choice: ";
  std::string x;
  std::getline(std::cin, x);
  return x;
}

bool compareChar(char &c1, char &c2) {
  if ((c1 == c2) || (std::toupper(c1) == std::toupper(c2)))
    return true;
  return false;
}

bool caseIgnoreStringCompare(const std::string &str1, const std::string &str2) {
  return std::equal(
      str1.begin(), str1.end(), str2.begin(), str2.end(),
      [](char str1, char str2) { return tolower(str1) == tolower(str2); });
}

/*
bool caseIgnoreStringCompare(const std::string & str1, const std::string &str2)
{
    if (str1.size() != str2.size())
        return false;
    for (int i = 0 ; i < str1.size(); i++){
        if (tolower(str1[i])!= tolower(str2[i]))
            return false;
    }
    return true;
}*/

void UI::showMenu() {
  while (true) {
    system("clear");
    std::string choice = chooseMainOptions();
    if ((caseIgnoreStringCompare(choice, "q")) ||
        (caseIgnoreStringCompare(choice, "quit"))) {
      return;
    } else if ((caseIgnoreStringCompare(choice, "a")) ||
               (caseIgnoreStringCompare(choice, "add"))) {
      addStudent();
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << "You have just succesfully added student to the base."
                << std::endl; // add
    } else if ((caseIgnoreStringCompare(choice, "d")) ||
               (caseIgnoreStringCompare(choice, "display"))) {
      showDisplayMenu();
    } else if ((caseIgnoreStringCompare(choice, "r")) ||
               (caseIgnoreStringCompare(choice, "reverse"))) {
      showDeleteMenu();
      // reverse
    } else if ((caseIgnoreStringCompare(choice, "s")) ||
               (caseIgnoreStringCompare(choice, "search"))) {
      showSearchMenu();
    } else if ((caseIgnoreStringCompare(choice, "p")) ||
               (caseIgnoreStringCompare(choice, "sort"))) {
      showSortMenu();
    }
    std::cout << "\n\nPress ENTER to continue.\n\n" << std::endl;
    std::cin.get();
  }
}

void UI::showDeleteMenu() {
  system("clear");
  std::string choice = chooseDeleteOptions();
  std::string data;
  std::cout << "Input data: ";
  std::cin >> data;

  if ((caseIgnoreStringCompare(choice, "q")) ||
      (caseIgnoreStringCompare(choice, "quit"))) {
    return;
  } else {
    system("clear");
  }
  if ((caseIgnoreStringCompare(choice, "n")) ||
      (caseIgnoreStringCompare(choice, "name"))) {
    if (dataManager.deleteByName(data))
      std::cout << "You have just succesfully deleted student from the base.\n";
    else
      std::cout << "Deleting student failed.\n";
  } else if ((caseIgnoreStringCompare(choice, "p")) ||
             (caseIgnoreStringCompare(choice, "pesel"))) {
    if (dataManager.deleteByPesel(data)) {
      std::cout << "You have just succesfully deleted student from the base.\n";
    } else
      std::cout << "Deleting student failed.\n"; // reverse
  } else if ((caseIgnoreStringCompare(choice, "i")) ||
             (caseIgnoreStringCompare(choice, "index"))) {
/*    if (dataManager.deleteByIndex(data)) {
      std::cout << "You have just succesfully deleted student from the base.\n";
    } else
      std::cout << "Deleting student failed.\n";
  }
  */
}
}

void UI::showSearchMenu() {
  system("clear");
  std::string choice = chooseSearchOptions();
  std::string data;
  if ((caseIgnoreStringCompare(choice, "q")) ||
      (caseIgnoreStringCompare(choice, "quit"))) {
    return;
  } else {
    system("clear");
  }
  std::vector<std::shared_ptr<Person>> vec;
  if ((caseIgnoreStringCompare(choice, "n")) ||
      (caseIgnoreStringCompare(choice, "name"))) {
    if (dataManager.searchByName(data, vec))
      for (auto &student : vec) {
        std::cout << *student << std::endl;
        std::cout << (*student).getAddress() << std::endl;
      }
    else
      std::cout << "No found.\n";
  } else if ((caseIgnoreStringCompare(choice, "p")) ||
             (caseIgnoreStringCompare(choice, "pesel"))) {
    if (dataManager.searchByPesel(data, vec)) {
      for (auto &student : vec) {
        std::cout << *student << std::endl;
        std::cout << "Address: " << (*student).getAddress() << std::endl;
      }
    } else {
      std::cout << "No found.\n";
    }
  }
//////////////
  /*
   else if ((caseIgnoreStringCompare(choice, "i")) ||
             (caseIgnoreStringCompare(choice, "index"))) {
    if (dataManager.searchByIndex(data, vec)) {
      for (auto &student : vec) {
        std::cout << *student << std::endl;
        std::cout << (*student).getAddress() << std::endl;
      }
    }
  else
      std::cout << "No found.\n";
  }*/
}

void UI::showSortMenu() {
  system("clear");
  std::string choice = chooseSortOptions();
  std::string data;
  if ((caseIgnoreStringCompare(choice, "q")) ||
      (caseIgnoreStringCompare(choice, "quit"))) {
    return;
  } else
    system("clear");
  if ((caseIgnoreStringCompare(choice, "n")) ||
      (caseIgnoreStringCompare(choice, "name"))) {
    if (dataManager.sortByName())
      std::cout << "Succesfully sorted. " << std::endl;

    else
      std::cout << "There is no data to sort. " << std::endl;
  } else if ((caseIgnoreStringCompare(choice, "p")) ||
             (caseIgnoreStringCompare(choice, "pesel"))) {
    if (dataManager.sortByPesel())
      std::cout << "Succesfully sorted. " << std::endl;

    else
      std::cout << "There is no data to sort. " << std::endl;
  }
  ////////////////////////////////////////
  /*
  else if ((caseIgnoreStringCompare(choice, "i")) ||
             (caseIgnoreStringCompare(choice, "index"))) {
    if (dataManager.sortByIndex())
      std::cout << "Succesfully sorted. " << std::endl;
    else
      std::cout << "There is no data to sort. " << std::endl;
  }*/
}

void UI::showDisplayMenu() {
  std::string choice = chooseDisplayOptions();
  if ((caseIgnoreStringCompare(choice, "s")) ||
      (caseIgnoreStringCompare(choice, "short"))) {
    dataManager.showShortWholeBase();

  } else {
    dataManager.showLongWholeBase();
  }
}

std::string UI::chooseSortOptions() const {
  std::cout << "Choose a feature that you want to sort by. " << std::endl;
  std::cout << "'n'/\"name\"- students' name \n";
  std::cout << "'p'/\"pesel\"- student's pesel  \n";
  //std::cout << "'i'/\"index\"- student's index\n";
  std::cout << "'q'/\"quit\" - quit \n";
  std::cout << "Your choice: ";
  std::string x;
  std::getline(std::cin, x);
  return x;
}

std::string UI::chooseDisplayOptions() const {
  std::cout << "Choose display option: " << std::endl;
  std::cout << "'s'/\"short\"- short info \n";
  std::cout << "'e'/\"extended\"- extended info  \n";
  std::cout << "Your choice: ";
  std::string x;
  std::getline(std::cin, x);
  return x;
}

std::string UI::chooseSearchOptions() const {
  std::cout << "Choose a feature that you want to search. " << std::endl;
  std::cout << "'n'/\"name\"- students' name \n";
  std::cout << "'p'/\"pesel\"- student's pesel  \n";
//  std::cout << "'i'/\"index\"- student's index";
  std::cout << "\n'q'/\"quit\" - quit \n";
  std::cout << "Your choice: ";
  std::string x;
  std::getline(std::cin, x);
  return x;
}

std::string UI::chooseDeleteOptions() const {
  std::cout << "Choose a feature that you want to delete by. " << std::endl;
  std::cout << "'n'/\"name\"- students' name \n";
  std::cout << "'p'/\"pesel\"- student's pesel  \n";
//  std::cout << "'i'/\"index\"- student's index\n";
  std::cout << "'q'/\"quit\" - quit \n";
  std::cout << "Your choice: ";
  std::string x;
  std::getline(std::cin, x);
  return x;
}

UI::UI(const DataManager &dataMan) : dataManager(dataMan) {}

DataManager &UI::getDataManager() { return dataManager; }


Address setAddress(Address &);

//void UI::addPerson(){


UI::UI() : dataManager(DataManager()) {}
