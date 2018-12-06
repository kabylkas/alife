#include "Carnivor.h"

Carnivor::Carnivor(uint32_t metabolic_rate) {
  this->metabolic_rate = metabolic_rate;
  this->nutritional_value = 0;
  this->type = CARNIVOR;
  this->food_type = HERBIVOR;
}

Carnivor::Carnivor() {
  this->metabolic_rate = 0;
  this->nutritional_value = 0;
  this->type = CARNIVOR;
  this->food_type = HERBIVOR;
}

Carnivor::~Carnivor() {

}

void Carnivor::eat(LivingOrganisms* liv_orgs) {
#ifdef TRACE
  std::cout << "EAT: Carnivor with id: "<< this->id <<" decided to eat." << std::endl;
#endif

  // observe proximity
  uint32_t x, y;
  if (this->eyes.in_proximity(HERBIVOR, this->x, this->y, this->facing, &x, &y)) {
    for (uint32_t i = 0; i < liv_orgs->get_num_animals(); i++) {
      Animal* prey = liv_orgs->get_animal(i);
      if (prey->get_x() == x && prey->get_y() == y) {
        if (prey->get_type() == this->food_type && prey->is_alive()) {
          #ifdef TRACE
            std::cout << "EAT: Carnivor with id: " << this->id <<" is eating.";
            std::cout << "Energy level: " << this->energy_level;
            std::cout << ". Prey id: " << prey->get_id() << std::endl;
          #endif
          // kill prey
          prey->die(true);
          // increment energy
          this->energy_level += prey->get_nutritional_value();
          break;
        }
      }
    }
  }
}

// sets
void Carnivor::set_nutritional_value(uint32_t nutritional_value) {
  this->nutritional_value = nutritional_value;
}

void Carnivor::set_metabolic_rate(uint32_t metabolic_rate) {
  this->metabolic_rate = metabolic_rate;
}
// gets
uint32_t Carnivor::get_metabolic_rate() {
  return this->metabolic_rate;
}

AgentType Carnivor::get_type() {
  return this->type;
}

uint32_t Carnivor::get_nutritional_value() {
  return this->nutritional_value;
}
