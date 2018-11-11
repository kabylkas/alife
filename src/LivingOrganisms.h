#pragma once
#include "SupportTypes.h"
#include <vector>
#include "Animal.h"
#include "Plant.h"

#ifdef DEBUG
#include <iostream>
#endif

class Animal;
class Plant;

class LivingOrganisms {
  public:
    uint32_t num_carnivors;
    uint32_t num_herbivors;
    uint32_t num_plants;
    std::vector<Animal*> animals;
    std::vector<Plant> plants;
    LivingOrganisms();
    ~LivingOrganisms();
};
