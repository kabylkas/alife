#include "Herbivor.h"

Herbivor::Herbivor(uint32_t metabolic_rate) {
  this->metabolic_rate = metabolic_rate;
}

Herbivor::Herbivor() {

}

Herbivor::~Herbivor() {

}

void Herbivor::eat() {
  std::cout << "Herbivor is eating" << std::endl;
}

uint32_t Herbivor::get_metabolic_rate() {
  return this->metabolic_rate;
}
