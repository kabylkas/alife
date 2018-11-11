#include "Eyes.h"
#include "Brain.h"
#include "World.h"

#include <iostream>

int main() {
  World world;
  Eyes eyes;
  Brain brain;
  
  world.init(10, 10, true);
  eyes.set_world(&world);
  eyes.set_brain(&brain);
  int test_num = 0;
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
  test_num++;
  bool expected_output[12] = {0,1,0, 1,0,0, 1,0,0, 0,0,1};
  world.clear_positions();
  world.place_agent_to(CARNIVOR, 3, 3);
  world.place_agent_to(HERBIVOR, 6, 4);
  world.place_agent_to(HERBIVOR, 2, 5);
  world.place_agent_to(PLANT   , 5, 4);
  eyes.observe(NORTH, 4, 5);
  if (!brain.compare(expected_output)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }
  /************************************************************/
  /* Test 2
  Facing: east
  0 1 2 3 4 5 6 7 8 9
  . . . . . . . . . . 0
  . . . . . . . . . . 1
  . . . . . . . . . . 2
  . . . C . . . . . . 3
  . . . . . P H . . . 4
  . . H . > . . . . . 5
  . . . . . . . . . . 6
  . . . . . . . . . . 7
  . . . . . . . . . . 8
  . . . . . . . . . . 9

  Expected output:
  1 0 0 | 0 0 0 | 0 0 0 | 0 0 1 */
  test_num++;
  bool expected_output2[12] = {1,0,0, 0,0,0, 0,0,0, 0,0,1};
  world.clear_positions();
  world.place_agent_to(CARNIVOR, 3, 3);
  world.place_agent_to(HERBIVOR, 6, 4);
  world.place_agent_to(HERBIVOR, 2, 5);
  world.place_agent_to(PLANT   , 5, 4);
  eyes.observe(EAST, 4, 5);
  if (!brain.compare(expected_output2)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }
  /************************************************************/
  /* Test 3
  Facing: south
  0 1 2 3 4 5 6 7 8 9
  . . . . . . . . H C 0
  P . . . . . . . . . 1
  . . . . . . . . . . 2
  . . . . . . . . . . 3
  . . . . . . . . . . 4
  . . . . . . . . . . 5
  . . . . . . . . . . 6
  . . . . . . . . . . 7
  . . . . . . . . . . 8
  P H . . . . . C . v 9

  Expected output:
  0 0 1 | 1 0 0 | 0 1 0 | 1 1 1 */
  test_num++;
  bool expected_output3[12] = {0,0,1, 1,0,0, 0,1,0, 1,1,1};
  world.clear_positions();
  world.place_agent_to(CARNIVOR, 9, 0);
  world.place_agent_to(CARNIVOR, 7, 9);
  world.place_agent_to(HERBIVOR, 8, 0);
  world.place_agent_to(HERBIVOR, 1, 9);
  world.place_agent_to(PLANT   , 0, 1);
  world.place_agent_to(PLANT   , 0, 9);
  eyes.observe(SOUTH, 9, 9);
  if (!brain.compare(expected_output3)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }
  /************************************************************/
  /* Test 4
  Facing: west
  0 1 2 3 4 5 6 7 8 9
  . . . . . . . . C . 0
  . . . . . . . H C H 1
  . . . . . . . . . . 2
  . . . . . . . . . . 3
  . . . . . . . . . . 4
  . . . . . . . . . . 5
  . . . . . . . . . . 6
  . . . . . . . P C P 7
  . . . . . . . . H P 8
  . . . . . . . C . < 9

  Expected output:
  1 1 1 | 1 1 0 | 0 1 1 | 1 1 1 */
  test_num++;
  bool expected_output4[12] = {1,1,1, 1,1,0, 0,1,1, 1,1,1};
  world.clear_positions();
  world.place_agent_to(CARNIVOR, 8, 0);
  world.place_agent_to(CARNIVOR, 8, 1);
  world.place_agent_to(CARNIVOR, 8, 7);
  world.place_agent_to(CARNIVOR, 7, 9);
  world.place_agent_to(HERBIVOR, 7, 1);
  world.place_agent_to(HERBIVOR, 9, 1);
  world.place_agent_to(HERBIVOR, 8, 8);
  world.place_agent_to(PLANT   , 7, 7);
  world.place_agent_to(PLANT   , 9, 7);
  world.place_agent_to(PLANT   , 9, 8);
  eyes.observe(WEST, 9, 9);
  if (!brain.compare(expected_output4)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  return 0;
}
