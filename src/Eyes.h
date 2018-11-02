#pragma once
#include "SupportTypes.h"
#include "Brain.h"
#include "World.h"

class Animal;

class Eyes {
  private:
    Offsets offsets;
    Brain* brain;
    World* world;

  public:
    Eyes();
    ~Eyes();
    void observe(Direction facing);

    //sets
    void set_brain(Brain* brain);
    void set_world(World* world);
};
