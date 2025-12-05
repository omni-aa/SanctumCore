#include <iostream>
#include "../include/sanctum/core/Person.h"
#include "../include/sanctum/utils/Logger.h"

using namespace sanctum::core;
using namespace sanctum::utils;


enum Level {
    LOW = 25,
    MEDIUM = 50,
    HIGH = 75
  };
int main() {

    std::string food = "Pizza";
    std::string &meal = food;

    meal = "Burger";

    std::cout << meal << std::endl;
    std::cout << food << std::endl;

    enum Level myvar = MEDIUM;
    std::cout << myvar << std::endl;
    struct {
        int mynum;
        std::string myString;
    }myStructure;


    myStructure.mynum = 10;
    myStructure.myString = "Hello World!";
    std::cout << myStructure.mynum << std::endl;
    std::cout << myStructure.myString << std::endl;








    return 0;
}