#pragma once
#include "Animal.h"
#include "Brain.h"

class Animal;

class Eyes {
  private:
    Animal* owner;

  public:
    Eyes();
    ~Eyes();
    void observe();
};
