#include "Brain.h"

Brain::Brain() {

}

Brain::~Brain() {

}

ActionType Brain::decide() {

}

void Brain::remember(bool* input) {
  for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
    this->short_term_memory[i] = input[i];
  }
}

bool Brain::compare(bool* input) {
  bool result = true;

  for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
    if (this->short_term_memory[i] != input[i]) {
      result = false;
      break;
    }
  }

  return result;
}

bool* Brain::get_memory() {
  return short_term_memory;
}
