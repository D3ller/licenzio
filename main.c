#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/command.h"
#include "includes/license.h"
#include "includes/licenzio.h"

void print_err(void);

int main(int argsc, char *argv[]) {

  if (argsc <= 1) {
    print_err();
    return 1;
  }

  char *firstArgs = argv[1];
  char *secondArgs = argv[2];

  size_t licenseCount;
  const struct License *licenseList = get_available_license(&licenseCount);

  if (strcmp(firstArgs, "--help") == 0 || strcmp(firstArgs, "-h") == 0) {
    generate_help(licenseList, licenseCount);
  } else if (strcmp(firstArgs, "-v") == 0 ||
             strcmp(firstArgs, "--version") == 0) {
    read_version();
  } else if (strcmp(firstArgs, "--license") == 0 ||
             strcmp(firstArgs, "-l") == 0) {
    print_licenses(licenseList, licenseCount, 0);
  } else {
    const struct License *found =
        find_license(licenseList, licenseCount, argv[1]);
    if (found == NULL) {
      fprintf(stderr,
              "The provided string doesn't match any supported license.\nUse "
              "'-h' or '--help' for usage information.\n");
      return (1);
    } else {
      if (argsc >= 3) {
        if (strcmp(secondArgs, "-o") == 0 && argsc == 4) {
          if(createLicenseFileAt(found, argv[3]) != 0) return (1);
        } else {
          print_err();
          return (1);
        }
      } else {
        if (createLicenseFile(found, "LICENSE") != 0)
          return (1);
      }
    }
  }

  return 0;
}

void print_err(void) {
  fprintf(stderr,
          "Wrong arguments. Use '-h' or '--help' for usage information.\n");
}
