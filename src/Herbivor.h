#pragma once
#include "Animal.h"
#include "LivingOrganisms.h"

#include <iostream>

class Herbivor : public Animal {
  private:
    uint32_t metabolic_rate;
    uint32_t nutritional_value;
    void eat(LivingOrganisms* liv_orgs);
    uint32_t get_metabolic_rate();

  public:
    Herbivor(uint32_t metabolic_rate);
    Herbivor();
    ~Herbivor();
    // sets
    void set_nutritional_value(uint32_t nutritional_value);
    // gets
    AgentType get_type();
    uint32_t get_nutritional_value();
};
