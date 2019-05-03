#include <iostream>
#include <vector>
#include <boost/locale.hpp>
#include "count_words.h"
#include "output.h"
#include "merge.h"
#include "parallel.h"
#include "input.h"
#include "config.h"
#include <algorithm>
#include "decompress_list.h"
#include <boost/algorithm/string/predicate.hpp>


inline std::chrono::high_resolution_clock::time_point get_current_time_fenced() {
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D &d) {
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}

int main(int argc, char **argv) {
    std::string config_filename;
    config configuration;
    std::string destination = "archive/";
    std::string input_file;
    if (argc > 1) {
        config_filename = argv[1];
    } else {
        config_filename = "config.dat";
    }
    configuration = read_config_from_file(config_filename);
    if (!boost::algorithm::ends_with(configuration.infile, ".txt")) {
        extract(configuration.infile.c_str(), destination);
        input_file = destination + read_directory(destination)[0];
    } else {
        input_file = configuration.infile;
    }
    auto start = get_current_time_fenced();
    std::vector<std::string> words_vector = get_words(format(read(input_file)));
    auto reading_ends = get_current_time_fenced();
    std::map<std::string, int> words_counted = count_words_parallel(words_vector.begin(), words_vector.end(),
                                                                    configuration.threads);
    auto counting_ends = get_current_time_fenced();
    write_map_to_file(words_counted, configuration.out_by_a);
    output_sorted_by_number(words_counted, configuration.out_by_n);
    auto end = get_current_time_fenced();
    std::cout << "Loading: " << to_us(reading_ends - start) << std::endl;
    std::cout << "Analyzing: " << to_us(counting_ends - reading_ends) << std::endl;
    std::cout << "Total: " <<to_us(end - start) << std::endl;
}
