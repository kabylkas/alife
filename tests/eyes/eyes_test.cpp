#include "Animal.h"
#include "Carnivor.h"
#include "World.h"

#include <iostream>

int main() {
  World world;
  Animal* new_animal = new Carnivor();

  return 0;
}
