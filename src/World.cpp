#include "World.h"

World::World() {

}

World::~World() {
  for (uint32_t i = 0; i < this->height; i++) {
    delete [] positions[CARNIVOR][i];
    delete [] positions[HERBIVOR][i];
    delete [] positions[PLANT][i];
  }

  delete [] positions[CARNIVOR];
  delete [] positions[HERBIVOR];
  delete [] positions[PLANT];
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

//others
void World::init(uint32_t height, uint32_t width) {
  this->height = height;
  this->width = width;

  // set up carnivor positions
  this->positions[CARNIVOR];
  this->positions[CARNIVOR] = new bool*[height];
  for (uint32_t i = 0; i < height; i++) {
    this->positions[CARNIVOR][i] = new bool[width];
    for (uint32_t j = 0; j < width; j++) {
      this->positions[CARNIVOR][i][j] = false;
    }
  }

  // set up herbivor positions
  this->positions[HERBIVOR];
  this->positions[HERBIVOR] = new bool*[height];
  for (uint32_t i = 0; i < height; i++) {
    this->positions[HERBIVOR][i] = new bool[width];
    for (uint32_t j = 0; j < width; j++) {
      this->positions[HERBIVOR][i][j] = false;
    }
  }

  // set up plant positions
  this->positions[PLANT];
  this->positions[PLANT] = new bool*[height];
  for (uint32_t i = 0; i < height; i++) {
    this->positions[PLANT][i] = new bool[width];
    for (uint32_t j = 0; j < width; j++) {
      this->positions[PLANT][i][j] = false;
    }
  }
  
}
