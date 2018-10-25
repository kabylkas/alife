#pragma once

#include "SupportTypes.h"
#include <string>
#include "Animal.h"
#include "Plant.h"
#include "World.h"
#include "LivingOrganisms.h"
#include <iostream>

class AlifeSim {
  private:
    LivingOrganisms liv_orgs;
    World world;

  public:
    AlifeSim();
    ~AlifeSim();
    void init(std::string cfg_file);
    void start();
};
