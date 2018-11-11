#include "Plant.h"

Plant::Plant() {
  this->x = 0;
  this->y = 0;
  this->nutritional_value = 0;
  this->dead = false;
}

Plant::~Plant() {

}

bool Plant::is_alive() {
  return !(this->dead);
}

bool Plant::is_dead() {
  return dead;
}

void Plant::die() {
  this->dead = true;
}

// sets
void Plant::set_x(uint32_t x) {
  this->x = x;
}

void Plant::set_y(uint32_t y) {
  this->y = y;
}

void Plant::set_nutritional_value(uint32_t nutrition_value) {
  this->nutritional_value = nutrition_value;
}

// gets
uint32_t Plant::get_nutritional_value() {
  return this->nutritional_value;
}

uint32_t Plant::get_x() {
  return this->x;
}

uint32_t Plant::get_y() {
  return this->y;
}

AgentType Plant::get_type() {
  return PLANT;
}
