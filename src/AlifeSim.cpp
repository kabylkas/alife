#include "AlifeSim.h"

AlifeSim::AlifeSim() {
  this->max_age = 0;
  this->max_population = 0;
  this->reproductions_happened = 0;
  liv_orgs.set_id_generator(&(this->id_generator));
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

    // init carnivaor
    liv_orgs.num_carnivors = sim_configs.num_carnivors;
    for (uint32_t i = 0; i < sim_configs.num_carnivors; i++) {
      liv_orgs.animals.push_back(this->get_random_carnivor());
    }

    // init herbivors
    liv_orgs.num_herbivors = sim_configs.num_herbivors;
    for (uint32_t i = 0; i < sim_configs.num_herbivors; i++) {
      liv_orgs.animals.push_back(this->get_random_herbivor());
    }

    // init herbivors
    liv_orgs.num_plants = sim_configs.num_plants;
    for (uint32_t i = 0; i < sim_configs.num_plants; i++) {
      liv_orgs.plants.push_back(this->get_random_plant());
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
      if (liv_orgs.animals[i]->is_alive()) {
        liv_orgs.animals[i]->take_action(&liv_orgs);
      }
    }

    // increase age of the animals
    for (uint32_t i = 0; i < liv_orgs.animals.size(); i++) {
      liv_orgs.animals[i]->increment_age();
      if (this->max_age < liv_orgs.animals[i]->get_age()) {
        this->max_age = liv_orgs.animals[i]->get_age();
      }
    }

    // update the living organisms, remove those that
    // are killed or used up all of their energy
    // animals:
    for (uint32_t i = 0; i < liv_orgs.animals.size(); i++) {
      if (liv_orgs.animals[i]->is_dead()) {
        #ifdef TRACE
          std::cout << "DEATH: Animal with id " << liv_orgs.animals[i]->get_id() << " is dead" << std::endl;
        #endif
        Animal* dead_animal = liv_orgs.animals[i];
        AgentType type = dead_animal->get_type();
        // update the count in the simulation
        if (type == CARNIVOR) {
          liv_orgs.num_carnivors--;
        } else {
          liv_orgs.num_herbivors--;
        }
        // erase dead animal
        this->world.remove_agent_from(type, dead_animal->get_x(), dead_animal->get_y());
        delete dead_animal;
        liv_orgs.animals.erase(liv_orgs.animals.begin() + i);

        // decrease i since indexing has changed after erase
        i -= 1;
      }
    }
    // plants
    for (uint32_t i = 0; i < liv_orgs.plants.size(); i++) {
      if (liv_orgs.plants[i].is_dead()) {
        #ifdef TRACE
          std::cout << "DEATH: Plant is dead" << std::endl;
        #endif
        liv_orgs.plants.erase(liv_orgs.plants.begin() + i);
        liv_orgs.num_plants--;
        // decrease i since indexing has changed after erase
        i -= 1;
      }
    }

    #ifdef TRACE
      std::cout << current_time << ": ITER_END: Animals in simulations: " << liv_orgs.animals.size() << std::endl;
    #endif
    assert(liv_orgs.num_carnivors + liv_orgs.num_herbivors == liv_orgs.animals.size());
    assert(liv_orgs.num_plants == liv_orgs.plants.size());

    // sustain the life in simulation
    this->sustain();

    //reproduce to hose that have enough energy
    std::vector<Animal*> new_born_animals;
    for (uint32_t i = 0; i < liv_orgs.animals.size(); i++) {
      Animal* parent = liv_orgs.animals[i];
      if (parent->get_energy() > sim_configs.repro_energy_level) {
        this->reproductions_happened++;
        // update energy, reproduction takes energy
        uint32_t new_energy = parent->get_energy() / 2;
        parent->set_energy(new_energy);

        // generate new animal
        Animal* child;
        if (parent->get_type() == CARNIVOR) {
          child = get_random_carnivor();
          liv_orgs.num_carnivors++;
        } else {
          child = get_random_herbivor();
          liv_orgs.num_herbivors++;
        }

        // transfer parents brain to child
        parent->get_brain()->transfer(child->get_brain());

        // mutate child's brain
        child->get_brain()->mutate(0.2);

        // some updates on child
        child->set_energy(new_energy);

        // place child to the crowd
        new_born_animals.push_back(child);
      }
    }
    // place new borns to the life
    while (new_born_animals.size() > 0) {
      liv_orgs.animals.push_back(new_born_animals[new_born_animals.size() - 1]);
      new_born_animals.pop_back();
    }

    // some initial stats update
    if (this->max_population < liv_orgs.animals.size()) {
      this->max_population = liv_orgs.animals.size();
    }

    if (current_time % sim_configs.sample_rate == 0) {
      std::cout << current_time << ", " << liv_orgs.animals.size() << ", " << this->reproductions_happened << std::endl;
      this->reproductions_happened = 0;
    }
  }
}

void AlifeSim::sustain() {
  while (liv_orgs.num_carnivors < sim_configs.min_num_carnivors) {
    #ifdef DEBUG
      std::cout << "Sustaining carnivors... Current: " << liv_orgs.num_carnivors << "; Min: " << sim_configs.min_num_carnivors << std::endl;
    #endif
    liv_orgs.animals.push_back(this->get_random_carnivor());
    liv_orgs.num_carnivors++;
  }

  while (liv_orgs.num_herbivors < sim_configs.min_num_herbivors) {
    #ifdef DEBUG
      std::cout << "Sustaining herbivors... Current: " << liv_orgs.num_herbivors << "; Min: " << sim_configs.min_num_herbivors << std::endl;
    #endif
    liv_orgs.animals.push_back(this->get_random_herbivor());
    liv_orgs.num_herbivors++;
  }

  while (liv_orgs.num_plants < sim_configs.min_num_plants) {
    #ifdef DEBUG
      std::cout << "Sustaining plants... Current: " << liv_orgs.num_plants << "; Min: " << sim_configs.min_num_plants << std::endl;
    #endif
    liv_orgs.plants.push_back(this->get_random_plant());
    liv_orgs.num_plants++;
  }
}

Animal* AlifeSim::get_random_herbivor() {
  // allocate agent
  Animal* new_animal = new Herbivor(sim_configs.herb_metabolic_rate);

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
  new_animal->set_offsets(&(this->offsets));
  new_animal->set_nutritional_value(nutritional_value);

  return new_animal;
}

Animal* AlifeSim::get_random_carnivor() {
  // allocate agent
  Animal* new_animal = new Carnivor(sim_configs.carn_metabolic_rate);

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
  new_animal->set_offsets(&(this->offsets));
  
  return new_animal;
}

Plant AlifeSim::get_random_plant() {
  Plant temp_plant;
  // get calculate initial member variable values
  uint32_t x, y;
  uint32_t nutritional_value = sim_configs.plant_nutritional_value;
  this->world.place_agent_rand(PLANT, &x, &y);
  
  // set initial values
  temp_plant.set_x(x);
  temp_plant.set_y(y);
  temp_plant.set_nutritional_value(nutritional_value);

  return temp_plant;
}
