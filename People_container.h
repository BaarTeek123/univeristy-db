//
// Created by bartek on 9/1/21.
//

#ifndef UNIVERSITY_DB_PEOPLE_CONTAINER_H
#define UNIVERSITY_DB_PEOPLE_CONTAINER_H

#include "Person.hpp"
#include <iostream>
#include <memory>
#include <vector>

class People_container {
  std::vector<std::shared_ptr<Person>> container;



};

#endif // UNIVERSITY_DB_PEOPLE_CONTAINER_H
