#pragma once

#include "SupportTypes.h"
#include "Animal.h"
#include "Plant.h"
#include "LivingOrganisms.h"
#include <vector>

class World {
  private:
    uint32_t world_width;
    uint32_t world_height;
    LivingOrganisms *liv_orgs;

  public:
    World();
    ~World();
    uint32_t wrap_x(int x);
    uint32_t wrap_y(int y);
    // sets
    void set_width(uint32_t width);
    void set_height(uint32_t height);
    void set_animals(std::vector<Animal*> *animals);
    void set_plants(std::vector<Plant> *plants);

    // gets
    uint32_t get_width();
    uint32_t get_height();
    std::vector<Animal*>* get_animals();
    std::vector<Plant>* get_plants();
};
