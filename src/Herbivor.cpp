#include "Herbivor.h"

Herbivor::Herbivor(uint32_t metabolic_rate) {
  this->metabolic_rate = metabolic_rate;
  this->type = HERBIVOR;
  this->food_type = PLANT;
}

Herbivor::Herbivor() {

}

Herbivor::~Herbivor() {

}

void Herbivor::eat(LivingOrganisms* liv_orgs) {
#ifdef TRACE
  std::cout << "EAT: Herbivor with id: "<< this->id <<" decided to eat" << std::endl;
#endif

  // observe proximity
  uint32_t x, y;
  if (this->eyes.in_proximity(PLANT, this->x, this->y, this->facing, &x, &y)) {
    for (uint32_t i = 0; i < liv_orgs->animals.size(); i++) {
      Plant* prey = &(liv_orgs->plants[i]);
      if (prey->get_x() == x && prey->get_y() == y) {
        if (prey->get_type() == this->food_type && prey->is_alive()) {
          #ifdef TRACE
            std::cout << "EAT: Herbivor with id: "<< this->id <<" is eating. Energy level: " << this->energy_level << std::endl;
          #endif
          // kill prey
          prey->die(); 
          // increment energy
          this->energy_level += prey->get_nutritional_value();
          break;
        }
      }
    }
  }
}

void Herbivor::reproduce(LivingOrganisms* liv_orgs) {
  this->energy_level /= 2;
  Animal* new_animal = new Herbivor();
  *new_animal = *(this);
  new_animal->new_born_reset(liv_orgs->id_generator->get_id());
  new_animal->get_brain()->mutate(0.2);
  liv_orgs->animals.push_back(new_animal);
  liv_orgs->num_herbivors++;
  #ifdef TRACE
    std::cout << "REPRODUCE: Herbivor with id: "<< this->id <<" is reproducing. Child id: " << new_animal->get_id() << std::endl;
  #endif
}

// sets
void Herbivor::set_nutritional_value(uint32_t nutritional_value) {
  this->nutritional_value = nutritional_value;
}

// gets
uint32_t Herbivor::get_metabolic_rate() {
  return this->metabolic_rate;
}

AgentType Herbivor::get_type() {
  return this->type;
}

uint32_t Herbivor::get_nutritional_value() {
  return this->nutritional_value;
}
