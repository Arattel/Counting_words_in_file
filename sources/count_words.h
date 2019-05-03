//
// Created by arattel on 19.04.19.
//

#ifndef COUNTING_WORDS_IN_FILE_READ_TEXT_TO_MEMORY_H
#define COUNTING_WORDS_IN_FILE_READ_TEXT_TO_MEMORY_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

std::map<std::string, int> count_words(std::vector<std::string> words);

void count_words_with_ref(std::map<std::string, int> &result, std::vector<std::string> words_vector);

void
count_words_iterator(std::vector<std::string>::iterator words_begin, std::vector<std::string>::iterator words_end,
                     std::map<std::string, int> &result);

#endif //COUNTING_WORDS_IN_FILE_READ_TEXT_TO_MEMORY_H
