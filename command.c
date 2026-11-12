#include "licenzio.h"
#include "utils.h"
#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define name "Licenzio"
#define version "0.0.1"
#define description "A CLI tool for adding license files to your projects"
#define github_url "https://github.com/d3ller/licenzio"

void generate_help(struct License *licenseList, int licenseCount) {
  struct Command commands[] = {{"help", "Show this help message", 'h'},
                               {"version", "Show version info", 'v'},
                               {"license", "Show the license available", 'l'},
                               {"output", "Output directory / path", 'o'}};

  int count = sizeof(commands) / sizeof(commands[0]);
  char lower[64];
  
  printf("USAGE: ./%s <license_name> [OPTIONS]\n\n", string_to_lower(name, lower));
  printf("license_name :\n");

  print_licenses(licenseList, licenseCount, 1);
  
  printf("\nOPTIONS:\n");
  for (int i = 0; i < count; i++) {
    printf("\t-%-c, --%-20s %-12s\n", commands[i].alias, commands[i].title,
           commands[i].desc);
  }
  printf("\n");
}

void read_version(void) {
  printf("%s v%s\n\n%s\n\nRepository URL: %s\n", name, version, description,
         github_url);
}

void print_licenses(struct License *licenseList, int licenseCount, int is_help) {
    if(!is_help) {
        printf("Available licenses (%d):\n", licenseCount);
    }
    for(int i = 0; i < licenseCount; i++) {
        printf("\t%-10s: %-s\n", licenseList[i].license_name, licenseList[i].license_description);
    }
}