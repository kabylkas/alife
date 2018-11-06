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

}

void Animal::turn_right() {

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

