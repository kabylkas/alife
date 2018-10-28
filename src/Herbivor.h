#pragma once
#include "Animal.h"

class Herbivor : public Animal {
  private:
    void eat();

  public:
    Herbivor();
    ~Herbivor();
};
