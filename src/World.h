#pragma once

#include "SupportTypes.h"
#include "LivingOrganisms.h"
#include <vector>

class World {
  private:
    uint32_t width;
    uint32_t height;
    LivingOrganisms *liv_orgs;

  public:
    World();
    ~World();
    uint32_t wrap_x(int x);
    uint32_t wrap_y(int y);
    // sets
    void set_width(uint32_t width);
    void set_height(uint32_t height);
    void set_liv_orgs(LivingOrganisms *liv_orgs);

    // gets
    uint32_t get_width();
    uint32_t get_height();
    LivingOrganisms* get_liv_orgs();
};
