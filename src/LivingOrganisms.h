#pragma once
#include "SupportTypes.h"
#include "IdGenerator.h"
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
    IdGenerator* id_generator;
    uint32_t num_carnivors;
    uint32_t num_herbivors;
    uint32_t num_plants;
    std::vector<Animal*> animals;
    std::vector<Plant> plants;
    LivingOrganisms();
    ~LivingOrganisms();
    void set_id_generator(IdGenerator* id_generator);
};
