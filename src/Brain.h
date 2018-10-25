#pragma once
#include "SupportTypes.h"
#include "Animal.h"

class Animal;

class Brain {
  private:
    Animal* owner;
    bool short_term_memory[MEMORY_SIZE]; 

  public:
    Brain();
    ~Brain();
    uint8_t decide();
    void remember(bool* input);
};
