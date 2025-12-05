#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "sanctum/core/Person.h"
#include "sanctum/utils/Logger.h"

namespace py = pybind11;

PYBIND11_MODULE(SanctumPython, m) {
    m.doc() = "SanctumCore Python bindings";

    // Bind Person class
    py::class_<sanctum::core::Person>(m, "Person")
        // Constructors
        .def(py::init<>())
        .def(py::init<const std::string&, int>())
        .def(py::init<const std::string&, int, const std::string&,const std::string&>())

        // Getters
        .def("getName", &sanctum::core::Person::getName)
        .def("getAge", &sanctum::core::Person::getAge)
        .def("getEmail", &sanctum::core::Person::getEmail)
        .def("getId", &sanctum::core::Person::getId)
        .def("getPhoneNumber", &sanctum::core::Person::getPhoneNumber)


        // Setters
        .def("setName", &sanctum::core::Person::setName)
        .def("setAge", &sanctum::core::Person::setAge)
        .def("setEmail", &sanctum::core::Person::setEmail)
        .def("setPhoneNumber", &sanctum::core::Person::setPhoneNumber)

        // Business logic
        .def("isAdult", &sanctum::core::Person::isAdult)
        .def("celebrateBirthday", &sanctum::core::Person::celebrateBirthday)
        .def("getDescription", &sanctum::core::Person::getDescription)

        // Utility methods
        .def("toString", &sanctum::core::Person::toString)
        .def("display", &sanctum::core::Person::display)

        // Comparison operators
        .def("__eq__", &sanctum::core::Person::operator==)
        .def("__ne__", &sanctum::core::Person::operator!=)

        // String representation
        .def("__repr__", &sanctum::core::Person::toString)

        // Python property-style access
        .def_property("name", &sanctum::core::Person::getName, &sanctum::core::Person::setName)
        .def_property("age", &sanctum::core::Person::getAge, &sanctum::core::Person::setAge)
        .def_property("email", &sanctum::core::Person::getEmail, &sanctum::core::Person::setEmail)
        .def_property_readonly("id", &sanctum::core::Person::getId)
        .def("phoneNumber", &sanctum::core::Person::getPhoneNumber)

        // Web analysis method
        .def("analyze_text_for_matches", &sanctum::core::Person::analyzeTextForMatches);

    // Bind Logger class
    py::class_<sanctum::utils::Logger>(m, "Logger")
        .def_static("info", &sanctum::utils::Logger::info)
        .def_static("warning", &sanctum::utils::Logger::warning)
        .def_static("error", &sanctum::utils::Logger::error)
        .def_static("debug", &sanctum::utils::Logger::debug);

    // Free function
    m.def("greet", []() {
        return "Hello from SanctumCore Python bindings!";
    });
}