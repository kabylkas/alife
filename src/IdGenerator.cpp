#include "IdGenerator.h"

IdGenerator::IdGenerator() {
  this->id = 0;
}

IdGenerator::~IdGenerator() {

}

uint64_t IdGenerator::get_id() {
  uint64_t result = this->id;
  this->id++;
  return result;
}
