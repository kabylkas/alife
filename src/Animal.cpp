#include "Animal.h"

Animal::Animal() {
  this->x = 0;
  this->y = 0;
  this->facing = EAST;
  this->energy_level = 100;
  this->facing = NORTH;
  this->age = 0;
  this->id = 0;
  this->dead = false;
  this->eyes.set_brain(&(this->brain));
}

Animal::~Animal() {

}

void Animal::move() {
  // remove the old position in the world
  this->eyes.get_world()->remove_agent_from(this->get_type(), this->x, this->y);

  // update positions
  switch (this->facing) {
    case NORTH:
      this->y = this->eyes.wrap_y(this->y - 1);
      break;

    case EAST:
      this->x = this->eyes.wrap_x(this->x + 1);
      break;

    case SOUTH:
      this->y = this->eyes.wrap_y(this->y + 1);
      break;

    case WEST:
      this->x = this->eyes.wrap_x(this->x - 1);
      break;

    default:
      std::cout << "Unknown direction, something wrong" << std::endl;
      break;
  }

  // update the position in the world
  this->eyes.get_world()->place_agent_to(this->get_type(), this->x, this->y);

#ifdef TRACE
  std::cout << "MOVE: Animal with id: " << this->id << " moved to position: (" << this->x << ", " << this->y << ")" << std::endl;
#endif
}

void Animal::turn_left() {
  // get the facing direction
  int current_direction = (uint8_t)this->facing;

  // suptract 1 to turn left
  current_direction--;
  if (current_direction < 0) {
    current_direction = NUM_DIRECTION - 1;
  }

  // update facing direction
  this->facing = (Direction)current_direction;

#ifdef TRACE
  std::cout << "TURN_LEFT: Animal with id: " << this->id << " is now facing: " << this->facing << std::endl;
#endif
}

void Animal::turn_right() {
  // get the facing direction
  uint8_t current_direction = (uint8_t)this->facing;

  // add 1 to turn right, Direction enum is ordered circularly
  current_direction = (current_direction + 1) % NUM_DIRECTION;

  // update facing direction
  this->facing = (Direction)current_direction;

#ifdef TRACE
  std::cout << "TURN_RIGHT: Animal with id: " << this->id << " is now facing: " << this->facing << std::endl;
#endif
}

void Animal::take_action(LivingOrganisms* liv_orgs) {
  // observe, remember the inputs
  this->eyes.observe(this->facing, this->x, this->y);
  
  // decide based on observation
  ActionType decision = this->brain.decide();

  switch (decision) {
    case EAT:
      this->eat(liv_orgs);
      break;

    case TURN_LEFT:
      this->turn_left();
      break;

    case TURN_RIGHT:
      this->turn_right();
      break;

    case MOVE:
      this->move();
      break;

    default:
      std::cout << "Non-existing decision made! Should not be here!" << std::endl;
      break;
  }

  // every action decrease energy
  this->energy_level -= this->get_metabolic_rate();

  // check if animal has enough energy to live
  if (this->energy_level <= 0) {
    this->die();
    this->eyes.get_world()->remove_agent_from(this->get_type(), this->x, this->y);
  }

  // if enought energy, reproduce
  if (this->energy_level > 170) {
    // reproduce agent
    this->reproduce(liv_orgs);
    // place child to the world
    this->eyes.get_world()->place_agent_to(this->get_type(), this->x, this->y);
  }
}

void Animal::increment_age() {
  this->age++;
}

bool Animal::is_alive() {
  return !(this->dead);
}

bool Animal::is_dead() {
  return this->dead;
}

void Animal::die() {
  this->energy_level = -100;
  this->dead = true;
}

void Animal::new_born_reset(uint64_t id) {
  this->id = id;
  this->age = 0;
  this->eyes.set_brain(&(this->brain));
}

//sets
void Animal::set_world(World* world) {
  this->eyes.set_world(world);
}

void Animal::set_offsets(Offsets* offsets) {
  this->eyes.set_offsets(offsets);
}

void Animal::set_x(uint32_t x) {
  this->x = x;
}

void Animal::set_y(uint32_t y) {
  this->y = y;
}

void Animal::set_direction(Direction facing) {
  this->facing = facing;
}

void Animal::set_energy(int energy_level) {
  this->energy_level = energy_level;
}

void Animal::set_id(uint64_t id) {
  this->id = id;
}

void Animal::set_age(uint64_t age) {
  this->age = age;
}

//gets
Brain* Animal::get_brain() {
  return &(this->brain);
}

uint64_t Animal::get_id() {
  return this->id;
}

uint32_t Animal::get_x() {
  return this->x;
}

uint32_t Animal::get_y() {
  return this->y;
}

uint64_t Animal::get_age() {
  return this->age;
}
