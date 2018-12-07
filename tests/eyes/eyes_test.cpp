#include "Eyes.h"
#include "Brain.h"
#include "World.h"

#include <iostream>

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
bool Test_1(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  bool expected_output[12] = {0,1,0, 1,0,0, 1,0,0, 0,0,1};
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 3, 3);
  world->place_agent_to(HERBIVOR, 6, 4);
  world->place_agent_to(HERBIVOR, 2, 5);
  world->place_agent_to(PLANT   , 5, 4);
  eyes->observe(NORTH, 4, 5);

  return brain->compare(expected_output);
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
bool Test_2(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  bool expected_output[12] = {1,0,0, 0,0,0, 0,0,0, 0,0,1};
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 3, 3);
  world->place_agent_to(HERBIVOR, 6, 4);
  world->place_agent_to(HERBIVOR, 2, 5);
  world->place_agent_to(PLANT   , 5, 4);
  eyes->observe(EAST, 4, 5);

  return brain->compare(expected_output);
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
bool Test_3(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  bool expected_output[12] = {0,0,1, 1,0,0, 0,1,0, 1,1,1};
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 9, 0);
  world->place_agent_to(CARNIVOR, 7, 9);
  world->place_agent_to(HERBIVOR, 8, 0);
  world->place_agent_to(HERBIVOR, 1, 9);
  world->place_agent_to(PLANT   , 0, 1);
  world->place_agent_to(PLANT   , 0, 9);
  eyes->observe(SOUTH, 9, 9);

  return brain->compare(expected_output);
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
bool Test_4(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  bool expected_output[12] = {1,1,1, 1,1,0, 0,1,1, 1,1,1};
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 8, 0);
  world->place_agent_to(CARNIVOR, 8, 1);
  world->place_agent_to(CARNIVOR, 8, 7);
  world->place_agent_to(CARNIVOR, 7, 9);
  world->place_agent_to(HERBIVOR, 7, 1);
  world->place_agent_to(HERBIVOR, 9, 1);
  world->place_agent_to(HERBIVOR, 8, 8);
  world->place_agent_to(PLANT   , 7, 7);
  world->place_agent_to(PLANT   , 9, 7);
  world->place_agent_to(PLANT   , 9, 8);
  eyes->observe(WEST, 9, 9);

  return brain->compare(expected_output);
}

/************************************************************/
/* Test 5
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
x = 5; y = 4 */
bool Test_5(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  uint32_t my_x = 4;
  uint32_t my_y = 5;
  uint32_t expected_x = 5;
  uint32_t expected_y = 4;
  uint32_t output_x, output_y;
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 3, 3);
  world->place_agent_to(HERBIVOR, 6, 4);
  world->place_agent_to(HERBIVOR, 2, 5);
  world->place_agent_to(PLANT   , 5, 4);

  bool cond1 = eyes->in_proximity(PLANT, my_x, my_y, NORTH, &output_x, &output_y);
  bool cond2 = (output_x == expected_x) && (output_y == expected_y);

  return cond1 & cond2;
}

/************************************************************/
/* Test 6
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
x = 5; y = 4 */
bool Test_6(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  uint32_t my_x = 9;
  uint32_t my_y = 9;
  Direction facing = WEST;
  uint32_t expected_x = 9;
  uint32_t expected_y = 8;
  uint32_t output_x, output_y;
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 8, 0);
  world->place_agent_to(CARNIVOR, 8, 1);
  world->place_agent_to(CARNIVOR, 8, 7);
  world->place_agent_to(CARNIVOR, 7, 9);
  world->place_agent_to(HERBIVOR, 7, 1);
  world->place_agent_to(HERBIVOR, 9, 1);
  world->place_agent_to(HERBIVOR, 8, 8);
  world->place_agent_to(PLANT   , 7, 7);
  world->place_agent_to(PLANT   , 9, 7);
  world->place_agent_to(PLANT   , 9, 8);

  bool cond1 = eyes->in_proximity(PLANT, my_x, my_y, facing, &output_x, &output_y);
  bool cond2 = (output_x == expected_x) && (output_y == expected_y);

  return cond1 & cond2;
}


