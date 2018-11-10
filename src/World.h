#pragma once

#include "SupportTypes.h"
#include <map>

#include <cstdlib> //rand()
#include <iostream>

class LivingOrganisms;
class World {
  private:
    uint32_t width;
    uint32_t height;

  public:
    World();
    ~World();
    std::map<AgentType, bool**> positions;

    uint32_t wrap_x(int x);
    uint32_t wrap_y(int y);
    void init(uint32_t height, uint32_t width);
    void place_agent_rand(AgentType type, uint32_t* x, uint32_t* y, bool allow_share);
    void place_agent_to(AgentType type, uint32_t x, uint32_t y);
    void remove_agent_from(AgentType type, uint32_t x, uint32_t y);
    void clear_positions();

    // sets
    void set_width(uint32_t width);
    void set_height(uint32_t height);

    // gets
    uint32_t get_width();
    uint32_t get_height();

    // debug
    void draw_positions(AgentType type);
    void draw_positions();
};
