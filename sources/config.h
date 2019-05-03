//
// Created by arattel on 28.04.19.
//

#ifndef COUNTING_WORDS_IN_FILE_CONFIG_H
#define COUNTING_WORDS_IN_FILE_CONFIG_H

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

struct config {
    std::string infile;
    std::string out_by_a;
    std::string out_by_n;
    size_t threads;
};

config read_config_from_file(std::string filename);

std::string get_config_value(std::string line);
#endif //COUNTING_WORDS_IN_FILE_CONFIG_H
