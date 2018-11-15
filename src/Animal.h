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
    bool killed;

    // Actions
    void move();
    virtual void eat(LivingOrganisms* liv_orgs) {};
    void turn_left();
    void turn_right();
    virtual void reproduce(LivingOrganisms* liv_orgs) {};

  public:
    Animal();
    ~Animal();
    // others
    void take_action(LivingOrganisms* liv_orgs);
    void increment_age();
    void die(bool killed);
    void new_born_reset(uint64_t id);
    bool is_alive();
    bool is_dead();
    bool is_killed();
    virtual AgentType get_type() { return (AgentType)0; };
    virtual uint32_t get_metabolic_rate() { return 0; };
    virtual uint32_t get_nutritional_value() { return 0; };

    //sets
    void set_world(World* world);
    void set_offsets(Offsets* offsets);
    void set_x(uint32_t x);
    void set_y(uint32_t y);
    void set_direction(Direction facing);
    void set_energy(int energy_level);
    void set_id(uint64_t id);
    void set_age(uint64_t age);
    virtual void set_nutritional_value(uint32_t nutritional_value) {};

    //gets
    Brain* get_brain();
    uint64_t get_id();
    uint32_t get_x();
    uint32_t get_y();
    uint64_t get_age();
    int get_energy();

};
