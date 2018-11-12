#pragma once
#include "Animal.h"
#include "LivingOrganisms.h"
#include "IdGenerator.h"

#include <iostream>

class Carnivor : public Animal {
  private:
    uint32_t metabolic_rate;
    uint32_t nutritional_value;
    void eat(LivingOrganisms* lig_orgs);
    void reproduce(LivingOrganisms* lig_orgs);
    uint32_t get_metabolic_rate();

  public:
    Carnivor(uint32_t metabolic_rate);
    Carnivor();
    ~Carnivor();
    // sets
    void set_nutritional_value(uint32_t nutritional_value);
    // gets
    AgentType get_type();
    uint32_t get_nutritional_value();
};
