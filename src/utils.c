#include "../includes/utils.h"

#include <stdio.h>
#include <ctype.h>

char *string_to_lower(const char *src, char *dest) {
  size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = tolower((unsigned char)src[i]);
    i++;
  }
  dest[i] = '\0';
  return dest;
}