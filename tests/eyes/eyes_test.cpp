#include "Eyes.h"
#include "Brain.h"
#include "World.h"

#include <iostream>

int main() {
  World world;
  Eyes eyes;
  Brain brain;
  
  world.init(10, 10);
  eyes.set_world(&world);
  eyes.set_brain(&brain);
  /* Test 1
  Facing: north
  0 1 2 3 4 5 6 7 8 9
  . . . . . . . . . . 0
  . . . . . . . . . . 1
  . . . . . . . . . . 2
  . . . C . . . . . . 3
  . . . . . P H . . . 4
  . . H . ^ . . . . . 5
  . . . . . . . . . . 6
  . . . . . . . . . . 7
  . . . . . . . . . . 8
  . . . . . . . . . . 9

  Expected output:
  0 1 0 | 1 0 0 | 1 0 0 | 0 0 1 */

  world.clear_positions();
  world.place_agent_to(CARNIVOR, 3, 3);
  world.place_agent_to(HERBIVOR, 6, 4);
  world.place_agent_to(HERBIVOR, 2, 5);
  world.place_agent_to(PLANT   , 5, 4);

  eyes.observe(NORTH, 4, 5);

  return 0;
}
