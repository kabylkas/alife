#pragma once

#include <vector>
#include <string>
#include "Animal.h"
#include "Plant.h"
#include "World.h"

class AlifeSim {
  private:
    std::vector<*Animal> animals;
    std::vector<Plant> plants;
    World world;

  public:
    AlifeSim();
    ~AlifeSim();
    void init(std::string cfg_file);
    void start();
};
