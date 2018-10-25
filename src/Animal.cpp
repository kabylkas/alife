#include "Animal.h"

Animal::Animal() {

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
