#ifndef SANCTUM_CORE_PERSON_H
#define SANCTUM_CORE_PERSON_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

namespace sanctum {
    namespace core {

        class Person {
        public:
            // Constructors
            Person();
            Person(const std::string& name, int age);
            Person(const std::string& name, int age, const std::string& email);

            // Getters
            std::string getName() const;
            int getAge() const;
            std::string getEmail() const;
            int getId() const;

            // Setters
            void setName(const std::string& name);
            void setAge(int age);
            void setEmail(const std::string& email);

            // Business logic methods
            bool isAdult() const;
            void celebrateBirthday();
            std::string getDescription() const;

            // Utility methods
            std::string toString() const;
            void display() const;

            // Comparison operators
            bool operator==(const Person& other) const;
            bool operator!=(const Person& other) const;

            // Web scraping analysis method
            std::map<std::string, int> analyzeTextForMatches(const std::vector<std::string>& textData) const;

        private:
            static int nextId;
            int id;
            std::string name;
            int age;
            std::string email;
        };

    } // namespace core
} // namespace sanctum

#endif // SANCTUM_CORE_PERSON_H