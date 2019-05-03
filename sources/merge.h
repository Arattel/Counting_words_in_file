//
// Created by arattel on 19.04.19.
//

#ifndef COUNTING_WORDS_IN_FILE_MERGE_H
#define COUNTING_WORDS_IN_FILE_MERGE_H

#include <map>
#include <string>
#include <vector>

std::map<std::string, int> merge_two_maps(std::map<std::string, int> dict0, std::map<std::string, int> dict1);

std::map<std::string, int> merge_maps_array(std::map<std::string, int> *maps, size_t length);

#endif //COUNTING_WORDS_IN_FILE_MERGE_H
