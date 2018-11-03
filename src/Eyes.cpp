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
  for (uint8_t type = 0; type < 3; type++) {
    for (uint8_t i = 0; i < this->offsets.x_offsets[facing].front.size(); i++) {
      uint32_t x_to_check = this->world->wrap_x(x + this->offsets.x_offsets[facing].front[i]);
      uint32_t y_to_check = this->world->wrap_y(y + this->offsets.y_offsets[facing].front[i]);
      if (this->world->positions[(AgentType)type][y_to_check][x_to_check]) {
        input[type] = true;
      }
    }
  }
  // check left
  for (uint8_t type = 0; type < 3; type++) {
    for (uint8_t i = 0; i < this->offsets.x_offsets[facing].left.size(); i++) {
      uint32_t x_to_check = this->world->wrap_x(x + this->offsets.x_offsets[facing].left[i]);
      uint32_t y_to_check = this->world->wrap_y(y + this->offsets.y_offsets[facing].left[i]);
      if (this->world->positions[(AgentType)type][y_to_check][x_to_check]) {
        input[3 + type] = true;
      }
    }
  }
  // check right
  for (uint8_t type = 0; type < 3; type++) {
    for (uint8_t i = 0; i < this->offsets.x_offsets[facing].right.size(); i++) {
      uint32_t x_to_check = this->world->wrap_x(x + this->offsets.x_offsets[facing].right[i]);
      uint32_t y_to_check = this->world->wrap_y(y + this->offsets.y_offsets[facing].right[i]);
      if (this->world->positions[(AgentType)type][y_to_check][x_to_check]) {
        input[6 + type] = true;
      }
    }
  }
  // check proximity
  for (uint8_t type = 0; type < 3; type++) {
    for (uint8_t i = 0; i < this->offsets.x_offsets[facing].proximity.size(); i++) {
      uint32_t x_to_check = this->world->wrap_x(x + this->offsets.x_offsets[facing].proximity[i]);
      uint32_t y_to_check = this->world->wrap_y(y + this->offsets.y_offsets[facing].proximity[i]);
      if (this->world->positions[(AgentType)type][y_to_check][x_to_check]) {
        input[9 + type] = true;
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
