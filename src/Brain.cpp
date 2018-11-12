#include "Brain.h"

Brain::Brain() {
  // generate random model at creation
  for (uint8_t action_type = 0; action_type < NUM_ACTION; action_type++) {
    for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
      double d = this->get_random_double();
      this->model[action_type].push_back(d);
    }

    this->bias[action_type] = this->get_random_double();
  }
}

Brain::~Brain() {

}

void Brain::dump_model() {
  for (uint8_t action_type = 0; action_type < NUM_ACTION; action_type++) {
    std::cout << "Weights for " << (ActionType)action_type << std::endl;
    std::cout << this->bias[action_type] << std::endl;
    for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
      std::cout << this->model[action_type][i] << std::setw(10);
    }
    std::cout << std::endl;
  }
}

double Brain::get_random_double() {
  double d = (rand()/1.0) / (RAND_MAX/1.0);
  return D_MIN + d * (D_MAX - D_MIN);
}

bool Brain::change(double percent) {
  double d = (rand()/1.0) / (RAND_MAX/1.0);
  return (d <= percent);
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

void Brain::mutate(double percent) {
  for (uint8_t action_type = 0; action_type < NUM_ACTION; action_type++) {
    for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
      if (this->change(percent)) { 
        double d = this->get_random_double();
        this->model[action_type].push_back(d);
      }
    }
    if (this->change(percent)) {
      this->bias[action_type] = this->get_random_double();
    }
  }
}

// gets
bool* Brain::get_memory() {
  return short_term_memory;
}

// sets
void Brain::set_model(ActionType action_type, double* model, double bias) {
  for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
    this->model[action_type][i] = model[i];
  }
  this->bias[action_type] = bias;
}
