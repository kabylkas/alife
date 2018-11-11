#pragma once
#include "SupportTypes.h"

class Plant {
  private:
    uint32_t x;
    uint32_t y;
    uint32_t nutritional_value;
    bool dead;

  public:
    Plant();
    ~Plant();
    bool is_alive();
    bool is_dead();
    void die();

    //sets
    void set_x(uint32_t x);
    void set_y(uint32_t y);
    void set_nutritional_value(uint32_t nutrition_value);

    //gets
    uint32_t get_nutritional_value();
    uint32_t get_x();
    uint32_t get_y();
    AgentType get_type();
};
