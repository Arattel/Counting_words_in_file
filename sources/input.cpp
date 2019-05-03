//
// Created by arattel on 26.04.19.
//
#include <boost/algorithm/string/predicate.hpp>
#include "input.h"

std::string read(std::string filename) {
    boost::locale::generator gen;
    std::locale::global(gen("en_US.UTF-8"));
    std::fstream input_file_stream;
    input_file_stream.imbue(gen("en_US.UTF-8"));
    input_file_stream.open(filename);
    if (input_file_stream.is_open()) {
        auto const start_pos = input_file_stream.tellg();
        input_file_stream.ignore(std::numeric_limits<std::streamsize>::max());
        auto const char_count = input_file_stream.gcount();
        input_file_stream.seekg(start_pos);
        auto input_string = std::string(char_count, char{});
        input_file_stream.read(&input_string[0], input_string.size());
        return input_string;
    }
};

std::string format(std::string file) {
    boost::locale::generator gen;
    std::locale::global(gen("en_US.UTF-8"));
    std::string normalized = boost::locale::normalize(file);
    return boost::locale::fold_case(file);
}

std::vector<std::string> get_words(std::string formatted_file) {
    std::vector<std::string> words;
    boost::locale::generator gen;
    auto utf = gen("en_US.UTF-8");
    std::locale::global(utf);
    boost::locale::boundary::ssegment_index map(boost::locale::boundary::word, formatted_file.begin(),
                                                formatted_file.end(), utf);
    for (boost::locale::boundary::ssegment_index::iterator it = map.begin(), e = map.end(); it != e; ++it) {
        if (*it > "A") {
            words.push_back(*it);

        }
    }
    return words;
};
