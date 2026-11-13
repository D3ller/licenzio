#include "../includes/licenzio.h"
#include "../includes/utils.h"
#include "../includes/command.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_help(const struct License *licenseList, size_t licenseCount) {
  struct Command commands[] = {{"help", "Show this help message", 'h'},
                               {"version", "Show version info", 'v'},
                               {"license", "Show the license available", 'l'},
                               {"output", "Output directory / path", 'o'}};

  int count = sizeof(commands) / sizeof(commands[0]);
  char lower[64];
  
  printf("USAGE: ./%s <license_name> [OPTIONS]\n\n", string_to_lower(NAME, lower));
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
  printf("%s v%s\n\n%s\n\nRepository URL: %s\n", NAME, VERSION, DESCRIPTION,
         GITHUB_URL);
}

void print_licenses(const struct License *licenseList, size_t licenseCount, int is_help) {
    if(!is_help) {
        printf("Available licenses (%lu):\n", licenseCount);
    }
    for(size_t i = 0; i < licenseCount; i++) {
        printf("\t%-10s: %-s\n", licenseList[i].license_name, licenseList[i].license_description);
    }
}