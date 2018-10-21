#pragma once
#include  "SupportTypes.h"

class Animal {
  private:
    World* my_world;
    Eyes eyes;
    Brain brain;
    uint16_t x;
    uint16_t y;
    Direction facing;
    uint8_t energy_level;

    // Actions
    void move();
    void eat();
    void turn_left();
    void turn_right();
  public:
    void take_action();
};
