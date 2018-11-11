#pragma once
#include  "SupportTypes.h"
#include "Brain.h"
#include "Eyes.h"
#include "LivingOrganisms.h"

class Animal {
  protected:
    Eyes eyes;
    Brain brain;
    int energy_level;
    uint64_t age;
    uint64_t id;
    uint32_t x;
    uint32_t y;
    Direction facing;
    AgentType type;
    AgentType food_type;
    bool dead;

    // Actions
    void move();
    virtual void eat(LivingOrganisms* liv_orgs) {};
    void turn_left();
    void turn_right();

  public:
    Animal();
    ~Animal();
    // others
    void take_action(LivingOrganisms* liv_orgs);
    void increment_age();
    void update_position();
    void die();
    bool is_alive();
    bool is_dead();
    virtual AgentType get_type() {};
    virtual uint32_t get_metabolic_rate() {};
    virtual uint32_t get_nutritional_value() {};

    //sets
    void set_world(World* world);
    void set_x(uint32_t x);
    void set_y(uint32_t y);
    void set_direction(Direction facing);
    void set_energy(int energy_level);
    void set_id(uint64_t id);
    virtual void set_nutritional_value(uint32_t nutritional_value) {};

    //gets
    Brain* get_brain();
    uint64_t get_id();
    uint32_t get_x();
    uint32_t get_y();

};
