#pragma once
#include "SupportTypes.h"

class Brain {
  private:
    bool short_term_memory[MEMORY_SIZE]; 

  public:
    Brain();
    ~Brain();
    ActionType decide();
    void remember(bool* input);
    bool compare(bool* input);
    //gets
    bool* get_memory();
};
