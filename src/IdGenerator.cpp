#include "IdGenerator.h"

IdGenerator::IdGenerator() {

}

IdGenerator::~IdGenerator() {

}

uint64_t IdGenerator::get_id() {
  uint64_t result = this->id;
  this->id++;
  return result;
}
