#pragma once

enum Direction {
  EAST,
  WEST,
  SOUTH,
  NORTH
};

class VisionOffsets {
  private:
    uint8_t x_offsets[14];
    uint8_t y_offsets[14];

  public:
    VisionCoordinates(Direction facing) {
      switch (facing) {
        NORTH:
          /////////////////
          // f1 f2 f3 f4 f5
          // l2 p2 p3 p4 r2
          // l1 p1 XX p5 r1

          //           f1  f2  f3  f4  f5  l1  l2  r1  r2  p1  p2  p3  p4  p5
          x_offsets = {-2, -1, 0,  1,  2,  -2, -2, 2,  2,  -1, -1, 0,  1,  1};
          y_offsets = {2,  2,  2,  2,  2,  0,  1,  0,  1,  0,  1,  1,  1,  0};
      }
    }
};
