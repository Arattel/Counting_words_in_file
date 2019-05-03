//
// Created by arattel on 19.04.19.
//

#ifndef COUNTING_WORDS_IN_FILE_OUTPUT_H
#define COUNTING_WORDS_IN_FILE_OUTPUT_H

#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "config.h"

void write_map_to_file(std::map<std::string, int> dict, std::string file);

template<typename T, typename F>
void write_vector_of_pairs_to_file(std::vector<std::pair<T, F>> vec, std::string file) {
    std::ofstream out(file);
    out << "word,count" << std::endl;
    for (auto const &x : vec) {
        out << "\"" << x.first << "\"" << ", " << x.second << std::endl;
    }
    out.close();
};

void output_sorted_by_number(std::map<std::string, int> map, std::string filename);

#endif //COUNTING_WORDS_IN_FILE_OUTPUT_H
