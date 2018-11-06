#include "AlifeSim.h"

AlifeSim::AlifeSim() {

}

AlifeSim::~AlifeSim() {

}

bool AlifeSim::read_config_file(std::string cfg_file_name) {
  bool result = true;
  std::string error_msg = "";

  std::ifstream cfg_file(cfg_file_name);
  if (cfg_file.is_open()) {
    std::string line;
    while (std::getline(cfg_file, line)) {
      // Check for valid simulation variable
      bool simulation_time_found = false;
      bool num_carnivors_found   = false;
      bool num_herbivors_found   = false;
      bool num_plants_found      = false;
      bool world_height_found    = false;
      bool world_width_found     = false;

      simulation_time_found = (line.find("simulation-time") != std::string::npos);
      num_carnivors_found   = (line.find("num-carnivor") != std::string::npos);
      num_herbivors_found   = (line.find("num-herbivors") != std::string::npos);
      num_plants_found      = (line.find("num-plants") != std::string::npos);
      world_height_found    = (line.find("world-height") != std::string::npos);
      world_width_found     = (line.find("world-width") != std::string::npos);

      // Extract value
      int eq_pos = line.find("=");
      int temp_value = 0;
      if (eq_pos != std::string::npos) {
        std::string post_eq = line.substr(eq_pos + 1);
        temp_value = std::stoi(post_eq);
      } else {
        error_msg = "No equal sign in the line. Check config file.";
        result = false;
        break;
      } 

      // Assign to config file
      if (simulation_time_found) {
        sim_configs.time = temp_value;
      } else if (num_carnivors_found) {
        sim_configs.num_carnivors = temp_value;
      } else if (num_herbivors_found) {
        sim_configs.num_herbivors = temp_value;
      } else if (num_plants_found) {
        sim_configs.num_plants = temp_value;
      } else if (world_height_found) {
        sim_configs.world_height = temp_value;
      } else if (world_width_found) {
        sim_configs.world_width = temp_value;
      } else {
        error_msg = "Unknown configuration variable: "+line;
        result = false;
        break;
      }
    }
  } else {
    error_msg = "Unable to open config file";
    result = false;
  }

  if (result) {
    std::cout << "Successfully read config file..." << std::endl;
  } else {
    std::cout << error_msg << std::endl;
  }
  return result;
}

void AlifeSim::init(std::string cfg_file_name) {
  // read in configs
  bool got_variables = this->read_config_file(cfg_file_name);
  if (got_variables) {
    // init the world
    this->world.init(sim_configs.world_height, sim_configs.world_width);
    this->world.set_liv_orgs(&(this->liv_orgs));

    // init the agents
    Animal* new_animal;
    // init carnivaor
    for (uint32_t i = 0; i < sim_configs.num_carnivors; i++) {
      // allocate agent
      new_animal = new Carnivor();

      // get calculate initial member variable values
      uint32_t x, y;
      Direction facing;
      uint16_t energy_level;
      this->world.place_agent_rand(CARNIVOR, &x, &y);
      facing = (Direction)(rand() % 4);
      energy_level = 100;

      // set initial values
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
      new_animal = new Herbivor();

      // get calculate initial member variable values
      uint32_t x, y;
      Direction facing;
      uint16_t energy_level;
      this->world.place_agent_rand(HERBIVOR, &x, &y);
      facing = (Direction)(rand() % 4);
      energy_level = 100;

      // set initial values
      new_animal->set_x(x);
      new_animal->set_y(y);
      new_animal->set_direction(facing);
      new_animal->set_energy(energy_level);
      new_animal->set_world(&(this->world));

      liv_orgs.animals.push_back(new_animal);
    }

    // init herbivors
    Plant temp_plant;
    for (uint32_t i = 0; i < sim_configs.num_plants; i++) {
      // get calculate initial member variable values
      uint32_t x, y;
      uint16_t nutrition_level;
      this->world.place_agent_rand(PLANT, &x, &y);
      
      // set initial values
      temp_plant.set_x(x);
      temp_plant.set_y(y);
      temp_plant.set_nutrition_level(nutrition_level);

      liv_orgs.plants.push_back(temp_plant);
    }
    #ifdef DEBUG
      world.draw_positions();
    #endif
  }
}

void AlifeSim::start() {
  for (uint64_t current_time = 0; current_time < sim_configs.time; current_time++) {
    for (uint32_t i = 0; i < liv_orgs.animals.size(); i++) {
      liv_orgs.animals[i]->take_action();
    }
  }
}
