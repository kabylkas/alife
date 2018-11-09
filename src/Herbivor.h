#pragma once
#include "Animal.h"
#include <iostream>

class Herbivor : public Animal {
  private:
    uint32_t metabolic_rate;

    void eat();
    uint32_t get_metabolic_rate();

  public:
    Herbivor(uint32_t metabolic_rate);
    Herbivor();
    ~Herbivor();
};
