cmake_minimum_required(VERSION 3.17)
project(university_db)

set(CMAKE_CXX_STANDARD 20)

add_executable(university_db main.cpp Person.cpp Person.hpp Employee.cpp Student.cpp Student.hpp DataManager.cpp DataManager.hpp UI.cpp UI.hpp Address.cpp Address.hpp Employee.cpp Employee.hpp)