/************************************************************/
/* Test 7
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
x = 5; y = 4 */
bool Test_7(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  uint32_t my_x = 9;
  uint32_t my_y = 9;
  Direction facing = WEST;
  uint32_t expected_x = 8;
  uint32_t expected_y = 0;
  uint32_t output_x, output_y;
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 8, 0);
  world->place_agent_to(CARNIVOR, 8, 1);
  world->place_agent_to(CARNIVOR, 8, 7);
  world->place_agent_to(CARNIVOR, 7, 9);
  world->place_agent_to(HERBIVOR, 7, 1);
  world->place_agent_to(HERBIVOR, 9, 1);
  world->place_agent_to(HERBIVOR, 8, 8);
  world->place_agent_to(PLANT   , 7, 7);
  world->place_agent_to(PLANT   , 9, 7);
  world->place_agent_to(PLANT   , 9, 8);

  bool cond1 = eyes->in_proximity(CARNIVOR, my_x, my_y, facing, &output_x, &output_y);
  bool cond2 = (output_x == expected_x) && (output_y == expected_y);

  return cond1 & cond2;
}


/************************************************************/
/* Test 8
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
x = 5; y = 4 */
bool Test_8(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  uint32_t my_x = 9;
  uint32_t my_y = 9;
  Direction facing = WEST;
  uint32_t expected_x = 8;
  uint32_t expected_y = 8;
  uint32_t output_x, output_y;
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 8, 0);
  world->place_agent_to(CARNIVOR, 8, 1);
  world->place_agent_to(CARNIVOR, 8, 7);
  world->place_agent_to(CARNIVOR, 7, 9);
  world->place_agent_to(HERBIVOR, 7, 1);
  world->place_agent_to(HERBIVOR, 9, 1);
  world->place_agent_to(HERBIVOR, 8, 8);
  world->place_agent_to(PLANT   , 7, 7);
  world->place_agent_to(PLANT   , 9, 7);
  world->place_agent_to(PLANT   , 9, 8);

  bool cond1 = eyes->in_proximity(HERBIVOR, my_x, my_y, facing, &output_x, &output_y);
  bool cond2 = (output_x == expected_x) && (output_y == expected_y);

  return cond1 & cond2;
}

/************************************************************/
/* Test 9
Facing: west
0 1 2 3 4 5 6 7 8 9
. . . . . . . . C . 0
. . . . . . . H C H 1
. . . . . . . . . . 2
. . . . . . . . . . 3
. . . . . . . . . . 4
. . . . . . < . . . 5
. . . . . . . . . . 6
. . . . . . . P C P 7
. . . . . . . . H P 8
. . . . . . . C . . 9*/
bool Test_9(World* world, Eyes* eyes, Brain* brain, Offsets* offsets) {
  uint32_t my_x = 6;
  uint32_t my_y = 5;
  Direction facing = WEST;
  uint32_t output_x, output_y;
  world->clear_positions();
  world->place_agent_to(CARNIVOR, 8, 0);
  world->place_agent_to(CARNIVOR, 8, 1);
  world->place_agent_to(CARNIVOR, 8, 7);
  world->place_agent_to(CARNIVOR, 7, 9);
  world->place_agent_to(HERBIVOR, 7, 1);
  world->place_agent_to(HERBIVOR, 9, 1);
  world->place_agent_to(HERBIVOR, 8, 8);
  world->place_agent_to(PLANT   , 7, 7);
  world->place_agent_to(PLANT   , 9, 7);
  world->place_agent_to(PLANT   , 9, 8);

  bool cond1 = !(eyes->in_proximity(HERBIVOR, my_x, my_y, facing, &output_x, &output_y));

  return cond1;
}
int main() {
  World world;
  Eyes eyes;
  Brain brain;
  Offsets offsets;
  
  world.init(10, 10, true);
  eyes.set_world(&world);
  eyes.set_brain(&brain);
  eyes.set_offsets(&offsets);
  int test_num = 0;

  // TEST 1
  test_num++;
  if (!Test_1(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  // TEST 2
  test_num++;
  if (!Test_2(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  // TEST 3
  test_num++;
  if (!Test_3(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  // TEST 4
  test_num++;
  if (!Test_4(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  // TEST 5
  test_num++;
  if (!Test_5(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  // TEST 6
  test_num++;
  if (!Test_6(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  // TEST 7
  test_num++;
  if (!Test_7(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  // TEST 8
  test_num++;
  if (!Test_8(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  // TEST 9
  test_num++;
  if (!Test_9(&world, &eyes, &brain, &offsets)) {
    std::cout << "Test " << test_num << " failed!" << std::endl;
    return 1;
  } else { 
    std::cout << "Test " << test_num << " passed" << std::endl;
  }
  return 0;
}
