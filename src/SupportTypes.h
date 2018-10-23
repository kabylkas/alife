#pragma once

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
int north_x_offset[14];
int north_y_offset[14];
//                 f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
north_x_offsets = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
north_y_offsets = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,  1,  0};

int east_x_offset[14];
int east_y_offset[14];
//                f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
east_x_offsets = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,   1,  0};
east_y_offsets = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};

int south_x_offset[14];
int south_y_offset[14];
//                 f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
south_x_offsets = {2,  1,  0,  -1, -2, 2,  2,  -2, -2, 1,  1,  0,  -1, -1};
south_y_offsets = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1,  0, -1, -1, -1,  0};

int west_x_offset[14];
int west_y_offset[14]
//                f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
west_x_offsets = {-2, -2, -2, -2, -2, 0,  -1, 0,  -1, 0,  -1, -1, -1, 0};
west_y_offsets = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
