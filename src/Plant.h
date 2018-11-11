#pragma once
#include "SupportTypes.h"

class Plant {
  private:
    uint32_t x;
    uint32_t y;
    uint16_t nutritional_value;

  public:
    Plant();
    ~Plant();

    //sets
    void set_x(uint32_t x);
    void set_y(uint32_t y);
    void set_nutritional_value(uint32_t nutrition_value);

    //gets
    uint32_t get_nutritional_value();
};
