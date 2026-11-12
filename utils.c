#include "licenzio.h"

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_to_lower(const char *src, char *dest) {
  size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = tolower((unsigned char)src[i]);
    i++;
  }
  dest[i] = '\0';
  return dest;
}

const struct License *find_license(const struct License licenses[], size_t count, const char* license_name) { 

    size_t i;
    for(i = 0; i < count; i++) {
        if(strcmp(license_name, licenses[i].license_name) == 0) {
            return &licenses[i];
        }
    }
    
    return NULL;
}

struct License *get_available_license(int *c) {

  size_t i, count, allow_bytes;
  struct License *available_licenses;

  struct License licenses[] = {
      {"apache", "Apache License (Version 2.0)"},
      {"artistic", "The Artistic License 2.0"},
      {"bsd2", "BSD 2-Clause License"},
      {"bsd3", "BSD 3-Clause License"},
      {"cc", "Creative Commons - Attribution 4.0 International"},
      {"eupl", "European Union Public License 1.2"},
      {"agpl", "GNU Affero General Public License v3.0"},
      {"mit", "MIT License"},
      {"mozilla", "Mozilla Public License 2.0"},
      {"zlib", "zlib License"},
      {"lgpl", "GNU Lesser General Public License v3.0"},
      {"gpl", "GNU General Public License v3.0"}};

  count = sizeof(licenses) / sizeof(licenses[0]);
  *c = count;
  allow_bytes = count * sizeof(struct License);

  available_licenses = malloc(allow_bytes);
  if (available_licenses == NULL)
    return NULL;

  for (i = 0; i < count; i++) {
    available_licenses[i] = licenses[i];
  }

  return available_licenses;
}
