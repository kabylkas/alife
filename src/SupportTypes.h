#pragma once
#include <map>
#include <vector>

#define MEMORY_SIZE 12
#define DEBUG

typedef signed char             int8_t;
typedef unsigned char           uint8_t;
typedef signed short int        int16_t;
typedef unsigned short int      uint16_t;
typedef unsigned int            uint32_t;
typedef unsigned long int       uint64_t;
enum Direction {
  EAST,
  WEST,
  SOUTH,
  NORTH
};

enum AgentType {
  HERBIVOR,
  CARNIVOR,
  PLANT
};

class Offsets {
  /////////////////
  // f1 f2 f3 f4 f5
  // l2 p2 p3 p4 r2
  // l1 p1 XX p5 r1
  //                 f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
  class Location {
    public:
      std::vector<int> front;
      std::vector<int> left;
      std::vector<int> right;
      std::vector<int> proximity;
      Location() {};
      ~Location() {};
  };

  public:
    std::map<Direction, Location> x_offsets;
    std::map<Direction, Location> y_offsets;

    Offsets() {
      this->x_offsets[NORTH];
      this->y_offsets[NORTH];
      this->x_offsets[EAST];
      this->y_offsets[EAST];
      this->x_offsets[SOUTH];
      this->y_offsets[SOUTH];
      this->x_offsets[WEST];
      this->y_offsets[WEST];

      int north_x_offsets[14] = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
      int north_y_offsets[14] = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,  1,  0};
      int east_x_offsets[14] = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,   1,  0};
      int east_y_offsets[14] = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};
      int south_x_offsets[14] = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};
      int south_y_offsets[14] = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1,  0, -1, -1, -1,  0};
      int west_x_offsets[14] = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1, 0,  -1, -1, -1, 0};
      int west_y_offsets[14] = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};

      for (uint8_t i = 0; i < 5; i++) {
        this->x_offsets[NORTH].front.push_back(north_x_offsets[i]);
        this->y_offsets[NORTH].front.push_back(north_y_offsets[i]);
        this->x_offsets[EAST].front.push_back(east_x_offsets[i]);
        this->y_offsets[EAST].front.push_back(east_y_offsets[i]);
        this->x_offsets[SOUTH].front.push_back(south_x_offsets[i]);
        this->y_offsets[SOUTH].front.push_back(south_y_offsets[i]);
        this->x_offsets[WEST].front.push_back(west_x_offsets[i]);
        this->y_offsets[WEST].front.push_back(west_y_offsets[i]);
      }

      for (uint8_t i = 5; i < 7; i++) {
        this->x_offsets[NORTH].left.push_back(north_x_offsets[i]);
        this->y_offsets[NORTH].left.push_back(north_y_offsets[i]);
        this->x_offsets[EAST].left.push_back(east_x_offsets[i]);
        this->y_offsets[EAST].left.push_back(east_y_offsets[i]);
        this->x_offsets[SOUTH].left.push_back(south_x_offsets[i]);
        this->y_offsets[SOUTH].left.push_back(south_y_offsets[i]);
        this->x_offsets[WEST].left.push_back(west_x_offsets[i]);
        this->y_offsets[WEST].left.push_back(west_y_offsets[i]);
      }
      
      for (uint8_t i = 7; i < 9; i++) {
        this->x_offsets[NORTH].right.push_back(north_x_offsets[i]);
        this->y_offsets[NORTH].right.push_back(north_y_offsets[i]);
        this->x_offsets[EAST].right.push_back(east_x_offsets[i]);
        this->y_offsets[EAST].right.push_back(east_y_offsets[i]);
        this->x_offsets[SOUTH].right.push_back(south_x_offsets[i]);
        this->y_offsets[SOUTH].right.push_back(south_y_offsets[i]);
        this->x_offsets[WEST].right.push_back(west_x_offsets[i]);
        this->y_offsets[WEST].right.push_back(west_y_offsets[i]);
      }

      for (uint8_t i = 9; i < 14; i++) {
        this->x_offsets[NORTH].proximity.push_back(north_x_offsets[i]);
        this->y_offsets[NORTH].proximity.push_back(north_y_offsets[i]);
        this->x_offsets[EAST].proximity.push_back(east_x_offsets[i]);
        this->y_offsets[EAST].proximity.push_back(east_y_offsets[i]);
        this->x_offsets[SOUTH].proximity.push_back(south_x_offsets[i]);
        this->y_offsets[SOUTH].proximity.push_back(south_y_offsets[i]);
        this->x_offsets[WEST].proximity.push_back(west_x_offsets[i]);
        this->y_offsets[WEST].proximity.push_back(west_y_offsets[i]);
      }
    }

    ~Offsets() {};
};

struct Configs {
  uint64_t time;
  uint32_t num_carnivors;
  uint32_t num_herbivors;
  uint32_t num_plants;
  uint32_t world_height;
  uint32_t world_width;
};
