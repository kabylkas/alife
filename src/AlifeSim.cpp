#include "AlifeSim.h"

AlifeSim::AlifeSim() {

}

AlifeSim::~AlifeSim() {

}


void AlifeSim::init(std::string cfg_file_name) {
  // read in configs
  bool got_variables = sim_configs.read_config_file(cfg_file_name);
  if (got_variables) {
    // rand seed
    srand(SEED);
    // init the world
    this->world.init(sim_configs.world_height, sim_configs.world_width, ALLOW_PLACE_SHARING);

    // init the agents
    Animal* new_animal;
    // init carnivaor
    for (uint32_t i = 0; i < sim_configs.num_carnivors; i++) {
      // allocate agent
      new_animal = new Carnivor(sim_configs.carn_metabolic_rate);

      // get calculate initial member variable values
      uint32_t x, y;
      Direction facing;
      uint16_t energy_level;
      this->world.place_agent_rand(CARNIVOR, &x, &y);
      facing = (Direction)(rand() % 4);
      energy_level = 100;

      // set initial values
      new_animal->set_id(id_generator.get_id());
      new_animal->set_x(x);
      new_animal->set_y(y);
      new_animal->set_direction(facing);
      new_animal->set_energy(energy_level);
      new_animal->set_world(&(this->world));

      liv_orgs.animals.push_back(new_animal);
    }

    // init herbivors
    for (uint32_t i = 0; i < sim_configs.num_herbivors; i++) {
      // allocate agent
      new_animal = new Herbivor(sim_configs.herb_metabolic_rate);

      // get calculate initial member variable values
      uint32_t x, y;
      Direction facing;
      uint16_t energy_level;
      this->world.place_agent_rand(HERBIVOR, &x, &y);
      facing = (Direction)(rand() % 4);
      uint32_t nutritional_value = sim_configs.herb_nutritional_value;
      energy_level = 100;

      // set initial values
      new_animal->set_id(id_generator.get_id());
      new_animal->set_x(x);
      new_animal->set_y(y);
      new_animal->set_direction(facing);
      new_animal->set_energy(energy_level);
      new_animal->set_world(&(this->world));
      new_animal->set_nutritional_value(nutritional_value);

      liv_orgs.animals.push_back(new_animal);
    }

    // init herbivors
    Plant temp_plant;
    for (uint32_t i = 0; i < sim_configs.num_plants; i++) {
      // get calculate initial member variable values
      uint32_t x, y;
      uint32_t nutritional_value = sim_configs.plant_nutritional_value;
      this->world.place_agent_rand(PLANT, &x, &y);
      
      // set initial values
      temp_plant.set_x(x);
      temp_plant.set_y(y);
      temp_plant.set_nutritional_value(nutritional_value);

      liv_orgs.plants.push_back(temp_plant);
    }
    #ifdef DEBUG
      world.draw_positions();
    #endif
  }
}

void AlifeSim::start() {
  for (uint64_t current_time = 0; current_time < sim_configs.time; current_time++) {
    // perform action
    for (uint32_t i = 0; i < liv_orgs.animals.size(); i++) {
      liv_orgs.animals[i]->take_action(&liv_orgs);
    }

    // increase age of the animals
    for (uint32_t i = 0; i < liv_orgs.animals.size(); i++) {
      liv_orgs.animals[i]->increment_age();
    }

    // update the living organisms, remove those that
    // are killed or used up all of their energy
    // animals:
    for (uint32_t i = 0; i < liv_orgs.animals.size(); i++) {
      if (liv_orgs.animals[i]->is_dead()) {
        #ifdef TRACE
          std::cout << "DEATH: Animal with id " << liv_orgs.animals[i]->get_id() << " is dead" << std::endl;
        #endif
        liv_orgs.animals.erase(liv_orgs.animals.begin() + i);
        // decrease i since indexing has changed after erase
        i -= 2;
      }
    }
    // plants
    for (uint32_t i = 0; i < liv_orgs.plants.size(); i++) {
      if (liv_orgs.plants[i].is_dead()) {
        #ifdef TRACE
          std::cout << "DEATH: Plant is dead" << std::endl;
        #endif
        liv_orgs.plants.erase(liv_orgs.plants.begin() + i);
        // decrease i since indexing has changed after erase
        i -= 2;
      }
    }

    // positions of the animals should be updated
    // this is to avoid problems related to several
    // same type animals sharing positions
    //
    // cleaner way to handle this is
    // to implement position planes as grid of 
    // counters instead of having booleans
    for (uint32_t i = 0; i < liv_orgs.animals.size(); i++) {
      liv_orgs.animals[i]->update_position();
    }

    #ifdef TRACE
      std::cout << current_time << ": ITER_END: Animals in simulations: " << liv_orgs.animals.size() << std::endl;
    #endif
  }
}

void AlifeSim::sustain() {

}
