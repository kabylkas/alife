#pragma once
#include  "SupportTypes.h"
#include "Brain.h"
#include "Eyes.h"

class World;

class Animal {
  protected:
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
    Animal();
    ~Animal();
    void take_action();
    void set_world(World* world);
    Brain* get_brain();

};
