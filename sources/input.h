//
// Created by arattel on 26.04.19.
//

#ifndef COUNTING_WORDS_IN_FILE_INPUT_H
#define COUNTING_WORDS_IN_FILE_INPUT_H

#include <fstream>
#include <ostream>
#include <iostream>
#include <limits>
#include <boost/locale.hpp>
#include <vector>
#include <boost/algorithm/string/classification.hpp>

std::string read(std::string filename);

std::string format(std::string file);

std::vector<std::string> get_words(std::string formatted_file);

#endif //COUNTING_WORDS_IN_FILE_INPUT_H
