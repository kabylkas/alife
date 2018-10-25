#pragma once

#define MEMORY_SIZE 12

enum Direction {
  EAST,
  WEST,
  SOUTH,
  NORTH
};

/////////////////
// f1 f2 f3 f4 f5
// l2 p2 p3 p4 r2
// l1 p1 XX p5 r1
//                 f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
int north_x_offsets[14] = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
int north_y_offsets[14] = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,  1,  0};

//                f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
int east_x_offsets[14] = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,   1,  0};
int east_y_offsets[14] = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};

//                 f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
int south_x_offsets[14] = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};
int south_y_offsets[14] = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1,  0, -1, -1, -1,  0};

//                f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
int west_x_offsets[14] = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1, 0,  -1, -1, -1, 0};
int west_y_offsets[14] = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
