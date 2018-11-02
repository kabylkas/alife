#pragma once
#include <map>
#include <vector>
#include <bits/stdc++.h> 

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
  CARNIVOR,
  HERBIVOR,
  PLANT
};

class Offsets {
  /////////////////
  // f1 f2 f3 f4 f5
  // l2 p2 p3 p4 r2
  // l1 p1 XX p5 r1
  //                 f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
  public:
    std::map<Direction, std::vector<int>> x_offset;
    std::map<Direction, std::vector<int>> y_offset;

    Offsets() {
      this->x_offset[NORTH];
      this->y_offset[NORTH];
      this->x_offset[EAST];
      this->y_offset[EAST];
      this->x_offset[SOUTH];
      this->y_offset[SOUTH];
      this->x_offset[WEST];
      this->y_offset[WEST];

      int north_x_offsets[14] = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
      int north_y_offsets[14] = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,  1,  0};
      int east_x_offsets[14] = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,   1,  0};
      int east_y_offsets[14] = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};
      int south_x_offsets[14] = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};
      int south_y_offsets[14] = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1,  0, -1, -1, -1,  0};
      int west_x_offsets[14] = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1, 0,  -1, -1, -1, 0};
      int west_y_offsets[14] = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};

      for (uint8_t i = 0; i < 14; i++) {
        this->x_offset[NORTH].push_back(north_x_offsets[i]);
        this->y_offset[NORTH].push_back(north_y_offsets[i]);
        this->x_offset[EAST].push_back(east_x_offsets[i]);
        this->y_offset[EAST].push_back(east_y_offsets[i]);
        this->x_offset[SOUTH].push_back(south_x_offsets[i]);
        this->y_offset[SOUTH].push_back(south_y_offsets[i]);
        this->x_offset[WEST].push_back(west_x_offsets[i]);
        this->y_offset[WEST].push_back(west_y_offsets[i]);
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
