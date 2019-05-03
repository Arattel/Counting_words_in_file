//
// Created by arattel on 29.04.19.
//

#ifndef UNZIPPER_UNZIP_H
#define UNZIPPER_UNZIP_H

#include <iostream>
#include <archive.h>
#include <archive_entry.h>
#include <string>

int copy_data(struct archive *ar, struct archive *aw);

int extract(const char *filename, std::string destination);

#endif //UNZIPPER_UNZIP_H
