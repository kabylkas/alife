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
  private:
    IdGenerator* id_generator;
    uint32_t num_carnivors;
    uint32_t num_herbivors;
    uint32_t num_plants;
    std::vector<Animal*> animals;
    std::vector<Plant> plants;

  public:
    LivingOrganisms();
    ~LivingOrganisms();
    void add_animal(Animal* animal);
    void remove_animal(uint32_t i);
    void add_plant(Plant plant);
    void remove_plant(uint32_t i);
    // sets
    void set_id_generator(IdGenerator* id_generator);

    //gets
    Animal* get_animal(uint32_t i);
    Plant* get_plant(uint32_t i);
    uint32_t get_num_carnivors();
    uint32_t get_num_herbivors();
    uint32_t get_num_animals();
    uint32_t get_num_plants();
};
