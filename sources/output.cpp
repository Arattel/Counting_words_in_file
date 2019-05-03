//
// Created by arattel on 19.04.19.
//
#include "output.h"

void write_map_to_file(std::map<std::string, int> dict, std::string file) {
    std::ofstream out(file);
    out << "word,count" << std::endl;
    for (auto const &x : dict) {
        out << "\"" << x.first << "\"" << ", " << x.second << std::endl;
    }
    out.close();
}

void output_sorted_by_number(std::map<std::string, int> map, std::string filename){
    std::vector<std::pair<std::string, int>> vec(map.begin(), map.end());
    std::sort(vec.begin(), vec.end(), [](const std::pair<std::string,int> &a,
                                         const std::pair<std::string,int> &b) ->
    bool {
        return (a.second > b.second);
    });
    write_vector_of_pairs_to_file(vec, filename);
}
