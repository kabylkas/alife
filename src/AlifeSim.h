#pragma once

#include "SupportTypes.h"
#include "Animal.h"
#include "Plant.h"
#include "World.h"
#include "LivingOrganisms.h"
#include <fstream>
#include <string>
#include <iostream>

class AlifeSim {
  private:
    LivingOrganisms liv_orgs;
    World world;
    bool read_config_file(std::string cfg_file_name);


  public:
    AlifeSim();
    ~AlifeSim();
    void init(std::string cfg_file_name);
    void start();
};
