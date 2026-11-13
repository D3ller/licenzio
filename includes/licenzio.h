#ifndef LICENZIO_LICENZIO_H
#define LICENZIO_LICENZIO_H

#define NAME "Licenzio"
#define VERSION "0.1.0"
#define DESCRIPTION "A CLI tool for adding license files to your projects"
#define GITHUB_URL "https://github.com/d3ller/licenzio"

#include <stdio.h>

struct Command {
    char title[20];
    char desc[255];
    char alias;
};

struct License {
  char license_name[50];
  char license_description[255];
  size_t size;
  const unsigned char *bytes;
};

#endif