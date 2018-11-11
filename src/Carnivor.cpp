#include "Carnivor.h"

Carnivor::Carnivor(uint32_t metabolic_rate) {
  this->metabolic_rate = metabolic_rate;
  this->type = CARNIVOR;
  this->food_type = HERBIVOR;
}

Carnivor::Carnivor() {

}

Carnivor::~Carnivor() {

}

void Carnivor::eat(LivingOrganisms* liv_orgs) {
#ifdef TRACE
  std::cout << "EAT: Carnivor with id: "<< this->id <<" is eating" << std::endl;
#endif

  // observe proximity
  uint32_t x, y;
  if (this->eyes.in_proximity(HERBIVOR, this->facing, &x, &y)) {
    for (uint32_t i = 0; i < liv_orgs->animals.size(); i++) {
      Animal* prey = liv_orgs->animals[i];
      if (prey->get_x() == x && prey->get_y() == y) {
        if (prey->get_type() == food_type) {
          prey->die(); 
          this->energy_level += prey->get_nutritional_value();
          break;
        }
      }
    }
  }
}

uint32_t Carnivor::get_metabolic_rate() {
  return this->metabolic_rate;
}

AgentType Carnivor::get_type() {
  return this->type;
}
