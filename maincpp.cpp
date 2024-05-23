#include <iostream>
#include <memory>

#include "magic.hpp"

int main() {
    // Create an auto pointer to Magic object and call a method on it
    std::unique_ptr<Magic> myObject = Magic::create(17);
    myObject->printValue();

    return 0;
}
