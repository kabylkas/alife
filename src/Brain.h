#pragma once
#include "SupportTypes.h"

#include <cstdlib> //rand()

class Brain {
  private:
    bool short_term_memory[MEMORY_SIZE]; 
    // model/neural nets
    std::vector<double> model[NUM_ACTION];
    double bias[NUM_ACTION];

  public:
    Brain();
    ~Brain();
    double get_random_double();
    ActionType decide();
    void remember(bool* input);
    bool compare(bool* input);
    //gets
    bool* get_memory();
};
