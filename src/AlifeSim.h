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
#include <cassert>
#include <cstdlib> //rand()

class AlifeSim {
  private:
    LivingOrganisms liv_orgs;
    World world;
    bool read_config_file(std::string cfg_file_name);
    IdGenerator id_generator;

  public:
    AlifeSim();
    ~AlifeSim();
    void init(std::string cfg_file_name);
    void start();
    void sustain();
    Configs sim_configs;
};
