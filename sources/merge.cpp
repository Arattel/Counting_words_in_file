//
// Created by arattel on 19.04.19.
//
#include "merge.h"



std::map<std::string, int> merge_two_maps(std::map<std::string, int> dict0, std::map<std::string, int> dict1) {
    std::map<std::string, int> result;
    std::map<std::string, int>::iterator it;
    for(std::map<std::string, int> map_for_merge:{dict0, dict1}){
        for(it = map_for_merge.begin(); it != map_for_merge.end(); it++){
            result[it->first] += it->second;
        }
    }
    return result;
};

std::map<std::string, int> merge_maps_array(std::map<std::string, int> *maps, size_t length) {
    std::map<std::string, int> result = maps[0];
    for (size_t i = 1; i < length; i++) {
        result = merge_two_maps(maps[i], result);
    }
    return result;
};
