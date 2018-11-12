#include "AlifeSim.h"

int main() {
  AlifeSim simulation;

  simulation.init("./simulation.cfg");
  simulation.start();

  std::cout << "Max age in simulation: " << simulation.max_age << std::endl;
  std::cout << "Max population in simulation: " << simulation.max_population << std::endl;
  return 0;
}
