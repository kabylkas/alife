#include "Eyes.h"

Eyes::Eyes() {

}

Eyes::~Eyes() {

}

void Eyes::observe(Direction facing, uint32_t x, uint32_t y) {
  // initialize inputs
  bool input[MEMORY_SIZE];
  for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
    input[i] = false;
  }

  // observe
  // check front
  for (uint8_t input_type = 0; input_type < INPUT_NUM; input_type++) {
    for (uint8_t type = 0; type < 3; type++) {
      for (uint8_t i = 0; i < this->offsets.x_offsets[facing].input[input_type].size(); i++) {
        uint32_t x_to_check = this->world->wrap_x(x + this->offsets.x_offsets[facing].input[input_type][i]);
        uint32_t y_to_check = this->world->wrap_y(y + this->offsets.y_offsets[facing].input[input_type][i]);
        if (this->world->positions[(AgentType)type][y_to_check][x_to_check]) {
          input[type] = true;
        }
      }
    }
  }
}

//sets
void Eyes::set_brain(Brain* brain) {
  this->brain = brain;
}

void Eyes::set_world(World* world) {
  this->world = world;
}
