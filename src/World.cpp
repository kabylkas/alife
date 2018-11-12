#include "World.h"

World::World() {
  this->allow_share = false;
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


// others
uint32_t World::wrap_x(int x) {
  uint32_t result;

  if (x < 0) {
    result = this->width + x;
  } else {
    result = x % this->width;
  }

  return result;
}

uint32_t World::wrap_y(int y) {
  uint32_t result;

  if (y < 0) {
    result = this->height + y;
  } else {
    result = y % this->height;
  }

  return result;
}

void World::init(uint32_t height, uint32_t width, bool allow_share) {
  this->allow_share = allow_share;
  this->height = height;
  this->width = width;

  // set up carnivor positions
  this->positions[CARNIVOR];
  this->positions[CARNIVOR] = new uint32_t*[height];
  for (uint32_t i = 0; i < height; i++) {
    this->positions[CARNIVOR][i] = new uint32_t[width];
    for (uint32_t j = 0; j < width; j++) {
      this->positions[CARNIVOR][i][j] = 0;
    }
  }

  // set up herbivor positions
  this->positions[HERBIVOR];
  this->positions[HERBIVOR] = new uint32_t*[height];
  for (uint32_t i = 0; i < height; i++) {
    this->positions[HERBIVOR][i] = new uint32_t[width];
    for (uint32_t j = 0; j < width; j++) {
      this->positions[HERBIVOR][i][j] = 0;
    }
  }

  // set up plant positions
  this->positions[PLANT];
  this->positions[PLANT] = new uint32_t*[height];
  for (uint32_t i = 0; i < height; i++) {
    this->positions[PLANT][i] = new uint32_t[width];
    for (uint32_t j = 0; j < width; j++) {
      this->positions[PLANT][i][j] = 0;
    }
  }  
}

void World::place_agent_rand(AgentType type, uint32_t* x, uint32_t* y) {
  // find empty spot on the plabe
  uint32_t temp_x;
  uint32_t temp_y;

  if (this->allow_share) {
    temp_x = rand() % this->width;
    temp_y = rand() % this->height;
  } else {
    do {
      temp_x = rand() % this->width;
      temp_y = rand() % this->height;
    } while (positions[CARNIVOR][temp_y][temp_x] ||
             positions[HERBIVOR][temp_y][temp_x] ||
             positions[PLANT][temp_y][temp_x]);
  }

  // place an agent to the spot
  positions[type][temp_y][temp_x]++;

  // return values
  *x = temp_x;
  *y = temp_y;
}

void World::place_agent_to(AgentType type, uint32_t x, uint32_t y) {
  if (this->allow_share) {
    positions[type][y][x]++;
  } else {
    if (positions[CARNIVOR][y][x] || positions[HERBIVOR][y][x] || positions[PLANT][y][x]) {
      std::cout <<"Place is taken" << std::endl;
    } else {
      positions[type][y][x]++;
    }
  }
}

void World::remove_agent_from(AgentType type, uint32_t x, uint32_t y) {
  assert(this->positions[type][y][x] > 0);
  if (this->positions[type][y][x] > 0) {
    this->positions[type][y][x]--;
  }
}

bool World::in_place(AgentType type, uint32_t x, uint32_t y) {
  return positions[type][y][x] > 0;
}

void World::clear_positions() {
  for (uint8_t type = 0; type < NUM_AGENT_TYPE; type++) {
    for (uint32_t i = 0; i < this->height; i++) {
      for (uint32_t j = 0; j < this->width; j++) {
        positions[(AgentType)type][i][j] = 0;
      }
    }
  }
}

// sets
void World::set_width(uint32_t width) {
  this->width = width;
}

void World::set_height(uint32_t height) {
  this->height = height;
}

// gets
uint32_t World::get_width() {
  return this->width;
}

uint32_t World::get_height() {
  return this->height;
}

//others

// debug
void World::draw_positions(AgentType type) {
  char type_char;
  switch (type) {
    case CARNIVOR:
      type_char = 'C';
      break;
    case HERBIVOR:
      type_char = 'H';
      break;
    case PLANT:
      type_char = 'P';
      break;
    default:
      break;
  };

  for (uint32_t i = 0; i < this->height; i++) {
    for (uint32_t j = 0; j < this->width; j++) {
      char to_print;
      if (positions[type][i][j] > 0) {
        to_print = type_char;
      } else {
        to_print = '.';
      }
      std::cout << to_print << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void World::draw_positions() {
  uint8_t c_type_char = 'C';
  uint8_t h_type_char = 'H';
  uint8_t p_type_char = 'P';

  for (uint32_t i = 0; i < this->width; i++) {
    std::cout << i % 10 << " ";
  }
  std::cout << std::endl;

  for (uint32_t i = 0; i < this->height; i++) {
    for (uint32_t j = 0; j < this->width; j++) {
      char to_print;
      if (positions[CARNIVOR][i][j] > 0) {
        to_print = c_type_char;
      } else if (positions[HERBIVOR][i][j] > 0){
        to_print = h_type_char;;
      } else if (positions[PLANT][i][j] > 0) {
        to_print = p_type_char;
      } else {
        to_print = '.';
      }

      std::cout << to_print << " ";
    }
    std::cout << i << std::endl;
  }
  std::cout << std::endl;
}
