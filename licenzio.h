#include <stdio.h>

struct Command {
    char title[20];
    char desc[255];
    char alias;
};

struct License {
  char license_name[50];
  char license_description[255];
  //FILE* path;
};