#include "World.h"

World::World() {

}

World::~World() {

}

uint32_t World::wrap_x(int x) {
  uint32_t result;

  if (x < 0) {
    result = this->width - 1;
  } else if (x >= this->width) {
    result = 0;
  } else {
    result = x;
  }

  return result;
}

uint32_t World::wrap_y(int y) {
  uint32_t result;

  if (y < 0) {
    result = this->height - 1;
  } else if (y >= this->height) {
    result = 0;
  } else {
    result = y;
  }

  return result;
}

// sets
void World::set_width(uint32_t width) {
  this->width = width;
}

void World::set_height(uint32_t height) {
  this->height = height;
}

void World::set_liv_orgs(LivingOrganisms* liv_orgs) {
  this->liv_orgs = liv_orgs;
}


// gets
uint32_t World::get_width() {
  return this->width;
}

uint32_t World::get_height() {
  return this->height;
}


LivingOrganisms* World::get_liv_orgs() {
  return this->liv_orgs;
}

