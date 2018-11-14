#pragma once

#include "SupportTypes.h"
#include "IdGenerator.h"
#include "Animal.h"
#include "Carnivor.h"
#include "Herbivor.h"
#include "Plant.h"
#include "World.h"
#include "LivingOrganisms.h"
#include "Configs.h"

#include <string>
#include <iostream>
#include <assert.h>
#include <cstdlib> //rand()

class AlifeSim {
  private:
    LivingOrganisms liv_orgs;
    World world;
    bool read_config_file(std::string cfg_file_name);
    IdGenerator id_generator;
    Animal* get_random_herbivor();
    Animal* get_random_carnivor();
    Plant get_random_plant();
    Offsets offsets;

  public:
    AlifeSim();
    ~AlifeSim();
    void init(std::string cfg_file_name);
    void start();
    void sustain();
    Configs sim_configs;
    uint64_t max_age;
    uint64_t max_population;
    uint64_t carn_reproductions_happened;
    uint64_t herb_reproductions_happened;
    uint64_t carn_death_happened;
    uint64_t herb_death_happened;
    uint64_t plants_eatan;
    uint64_t herbs_eatan;
};
