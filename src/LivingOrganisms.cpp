#include "LivingOrganisms.h"

LivingOrganisms::LivingOrganisms() {
  this->num_carnivors = 0;
  this->num_herbivors = 0;
  this->num_plants = 0;
}

LivingOrganisms::~LivingOrganisms() {
  #ifdef DEBUG
    std::cout << "About to delete " << animals.size() << " animals" << std::endl; 
  #endif
  for (uint32_t i = 0; i < animals.size(); i++) {
    delete animals[i];
  }
}

void LivingOrganisms::set_id_generator(IdGenerator* id_generator) {
  this->id_generator = id_generator;
}
