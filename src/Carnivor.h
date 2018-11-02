#pragma once
#include "Animal.h"
#include <iostream>

class Carnivor : public Animal {
  private:
    void eat();

  public:
    Carnivor();
    ~Carnivor();
};
