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

uint32_t Herbivor::get_metabolic_rate() {
  return this->metabolic_rate;
}

AgentType Herbivor::get_type() {
  return this->type;
}
