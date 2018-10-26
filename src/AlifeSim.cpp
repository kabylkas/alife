#include "AlifeSim.h"

AlifeSim::AlifeSim() {

}

AlifeSim::~AlifeSim() {

}

bool AlifeSim::read_config_file(std::string cfg_file_name) {
  bool result = true;
  ifstream cfg_file(cfg_file_name);
  if (cfg_file.is_open()) {
    std::string line;
    while (std::get_line(cfg_file, line)) {
      bool simulation_time_found = false;
      bool num_carnivors_found   = false;
      bool num_herbivors_found   = false;
      bool num_plants_found      = false;

      simulation_time_found = (line.find("simulation-time") != std::string::npos);
      num_carnivors_found   = (line.find("num-carnivor") != std::string::npos);
      num_herbivors_found   = (line.find("num-herbivors") != std::string::npos);
      num_plants_found      = (line.find("num-plants") != std::string::npos);

      if (simulation_time_found) {

      } else if (num_carnivors_found) {

      } else if (num_herbivors_found) {

      } else if (num_plants_found) {

      } else {
        std::cout << "Unknown configuration variable: " << line << std::endl;
        result = false;
        break;
      }
    }
  } else {
    std::cout << "Unable to open config file" << std::endl;
    result = false;
  }

  return result;
}

void AlifeSim::init(std::string cfg_file) {
  for (uint32_t i = 0; i < 100; i++) {
    Animal* animal = new Animal();
    liv_orgs.animals.push_back(animal);
    Plant plant(0, 0);
    liv_orgs.plants.push_back(plant);
  }
}

void AlifeSim::start() {

}
