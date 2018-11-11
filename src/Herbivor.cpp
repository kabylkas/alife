#include "Herbivor.h"

Herbivor::Herbivor(uint32_t metabolic_rate) {
  this->metabolic_rate = metabolic_rate;
  this->type = HERBIVOR;
}

Herbivor::Herbivor() {

}

Herbivor::~Herbivor() {

}

void Herbivor::eat() {
#ifdef TRACE
  std::cout << "EAT: Herbivor with id: "<< this->id <<" is eating" << std::endl;
#endif
}

// sets
void Herbivor::set_nutritional_value(uint32_t nutrtional_value) {
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
