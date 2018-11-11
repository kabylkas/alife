#pragma once
#include "SupportTypes.h"
#include "Brain.h"
#include "World.h"

class Animal;

class Eyes {
  private:
    Offsets offsets;
    Brain* brain;
    World* world;

  public:
    Eyes();
    ~Eyes();
    void observe(Direction facing, uint32_t x, uint32_t y);
    bool in_proximity(AgentType type, uint32_t input_x, uint32_t input_y, Direction facing, uint32_t* output_x, uint32_t* output_y);
    uint32_t wrap_x(int x);
    uint32_t wrap_y(int y);

    //sets
    void set_brain(Brain* brain);
    void set_world(World* world);

    //gets
    World* get_world();
};
