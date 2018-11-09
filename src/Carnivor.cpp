#include "Carnivor.h"

Carnivor::Carnivor(uint32_t metabolic_rate) {
  this->metabolic_rate = metabolic_rate;
}

Carnivor::Carnivor() {

}

Carnivor::~Carnivor() {

}

void Carnivor::eat() {
  std::cout << "Carnivor is eating" << std::endl;
}

uint32_t Carnivor::get_metabolic_rate() {
  return this->metabolic_rate;
}
