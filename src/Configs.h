#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Configs {
  public:
    Configs();
    ~Configs();
    bool read_config_file(std::string cfg_file_name);
    uint64_t time;
    uint32_t min_num_carnivors;
    uint32_t min_num_herbivors;
    uint32_t min_num_plants;
    uint32_t num_carnivors;
    uint32_t num_herbivors;
    uint32_t num_plants;
    uint32_t world_height;
    uint32_t world_width;
    uint32_t carn_metabolic_rate;
    uint32_t herb_metabolic_rate;
    uint32_t herb_nutritional_value;
    uint32_t plant_nutritional_value;
    uint32_t sample_rate;
    uint32_t repro_energy_level;
};
