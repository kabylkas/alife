#include "Eyes.h"

Eyes::Eyes() {

}

Eyes::~Eyes() {

}

void Eyes::observe() {
  bool input[MEMORY_SIZE];
  for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
    input[i] = false;
  }

  owner->get_brain()->remember(input);
}
