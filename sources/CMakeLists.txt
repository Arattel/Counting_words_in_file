cmake_minimum_required(VERSION 3.10)
project(Counting_words_in_file)


set(CMAKE_CXX_STANDARD 11)
find_package(ICU REQUIRED COMPONENTS uc i18n)
set(CMAKE_CXX_FLAGS "-pthread -fsanitize=thread")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREAD ON)
find_package(Boost REQUIRED COMPONENTS locale system filesystem)
find_package(LibArchive REQUIRED)
INCLUDE_DIRECTORIES(${LibArchive_INCLUDE_DIR})

include_directories(${Boost_INCLUDE_DIRS})
add_executable(Counting_words_in_file main.cpp count_words.h count_words.cpp output.h output.cpp
        merge.cpp merge.h parallel.h parallel.cpp merge.h merge.cpp input.cpp input.h config.h config.cpp
        unzip.h unzip.cpp decompress_list.h decompress_list.cpp)
target_link_libraries(Counting_words_in_file ${Boost_LIBRARIES})
target_link_libraries(Counting_words_in_file ${LibArchive_LIBRARIES})
