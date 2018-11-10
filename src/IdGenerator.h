#pragma once
#include "SupportTypes.h"

class IdGenerator {
  private:
    uint64_t id;

  public:
    IdGenerator();
    ~IdGenerator();
    uint64_t get_id();
};
