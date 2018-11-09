#include "Animal.h"

Animal::Animal() {
  this->x = 0;
  this->y = 0;
  this->facing = EAST;
  this->energy_level = 100;

  this->eyes.set_brain(&brain);
}

Animal::~Animal() {

}

void Animal::move() {

}

void Animal::turn_left() {
  // get the facing direction
  int current_direction = (uint8_t)this->facing;

  // suptract 1 to turn left
  current_direction--;
  if (current_direction < 0) {
    current_direction = NUM_DIRECTION - 1;
  }

  // update facing direction
  this->facing = (Direction)current_direction;
}

void Animal::turn_right() {
  // get the facing direction
  uint8_t current_direction = (uint8_t)this->facing;

  // add 1 to turn right, Direction enum is ordered circularly
  current_direction = (current_direction + 1) % NUM_DIRECTION;

  // update facing direction
  this->facing = (Direction)current_direction;
}

void Animal::take_action(LivingOrganisms* liv_orgs) {
  // observe, remember the inputs
  this->eyes.observe(this->facing, this->x, this->y);
  
  // decide based on observation
  ActionType decision = this->brain.decide();

  switch (decision) {
    case EAT:
      this->eat();
      break;

    case TURN_LEFT:
      this->turn_left();
      break;

    case TURN_RIGHT:
      this->turn_right();
      break;

    case MOVE:
      this->move();
      break;

    default:
      std::cout << "Non-existing decision made! Should not be here!" << std::endl;
      break;
  }
}

//sets
void Animal::set_world(World* world) {
  this->eyes.set_world(world);
}

void Animal::set_x(uint32_t x) {
  this->x = x;
}

void Animal::set_y(uint32_t y) {
  this->y = y;
}

void Animal::set_direction(Direction facing) {
  this->facing = facing;
}

void Animal::set_energy(uint16_t energy_level) {
  this->energy_level = energy_level;
}

//gets
Brain* Animal::get_brain() {
  return &(this->brain);
}

