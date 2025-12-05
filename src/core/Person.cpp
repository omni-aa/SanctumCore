#include "sanctum/core/Person.h"
#include <sstream>
#include <algorithm>
#include <cctype>

namespace sanctum {
    namespace core {

        // Initialize static member
        int Person::nextId = 1;

        // Constructors
        Person::Person() : id(nextId++), name("Unknown"), age(0), email("") {}
        Person::Person(const std::string& name, int age)
            : id(nextId++), name(name), age(age), email("") {}
        Person::Person(const std::string& name, int age, const std::string& email, const std::string& phone_number,const std::string& DOB)
            : id(nextId++), name(name), age(age), email(email),phone_number(phone_number), DOB(DOB){}

        // Getters
        std::string Person::getName() const { return name; }
        int Person::getAge() const { return age; }
        std::string Person::getEmail() const { return email; }
        int Person::getId() const { return id; }
        std::string Person::getPhoneNumber() const { return phone_number; }
        std::string Person::getDOB() const { return DOB; }

        // Setters
        void Person::setName(const std::string& name) { this->name = name; }
        void Person::setAge(int age) { this->age = age; }
        void Person::setEmail(const std::string& email) { this->email = email; }
        void Person::setPhoneNumber(std::string& phone_number) { this->phone_number = phone_number; }
        void Person::setDOB(const std::string& DOB) { this->DOB = DOB; }

        // Business logic methods
        bool Person::isAdult() const { return age >= 18; }

        void Person::celebrateBirthday() {
            age++;
        }

        std::string Person::getDescription() const {
            std::stringstream ss;
            ss << name << " (" << age << " years old)";
            if (!email.empty()) {
                ss << " - " << email;
            }
            return ss.str();
        }

        // Utility methods
        std::string Person::toString() const {
            std::stringstream ss;
            ss << "Person{ID: " << id << ", Name: \"" << name << "\", Age: " << age;
            if (!email.empty()) {
                ss << ", Email: \"" << email << "\"";
            }
            ss << "}";
            return ss.str();
        }

        void Person::display() const {
            std::cout << toString() << std::endl;
        }

        // Comparison operators
        bool Person::operator==(const Person& other) const {
            return id == other.id && name == other.name && age == other.age && email == other.email;
        }

        bool Person::operator!=(const Person& other) const {
            return !(*this == other);
        }

        // Web scraping analysis method
        std::map<std::string, int> Person::analyzeTextForMatches(const std::vector<std::string>& textData) const {
            std::map<std::string, int> results = {
                {"name_matches", 0},
                {"age_matches", 0},
                {"combined_matches", 0},
                {"total_texts_analyzed", 0},
                {"exact_name_matches", 0}
            };

            for (const auto& text : textData) {
                bool has_exact_name = false;
                bool has_age = false;

                // EXACT NAME CHECK - Only match "John Doe", not "John Parker"
                if (name != "Unknown" && !name.empty()) {
                    std::string lower_text = text;
                    std::transform(lower_text.begin(), lower_text.end(), lower_text.begin(), ::tolower);
                    std::string lower_name = name;
                    std::transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);

                    // Check for exact full name match
                    size_t pos = lower_text.find(lower_name);
                    while (pos != std::string::npos) {
                        // Check if it's a whole word match
                        bool start_ok = (pos == 0) || !std::isalnum(lower_text[pos - 1]);
                        bool end_ok = ((pos + lower_name.length()) >= lower_text.length()) ||
                                     !std::isalnum(lower_text[pos + lower_name.length()]);

                        if (start_ok && end_ok) {
                            has_exact_name = true;
                            break;
                        }
                        pos = lower_text.find(lower_name, pos + 1);
                    }
                }

                // AGE CHECK
                has_age = (text.find(std::to_string(age)) != std::string::npos);

                if (has_exact_name) {
                    results["exact_name_matches"]++;
                    results["name_matches"]++;
                }
                if (has_age) results["age_matches"]++;
                if (has_exact_name && has_age) results["combined_matches"]++;
            }

            results["total_texts_analyzed"] = textData.size();
            return results;
        }

    } // namespace core
} // namespace sanctum