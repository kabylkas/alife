#include "Animal.h"

Animal::Animal() {
  this->x = 0;
  this->y = 0;
  this->facing = EAST;
  this->energy_level = 100;
}

Animal::~Animal() {

}

void Animal::move() {

}

void Animal::eat() {

}

void Animal::turn_left() {

}

void Animal::turn_right() {

}

void Animal::take_action() {

}

Brain* Animal::get_brain() {
  return &(this->brain);
}

void Animal::set_world(World* world) {
  this->my_world = world;
}
