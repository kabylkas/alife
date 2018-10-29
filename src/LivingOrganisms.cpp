#include "LivingOrganisms.h"

LivingOrganisms::LivingOrganisms() {

}

LivingOrganisms::~LivingOrganisms() {
  #ifdef DEBUG
    std::cout << "About to delete " << animals.size() << " animals" << std::endl; 
  #endif
  for (uint32_t i = 0; i < animals.size(); i++) {
    delete animals[i];
  }
}
