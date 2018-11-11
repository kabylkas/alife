#include "AlifeSim.h"

int main() {
  AlifeSim simulation;

  simulation.init("./simulation.cfg");
  simulation.start();

  std::cout << "Max age in simulation: " << simulation.max_age << std::endl;
  return 0;
}
