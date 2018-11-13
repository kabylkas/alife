#pragma once
#include "SupportTypes.h"

#include <cstdlib> //rand()
#include <iostream>
#include <iomanip>

class Brain {
  private:
    bool short_term_memory[MEMORY_SIZE]; 
    // model/neural nets
    double model[NUM_ACTION][MEMORY_SIZE];
    double bias[NUM_ACTION];
    double get_random_double();

  public:
    Brain();
    ~Brain();
    void dump_model();
    ActionType decide();
    void remember(bool* input);
    bool compare(bool* input);
    void mutate(double percent);
    bool change(double percent);
    void transfer(Brain* brain);

    // gets
    bool* get_memory();

    // sets
    void set_model(ActionType action_type, double* model, double bias);
};
