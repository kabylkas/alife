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

void Plant::set_nutrition_level(uint16_t nutrition_level) {
  this->nutrition_level = nutrition_level;
}

