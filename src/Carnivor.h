#pragma once
#include "Animal.h"
#include "LivingOrganisms.h"

#include <iostream>

class Carnivor : public Animal {
  private:
    uint32_t metabolic_rate;
    AgentType type;
    AgentType food_type;

    void eat(LivingOrganisms* lig_orgs);
    uint32_t get_metabolic_rate();

  public:
    Carnivor(uint32_t metabolic_rate);
    Carnivor();
    ~Carnivor();
    AgentType get_type();
};
