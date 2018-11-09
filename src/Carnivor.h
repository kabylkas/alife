#pragma once
#include "Animal.h"
#include <iostream>

class Carnivor : public Animal {
  private:
    uint32_t metabolic_rate;

    void eat();
    uint32_t get_metabolic_rate();

  public:
    Carnivor(uint32_t metabolic_rate);
    Carnivor();
    ~Carnivor();
};
