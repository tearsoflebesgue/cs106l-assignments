#include <iostream>
#include "class.h"

Dog::Dog(): name{"Bruce"}, weight{10}, feeded{false} {};

Dog::Dog(std::string name, int weight, bool feeded): name{name}, weight{weight}, feeded{feeded} {};

bool Dog::is_hungry() const {
    if (feeded) {
        return false;
    } else {
        return true;
    }
}

int Dog::get_weight() const {
    if (is_hungry()) {
        std::cout << name << " is hungry" << std::endl; 
        return weight - 1;
    } else {
        std::cout << name << " is not hungry" << std::endl; 
        return weight;
    }
}

void Dog::set_weight(int value) {
    weight = value;
}