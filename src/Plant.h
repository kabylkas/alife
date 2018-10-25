#pragma once
#include "SupportTypes.h"

class Plant {
  private:
    uint16_t x;
    uint16_t y;
    uint16_t nutrition_level;

  public:
    Plant(uint16_t x, uint16_t y);
    ~Plant();
};
