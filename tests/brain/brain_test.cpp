#include "Brain.h"

#include <iostream>
#include <cstdlib> //rand()
#include <ctime>

int main() {
  srand(time(0));
  std::cout << "Seed: " << time(0) << std::endl;
  int test_num = 0;
  ///////////////
  // Test 1
  ///////////////
  {
    test_num++;
    Brain brain;
    bool input[12]                 = {true, true, true, true, true, true, true, true, true, true, true, true};
    double initial_eat[12]         = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_left[12]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_right[12]  = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_move[12]        = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_eat_bias        = 0;
    double initial_tl_bias         = 0;
    double initial_tr_bias         = 0;
    double initial_move_bias       = 0;
    brain.set_model(EAT, initial_eat, initial_eat_bias);
    brain.set_model(TURN_LEFT, initial_turn_left, initial_tl_bias);
    brain.set_model(TURN_RIGHT, initial_turn_right, initial_tr_bias);
    brain.set_model(MOVE, initial_move, initial_move_bias);
    brain.remember(input);
    brain.dump_model();
    ActionType expected_output = TURN_RIGHT;

    if (brain.decide() == expected_output) {
      std::cout << "Test " << test_num << " passed" << std::endl;
    } else {
      std::cout << "Test " << test_num << " failed" << std::endl;
      return 1;
    }
  }

  ///////////////
  // Test 2
  ///////////////
  {
    test_num++;
    Brain brain;
    bool input[12]                 = {true, true, true, true, true, true, true, true, true, true, true, true};
    double initial_eat[12]         = {0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_left[12]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_right[12]  = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_move[12]        = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_eat_bias        = 0;
    double initial_tl_bias         = 0;
    double initial_tr_bias         = 0;
    double initial_move_bias       = 0;
    brain.set_model(EAT, initial_eat, initial_eat_bias);
    brain.set_model(TURN_LEFT, initial_turn_left, initial_tl_bias);
    brain.set_model(TURN_RIGHT, initial_turn_right, initial_tr_bias);
    brain.set_model(MOVE, initial_move, initial_move_bias);
    brain.remember(input);
    brain.dump_model();
    ActionType expected_output = EAT;

    if (brain.decide() == expected_output) {
      std::cout << "Test " << test_num << " passed" << std::endl;
    } else {
      std::cout << "Test " << test_num << " failed" << std::endl;
      return 1;
    }
  }

  ///////////////
  // Test 3
  ///////////////
  {
    test_num++;
    Brain brain;
    bool input[12]                 = {true, true, true, true, true, true, true, true, true, true, true, true};
    double initial_eat[12]         = {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_left[12]   = {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0};
    double initial_turn_right[12]  = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_move[12]        = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_eat_bias        = 0;
    double initial_tl_bias         = 0;
    double initial_tr_bias         = 0;
    double initial_move_bias       = 0;
    brain.set_model(EAT, initial_eat, initial_eat_bias);
    brain.set_model(TURN_LEFT, initial_turn_left, initial_tl_bias);
    brain.set_model(TURN_RIGHT, initial_turn_right, initial_tr_bias);
    brain.set_model(MOVE, initial_move, initial_move_bias);
    brain.remember(input);
    brain.dump_model();
    ActionType expected_output = TURN_LEFT;

    if (brain.decide() == expected_output) {
      std::cout << "Test " << test_num << " passed" << std::endl;
    } else {
      std::cout << "Test " << test_num << " failed" << std::endl;
      return 1;
    }
  }

  ///////////////
  // Test 4
  ///////////////
  {
    test_num++;
    Brain brain;
    bool input[12]                 = {true, true, true, true, true, true, true, true, true, true, true, true};
    double initial_eat[12]         = {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_left[12]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_right[12]  = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_move[12]        = {0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0};
    double initial_eat_bias        = 0;
    double initial_tl_bias         = 0;
    double initial_tr_bias         = 0;
    double initial_move_bias       = 0;
    brain.set_model(EAT, initial_eat, initial_eat_bias);
    brain.set_model(TURN_LEFT, initial_turn_left, initial_tl_bias);
    brain.set_model(TURN_RIGHT, initial_turn_right, initial_tr_bias);
    brain.set_model(MOVE, initial_move, initial_move_bias);
    brain.remember(input);
    brain.dump_model();
    ActionType expected_output = MOVE;

    if (brain.decide() == expected_output) {
      std::cout << "Test " << test_num << " passed" << std::endl;
    } else {
      std::cout << "Test " << test_num << " failed" << std::endl;
      return 1;
    }
  }

  ///////////////
  // Test 5
  ///////////////
  {
    test_num++;
    Brain brain;
    bool input[12]                 = {true, true, true, true, true, true, true, true, true, true, true, true};
    double initial_eat[12]         = {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_left[12]   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_turn_right[12]  = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double initial_move[12]        = {0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0};
    double initial_eat_bias        = 100;
    double initial_tl_bias         = 0;
    double initial_tr_bias         = 0;
    double initial_move_bias       = 0;
    brain.set_model(EAT, initial_eat, initial_eat_bias);
    brain.set_model(TURN_LEFT, initial_turn_left, initial_tl_bias);
    brain.set_model(TURN_RIGHT, initial_turn_right, initial_tr_bias);
    brain.set_model(MOVE, initial_move, initial_move_bias);
    brain.remember(input);
    brain.dump_model();
    ActionType expected_output = EAT;

    if (brain.decide() == expected_output) {
      std::cout << "Test " << test_num << " passed" << std::endl;
    } else {
      std::cout << "Test " << test_num << " failed" << std::endl;
      return 1;
    }
  }

  ///////////////
  // Test 6
  ///////////////
  {
    test_num++;
    Brain brain;
    double percent = 0.2;
    uint32_t expected_count = (uint32_t)(percent * 100);
    uint32_t tolerance = 20;
    for (uint32_t k = 0; k < 100; k++) {
      uint32_t count = 0;
      for (uint32_t i = 0; i < 100; i++) {
        if (brain.change(percent)) {
          count++;
        }
      }
      if (count > expected_count + tolerance || count < expected_count - tolerance) {
        std::cout << "Test " << test_num << " failed. Count: " << count << std::endl;
        return 1;
      }
    }
    std::cout << "Test " << test_num << " passed" << std::endl;
  }

  ///////////////
  // Test 7
  ///////////////
  {
    test_num++;
    Brain brain;
    double percent = 0.5;
    uint32_t expected_count = (uint32_t)(percent * 100);
    uint32_t tolerance = 20;
    for (uint32_t k = 0; k < 100; k++) {
      uint32_t count = 0;
      for (uint32_t i = 0; i < 100; i++) {
        if (brain.change(percent)) {
          count++;
        }
      }
      if (count > expected_count + tolerance || count < expected_count - tolerance) {
        std::cout << "Test " << test_num << " failed. Count: " << count << std::endl;
        return 1;
      }
    }
    std::cout << "Test " << test_num << " passed" << std::endl;
  }
  return 0;
}
