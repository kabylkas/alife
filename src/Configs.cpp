#include "Configs.h"

Configs::Configs() {
  this->time                    = 0;
  this->min_num_carnivors       = 0;
  this->min_num_plants          = 0;
  this->min_num_herbivors       = 0;
  this->num_plants              = 0;
  this->num_herbivors           = 0;
  this->num_plants              = 0;
  this->world_height            = 0;
  this->world_width             = 0;
  this->carn_metabolic_rate     = 0;
  this->herb_metabolic_rate     = 0;
  this->herb_nutritional_value  = 0;
  this->plant_nutritional_value = 0;
}

Configs::~Configs() {

}

bool Configs::read_config_file(std::string cfg_file_name) {
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
      bool carn_m_rate_found     = false;
      bool herb_m_rate_found     = false;
      bool herb_nut_value_found  = false;
      bool plant_nut_value_found = false;
      bool min_num_carn_found    = false;
      bool min_num_herb_found    = false;
      bool min_num_plant_found   = false;

      simulation_time_found = (line.find("simulation-time") != std::string::npos);
      num_carnivors_found   = (line.find("num-carnivors") != std::string::npos);
      num_herbivors_found   = (line.find("num-herbivors") != std::string::npos);
      num_plants_found      = (line.find("num-plants") != std::string::npos);
      min_num_carn_found    = (line.find("min-num-carnivors") != std::string::npos);
      min_num_herb_found    = (line.find("min-num-herbivors") != std::string::npos);
      min_num_plant_found   = (line.find("min-num-plants") != std::string::npos);
      world_height_found    = (line.find("world-height") != std::string::npos);
      world_width_found     = (line.find("world-width") != std::string::npos);
      carn_m_rate_found     = (line.find("carnivor-metabolic-rate") != std::string::npos);
      herb_m_rate_found     = (line.find("herbivor-metabolic-rate") != std::string::npos);
      herb_m_rate_found     = (line.find("herbivor-metabolic-rate") != std::string::npos);
      herb_nut_value_found  = (line.find("herbivor-nutritional-value") != std::string::npos);
      plant_nut_value_found = (line.find("plant-nutritional-value") != std::string::npos);


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
      if (simulation_time_found)
      {
        this->time = temp_value;
      } 
      else if (min_num_carn_found)
      {
        this->min_num_carnivors = temp_value;
      } 
      else if (min_num_herb_found)
      {
        this->min_num_herbivors = temp_value;
      } 
      else if (min_num_plant_found)
      {
        this->min_num_plants = temp_value;
      } 
      else if (num_carnivors_found)
      {
        this->num_carnivors = temp_value;
      } 
      else if (num_herbivors_found)
      {
        this->num_herbivors = temp_value;
      } 
      else if (num_plants_found)
      {
        this->num_plants = temp_value;
      } 
      else if (world_height_found)
      {
        this->world_height = temp_value;
      } 
      else if (world_width_found)
      {
        this->world_width = temp_value;
      } 
      else if (carn_m_rate_found)
      {
        this->carn_metabolic_rate = temp_value;
      } 
      else if (herb_m_rate_found)
      {
        this->herb_metabolic_rate = temp_value;
      } 
      else if (herb_nut_value_found)
      {
        this->herb_nutritional_value = temp_value;
      } 
      else if (plant_nut_value_found)
      {
        this->plant_nutritional_value = temp_value;
      } 
      else
      {
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
