//
// Created by arattel on 29.04.19.
//
#include "decompress_list.h"



std::vector<std::string> read_directory(const std::string& name){
    std::vector<std::string> v;
    boost::filesystem::path p(name);
    boost::filesystem::directory_iterator start(p);
    boost::filesystem::directory_iterator end;
    std::transform(start, end, std::back_inserter(v), path_leaf_string());
    return v;
}


//std::vector<std::string> extract_and_get_list(std::string archive_path, std::string destination) {
//    extract(archive_path.c_str(), destination);
//    return get_list(destination);
//}
//
//std::vector<std::string> get_list(std::string directory){
//    std::vector<std::string> result;
//    DIR *dir;
//    struct dirent *ent;
//    if ((dir = opendir (directory.c_str())) != NULL) {
//        /* print all the files and directories within directory */
//        while ((ent = readdir (dir)) != NULL) {
//            result.push_back(ent->d_name);
//        }
//        closedir (dir);
//    } else {
//        /* could not open directory */
//        perror ("");
//        return std::vector<std::string>();;
//    }
//    return result;
//}
//


