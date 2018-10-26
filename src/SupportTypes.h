#pragma once

#define MEMORY_SIZE 12

typedef signed char             int8_t;
typedef unsigned char           uint8_t;
typedef signed short int        int16_t;
typedef unsigned short int      uint16_t;
typedef unsigned int            uint32_t;
enum Direction {
  EAST,
  WEST,
  SOUTH,
  NORTH
};

struct Offsets {
  /////////////////
  // f1 f2 f3 f4 f5
  // l2 p2 p3 p4 r2
  // l1 p1 XX p5 r1
  //                 f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
  const int north_x_offsets[14] = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
  const int north_y_offsets[14] = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,  1,  0};

  //                f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
  const int east_x_offsets[14] = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,   1,  0};
  const int east_y_offsets[14] = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};

  //                 f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
  const int south_x_offsets[14] = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};
  const int south_y_offsets[14] = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1,  0, -1, -1, -1,  0};

  //                f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
  const int west_x_offsets[14] = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1, 0,  -1, -1, -1, 0};
  const int west_y_offsets[14] = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
};

struct Config {
  uint64_t time;
  uint32_t num_carnivors;
  uint32_t num_herbivors;
  uint32_t num_plants;
}
