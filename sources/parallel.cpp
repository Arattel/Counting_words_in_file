//
// Created by arattel on 23.04.19.
//
#include "parallel.h"

std::map<std::string, int>
count_words_parallel(std::vector<std::string>::iterator vector_start, std::vector<std::string>::iterator vector_end,
                     size_t num_threads) {
    ptrdiff_t size = vector_end - vector_start;
    size_t part_size = size / num_threads;
    size_t remainder = size % num_threads;
    std::thread threads[num_threads];
    size_t i;
    std::map<std::string, int> maps[num_threads];
    for (i = 0; i < num_threads; i++) {
        threads[i] = i == num_threads - 1 ? std::thread(count_words_iterator, vector_start + i * part_size,
                                                        vector_start + (i + 1) * part_size + remainder,
                                                        std::ref(maps[i]))
                                          : std::thread(count_words_iterator, vector_start + i * part_size,
                                                        vector_start + (i + 1) * part_size, std::ref(maps[i]));
    }
    for(i = 0; i < num_threads; i++){
        threads[i].join();
    }
    return merge_maps_array(maps, num_threads);
};