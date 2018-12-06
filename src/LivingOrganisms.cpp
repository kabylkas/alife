#include "LivingOrganisms.h"

LivingOrganisms::LivingOrganisms() {
  this->num_carnivors = 0;
  this->num_herbivors = 0;
  this->num_plants = 0;
}

LivingOrganisms::~LivingOrganisms() {
  #ifdef DEBUG
    std::cout << "About to delete " << animals.size() << " animals" << std::endl; 
  #endif
  for (uint32_t i = 0; i < animals.size(); i++) {
    delete animals[i];
  }
}

void LivingOrganisms::set_id_generator(IdGenerator* id_generator) {
  this->id_generator = id_generator;
}

void LivingOrganisms::add_animal(Animal* animal) {
  this->animals.push_back(animal);
  if (animal->get_type() == CARNIVOR) {
    this->num_carnivors++;
  } else {
    this->num_herbivors++;
  }
}

void LivingOrganisms::remove_animal(uint32_t i) {
  assert(i < this->animals.size());
  if (this->animals[i]->get_type() == CARNIVOR) {
    this->num_carnivors--;
  } else {
    this->num_herbivors--;
  }
  delete animals[i];
  this->animals.erase(this->animals.begin() + i);
}

void LivingOrganisms::add_plant(Plant plant) {
  this->plants.push_back(plant);
  this->num_plants++;
}

void LivingOrganisms::remove_plant(uint32_t i) {
  assert(i < this->plants.size());
  this->plants.erase(this->plants.begin() + i);
  this->num_plants--;
}

Animal* LivingOrganisms::get_animal(uint32_t i) {
  assert(i < this->animals.size());
  return this->animals[i];
}

Plant* LivingOrganisms::get_plant(uint32_t i) {
  assert(i < this->plants.size());
  return &(this->plants[i]);
}

uint32_t LivingOrganisms::get_num_carnivors() {
  return this->num_carnivors;
}

uint32_t LivingOrganisms::get_num_herbivors() {
  return this->num_herbivors;
}

uint32_t LivingOrganisms::get_num_animals() {
  return this->animals.size();
}

uint32_t LivingOrganisms::get_num_plants() {
  return this->plants.size();
}
