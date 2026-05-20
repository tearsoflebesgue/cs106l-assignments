/* File: wizard.cpp
 * Author: Preston Seay
 * 
 * This file contains practice for implementing a wizard
 * and spellbook class, as well as provides a main function
 * that can run some methods of the classes for you.
 * 
 * As an exercise, implement the wizard and spellbook
 * classes and compile and run the program.
 */
#include <iostream>
#include <string>
#include <map>
#include "wizard.h"

// ==========================
// =     CLASS 1: Wizard    =
// ==========================

// This constructor creates a new wizard, storing it's name
// and starting energy.
Wizard::Wizard(const std::string& name, int energy) {
    this->name = name;
    this->energy = energy;
}

// This function will try to use `amount` of energy.
// If the wizard has enough energy to decrease by
// amount and still be non-zero, then it will subtract
// from energy and return true. Otherwise, the energy
// should remain unchanged and it will return false.
bool Wizard::useEnergy(int amount) {
    if (amount > energy) {
        return false;
    }
    energy -= amount;
    return true;
}

// This function should simply return the amount of energy
// the wizard has left.
int Wizard::getEnergy() const {
    return energy;
}

// This should simply return the name of the wizard.
std::string Wizard::getName() const {
    return name;
}

// ==========================
// =   CLASS 2: SpellBook   =
// ==========================

// Add this spell to the spellbook.
void SpellBook::addSpell(const std::string& name, int cost) {
    spells.insert({name, cost});
}

// Try to have the wizard cast all of the spells they can.
void SpellBook::castAll(Wizard& w) {
 for (const auto& spell : spells) {
    w.useEnergy(spell.second);
 }
}

// ==========================
// =        MAIN TEST       =
// ==========================
int main() {
    Wizard w("Merlin", 50);
    SpellBook book;

    book.addSpell("Fireball", 20);
    book.addSpell("Ice", 35);
    book.addSpell("Storm", 15);

    book.castAll(w);

    std::cout << w.getName()
              << " has " << w.getEnergy()
              << " energy left\n";
}