#include "Brain.h"

Brain::Brain() {
  // generate random model at creation
  for (uint8_t action_type = 0; action_type < NUM_ACTION; action_type++) {
    for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
      double d = this->get_random_double();
      model[action_type].push_back(d);
    }
  }
}

Brain::~Brain() {

}

double Brain::get_random_double() {
  double d = rand() / RAND_MAX; 
  return D_MIN + d * (D_MAX - D_MIN);
}

ActionType Brain::decide() {
  double max_sum = -10000;
  uint8_t max_action;

  for (uint8_t action_type = 0; action_type < NUM_ACTION; action_type++) {
    double action_sum = 0;
    for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
      action_sum += short_term_memory[i] * model[action_type][i];
    }
    action_sum += bias[action_type];

    if (action_sum > max_sum) {
      max_sum = action_sum;
      max_action = action_type;
    }
  }

  return (ActionType)max_action;
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
