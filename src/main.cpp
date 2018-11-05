#include "AlifeSim.h"

int main() {
  AlifeSim simulation;

  simulation.init("./simulation.cfg");
  simulation.start();

  return 0;
}
