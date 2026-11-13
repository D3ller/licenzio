#ifndef LICENZIO_COMMAND_H
#define LICENZIO_COMMAND_H

#include "licenzio.h"
#include <stdio.h>

void generate_help(const struct License *licenseList, size_t licenseCount);

void print_licenses(const struct License *licenseList, size_t licenseCount, int is_help);

void read_version(void);

#endif
