#include "Plant.h"

Plant::Plant() {
  this->x = x;
  this->y = y;
}

Plant::~Plant() {

}

void Plant::set_x(uint32_t x) {
  this->x = x;
}

void Plant::set_y(uint32_t y) {
  this->y = y;
}

// sets
void Plant::set_nutritional_value(uint32_t nutrition_value) {
  this->nutritional_value = nutrition_value;
}

// gets
uint32_t Plant::get_nutritional_value() {
  return this->nutritional_value;
}
