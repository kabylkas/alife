#pragma once
#include  "SupportTypes.h"
#include "Brain.h"
#include "Eyes.h"
#include "LivingOrganisms.h"

class Animal {
  protected:
    Eyes eyes;
    Brain brain;
    uint32_t x;
    uint32_t y;
    Direction facing;
    uint16_t energy_level;
    uint64_t age;
    uint64_t id;

    // Actions
    void move();
    virtual void eat() {};
    void turn_left();
    void turn_right();
    virtual uint32_t get_metabolic_rate() {};

  public:
    Animal();
    ~Animal();
    // others
    void take_action(LivingOrganisms* liv_orgs);
    void increment_age();
    //sets
    void set_world(World* world);
    void set_x(uint32_t x);
    void set_y(uint32_t y);
    void set_direction(Direction facing);
    void set_energy(uint16_t energy_level);
    void set_id(uint64_t id);

    //gets
    Brain* get_brain();

};
