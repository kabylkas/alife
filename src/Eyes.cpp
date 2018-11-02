#include "Eyes.h"

Eyes::Eyes() {

}

Eyes::~Eyes() {

}

void Eyes::observe(Direction facing) {
  // initialize inputs
  bool input[MEMORY_SIZE];
  for (uint8_t i = 0; i < MEMORY_SIZE; i++) {
    input[i] = false;
  }

  // observe
  
  brain->remember(input);
}

//sets
void Eyes::set_brain(Brain* brain) {
  this->brain = brain;
}

void Eyes::set_world(World* world) {
  this->world = world;
}
