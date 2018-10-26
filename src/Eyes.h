#pragma once
#include "Brain.h"

class Animal;

class Eyes {
  private:
    Brain* brain;

  public:
    Eyes();
    ~Eyes();
    void observe();
};
