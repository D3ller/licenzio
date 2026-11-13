#ifndef LICENZIO_LICENSE_H
#define LICENZIO_LICENSE_H

#include <stdio.h>
#include "licenzio.h"

const struct License *get_available_license(size_t *c);

const struct License *find_license(const struct License licenses[],
                                   size_t count, const char *license_name);

int createLicenseFile(const struct License *license);


#endif