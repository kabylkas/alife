#pragma once

#include "SupportTypes.h"
#include "LivingOrganisms.h"
#include <map>

class World {
  private:
    uint32_t width;
    uint32_t height;
    LivingOrganisms *liv_orgs;
    std::map<AgentType, bool**> positions;

  public:
    World();
    ~World();
    uint32_t wrap_x(int x);
    uint32_t wrap_y(int y);
    void init(uint32_t height, uint32_t width);
    // sets
    void set_width(uint32_t width);
    void set_height(uint32_t height);
    void set_liv_orgs(LivingOrganisms *liv_orgs);

    // gets
    uint32_t get_width();
    uint32_t get_height();
    LivingOrganisms* get_liv_orgs();
};
