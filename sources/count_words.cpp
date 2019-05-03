//
// Created by arattel on 19.04.19.
//
#include "count_words.h"


std::map<std::string, int> count_words(std::vector<std::string> words_vector) {
    std::map<std::string, int> dict;
    for (int i = 0; i < words_vector.size(); i++) {
        dict[words_vector[i]]++;
    }
    return dict;
};

void count_words_with_ref(std::map<std::string, int> &result, std::vector<std::string> words_vector) {
    std::map<std::string, int> dict;
    for (int i = 0; i < words_vector.size(); i++) {
        dict[words_vector[i]]++;
    }
    result = dict;
};

void
count_words_iterator(std::vector<std::string>::iterator words_begin, std::vector<std::string>::iterator words_end,
                     std::map<std::string, int> &result) {
    std::map<std::string, int> dict;
    for (auto it = words_begin; it != words_end; it++) {
        dict[*it]++;
    }
    result = dict;
};

