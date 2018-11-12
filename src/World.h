#pragma once

#include "SupportTypes.h"
#include <map>

#include <iostream>
#include <cstdlib> //rand()
#include <assert.h>

class LivingOrganisms;

class World {
  private:
    uint32_t width;
    uint32_t height;
    bool allow_share;
    std::map<AgentType, uint8_t**> positions;

  public:
    World();
    ~World();

    uint32_t wrap_x(int x);
    uint32_t wrap_y(int y);
    void init(uint32_t height, uint32_t width, bool allow_share);
    void place_agent_rand(AgentType type, uint32_t* x, uint32_t* y);
    void place_agent_to(AgentType type, uint32_t x, uint32_t y);
    void remove_agent_from(AgentType type, uint32_t x, uint32_t y);
    bool in_place(AgentType type, uint32_t x, uint32_t y);
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
