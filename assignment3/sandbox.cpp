/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include <iostream>
#include "class.h"
void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  Dog d {"Wangcai", 11, false};

  d.set_weight(12);

  int actualweight = d.get_weight();

  std::cout << "Actual weight is :" << actualweight << std::endl;

}