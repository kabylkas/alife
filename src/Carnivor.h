#pragma once
#include "Animal.h"

class Carnivor : public Animal {
  private:
    void eat();

  public:
    Carnivor();
    ~Carnivor();
};
