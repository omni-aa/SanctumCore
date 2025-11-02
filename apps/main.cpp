#include <iostream>
#include "../include/sanctum/core/Person.h"
#include "../include/sanctum/utils/Logger.h"

using namespace sanctum::core;
using namespace sanctum::utils;

int main() {
    Logger::info("SanctumCore Application Started");

    // Create some Person objects
    Person person1("Alice", 25, "alice@example.com");
    Person person2("Bob", 17);
    Person person3;
    person3.setName("Charlie");
    person3.setAge(30);
    person3.setEmail("charlie@example.com");

    // Display persons
    std::cout << "\n=== Person Information ===" << std::endl;
    person1.display();
    person2.display();
    person3.display();

    // Test business logic
    std::cout << "\n=== Business Logic ===" << std::endl;
    std::cout << person1.getName() << " is adult: " << person1.isAdult() << std::endl;
    std::cout << person2.getName() << " is adult: " << person2.isAdult() << std::endl;

    // Celebrate birthday
    std::cout << "\n=== Birthday Celebration ===" << std::endl;
    std::cout << "Before: " << person2.getDescription() << std::endl;
    person2.celebrateBirthday();
    std::cout << "After: " << person2.getDescription() << std::endl;

    Logger::info("SanctumCore Application Finished");
    return 0;
}