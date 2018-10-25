#include "Brain.h"

Brain::Brain() {

}

Brain::~Brain() {

}

uint8_t Brain::decide() {

}

void Brain::remember(bool* input) {
  for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
    this->short_term_memory[i] = input[i];
  }
}
