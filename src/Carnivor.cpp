#include "Carnivor.h"

Carnivor::Carnivor(uint32_t metabolic_rate) {
  this->metabolic_rate = metabolic_rate;
  this->type = CARNIVOR;
}

Carnivor::Carnivor() {

}

Carnivor::~Carnivor() {

}

void Carnivor::eat() {
#ifdef TRACE
  std::cout << "EAT: Carnivor with id: "<< this->id <<" is eating" << std::endl;
#endif
}

uint32_t Carnivor::get_metabolic_rate() {
  return this->metabolic_rate;
}

AgentType Carnivor::get_type() {
  return this->type;
}
