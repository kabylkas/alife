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
    uint32_t x;
    uint32_t y;
    Direction facing;
    uint16_t energy_level;

    // Actions
    void move();
    virtual void eat();
    void turn_left();
    void turn_right();

  public:
    Animal();
    ~Animal();
    // others
    void take_action();

    //sets
    void set_world(World* world);
    void set_x(uint32_t x);
    void set_y(uint32_t y);
    void set_direction(Direction facing);
    void set_energy(uint16_t energy_level);

    //gets
    Brain* get_brain();

};
