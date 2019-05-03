//
// Created by arattel on 23.04.19.
//

#ifndef COUNTING_WORDS_IN_FILE_PARALLEL_H
#define COUNTING_WORDS_IN_FILE_PARALLEL_H

#include <vector>
#include <map>
#include "count_words.h"
#include <thread>
#include "output.h"
#include "merge.h"

std::map<std::string, int>
count_words_parallel(std::vector<std::string>::iterator vector_start, std::vector<std::string>::iterator vector_end,
                     size_t num_threads);

#endif //COUNTING_WORDS_IN_FILE_PARALLEL_H
