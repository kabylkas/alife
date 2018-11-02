#pragma once
#include "Animal.h"
#include <iostream>

class Herbivor : public Animal {
  private:
    void eat();

  public:
    Herbivor();
    ~Herbivor();
};
