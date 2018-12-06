#include "AlifeSim.h"

AlifeSim::AlifeSim() {
  this->max_age = 0;
  this->max_population = 0;
  this->carn_reproductions_happened = 0;
  this->herb_reproductions_happened = 0;
  this->carn_death_happened = 0;
  this->herb_death_happened = 0;
  this->plants_eatan = 0;
  this->herbs_eatan = 0;
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
    this->world.init(sim_configs.world_height, sim_configs.world_width, sim_configs.allow_sharing);

    // init carnivaor
    for (uint32_t i = 0; i < sim_configs.num_carnivors; i++) {
      liv_orgs.add_animal(this->get_random_animal(CARNIVOR));
    }

    // init herbivors
    for (uint32_t i = 0; i < sim_configs.num_herbivors; i++) {
      liv_orgs.add_animal(this->get_random_animal(HERBIVOR));
    }

    // init herbivors
    for (uint32_t i = 0; i < sim_configs.num_plants; i++) {
      liv_orgs.add_plant(this->get_random_plant());
    }

    #ifdef DEBUG
      world.draw_positions();
    #endif
  }
}

void AlifeSim::start() {
  for (uint64_t current_time = 0; current_time < sim_configs.time; current_time++) {
    // perform action
    for (uint32_t i = 0; i < liv_orgs.get_num_animals(); i++) {
      if (liv_orgs.get_animal(i)->is_alive()) {
        liv_orgs.get_animal(i)->take_action(&liv_orgs);
      }
    }

    // increase age of the animals
    for (uint32_t i = 0; i < liv_orgs.get_num_animals(); i++) {
      liv_orgs.get_animal(i)->increment_age();
      uint64_t age = liv_orgs.get_animal(i)->get_age();
      if (this->max_age < age) {
        this->max_age = age;
      }
    }

    // update the living organisms, remove those that
    // are killed or used up all of their energy
    // animals:
    for (uint32_t i = 0; i < liv_orgs.get_num_animals(); i++) {
      if (liv_orgs.get_animal(i)->is_dead()) {
        #ifdef TRACE
          std::cout << "DEATH: Animal with id " << liv_orgs.get_animal(i)->get_id() << " is dead" << std::endl;
        #endif
        Animal* dead_animal = liv_orgs.get_animal(i);
        AgentType type = dead_animal->get_type();

        // stats gathering
        if (type == CARNIVOR) {
          this->carn_death_happened++;
        } else {
          this->herb_death_happened++;
          if (dead_animal->is_killed()) {
            this->herbs_eatan++;
          }
        }

        // erase dead animal
        this->world.remove_agent_from(type, dead_animal->get_x(), dead_animal->get_y());
        liv_orgs.remove_animal(i);

        // decrease i since indexing has changed after erase
        i -= 1;
      }
    }

    // plants
    for (uint32_t i = 0; i < liv_orgs.get_num_plants(); i++) {
      if (liv_orgs.get_plant(i)->is_dead()) {
        #ifdef TRACE
          std::cout << "DEATH: Plant is dead" << std::endl;
        #endif
        liv_orgs.remove_plant(i);

        //stats gathering
        this->plants_eatan++;

        // decrease i since indexing has changed after erase
        i -= 1;
      }
    }

    #ifdef TRACE
      std::cout << current_time << ": ITER_END: Animals in simulations: " << liv_orgs.animals.get_num_animals() << std::endl;
    #endif

    // sustain the life in simulation
    this->sustain();

    //reproduce those that have enough energy
    std::vector<Animal*> new_born_animals;
    for (uint32_t i = 0; i < liv_orgs.get_num_animals(); i++) {
      Animal* parent = liv_orgs.get_animal(i);
      if (parent->get_energy() > sim_configs.repro_energy_level) {
        // update energy, reproduction takes energy
        uint32_t new_energy = parent->get_energy() / 2;
        parent->set_energy(new_energy);

        // generate new animal
        Animal* child;
        child = get_random_animal(parent->get_type());
        
        // stats gathering
        if (parent->get_type() == CARNIVOR) {
          this->carn_reproductions_happened++;
        } else {
          this->herb_reproductions_happened++;
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
      liv_orgs.add_animal(new_born_animals[new_born_animals.size() - 1]);
      new_born_animals.pop_back();
    }

    // stats gathering
    uint64_t current_population = liv_orgs.get_num_animals();
    if (current_population > this->max_population) {
      this->max_population = current_population;
    }

    // stats report
    if (current_time % sim_configs.sample_rate == 0) {
      // spit out some report
      std::cout << current_time << ", ";
      std::cout << liv_orgs.get_num_animals() << ", ";
      std::cout << this->carn_reproductions_happened << ", ";
      std::cout << this->herb_reproductions_happened << ", ";
      std::cout << this->carn_death_happened << ", ";
      std::cout << this->herb_death_happened << ", ";
      std::cout << this->herbs_eatan << ", ";
      std::cout << this->plants_eatan << std::endl;

      // reset counters
      this->carn_reproductions_happened = 0;
      this->herb_reproductions_happened = 0;
      this->carn_death_happened = 0;
      this->herb_death_happened = 0;
      this->herbs_eatan = 0;
      this->plants_eatan = 0;
    }
  }
}

void AlifeSim::sustain() {
  while (liv_orgs.get_num_carnivors() < sim_configs.min_num_carnivors) {
    #ifdef DEBUG
      std::cout << "Sustaining carnivors... Current: " << liv_orgs.get_num_carnivors() << "; Min: " << sim_configs.min_num_carnivors << std::endl;
    #endif
    liv_orgs.add_animal(this->get_random_animal(CARNIVOR));
  }

  while (liv_orgs.get_num_herbivors() < sim_configs.min_num_herbivors) {
    #ifdef DEBUG
      std::cout << "Sustaining herbivors... Current: " << liv_orgs.get_num_herbivors() << "; Min: " << sim_configs.min_num_herbivors << std::endl;
    #endif
    liv_orgs.add_animal(this->get_random_animal(HERBIVOR));
  }

  while (liv_orgs.get_num_plants() < sim_configs.min_num_plants) {
    #ifdef DEBUG
      std::cout << "Sustaining plants... Current: " << liv_orgs.get_num_plants() << "; Min: " << sim_configs.min_num_plants << std::endl;
    #endif
    liv_orgs.add_plant(this->get_random_plant());
  }
}

Animal* AlifeSim::get_random_animal(AgentType type) {
  // allocate agent
  Animal* new_animal;

  if (type == CARNIVOR) {
    new_animal = new Carnivor();
  } else {
    new_animal = new Herbivor();
  }

  // get calculate initial member variable values
  uint32_t x, y;
  Direction facing;
  uint16_t energy_level;
  this->world.place_agent_rand(type, &x, &y);
  facing = (Direction)(rand() % 4);
  energy_level = 100;
  uint32_t metabolic_rate = sim_configs.carn_metabolic_rate;

  // set common initial values
  new_animal->set_id(id_generator.get_id());
  new_animal->set_x(x);
  new_animal->set_y(y);
  new_animal->set_direction(facing);
  new_animal->set_energy(energy_level);
  new_animal->set_world(&(this->world));
  new_animal->set_offsets(&(this->offsets));
  new_animal->set_metabolic_rate(metabolic_rate); 

  // set herbivor specific values
  if (type == HERBIVOR) {
    uint32_t nutritional_value = sim_configs.herb_nutritional_value;
    new_animal->set_nutritional_value(nutritional_value);
  }

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
