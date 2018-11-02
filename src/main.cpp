#include "AlifeSim.h"

int main() {
  AlifeSim simulation;

  simulation.init("./src/simulation.cfg");
  simulation.start();

  return 0;
}
