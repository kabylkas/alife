#pragma once
#include "SupportTypes.h"

class Plant {
  private:
    uint32_t x;
    uint32_t y;
    uint16_t nutrition_level;

  public:
    Plant();
    ~Plant();

    //sets
    void set_x(uint32_t x);
    void set_y(uint32_t y);
    void set_nutrition_level(uint16_t nutrition_level);
};
