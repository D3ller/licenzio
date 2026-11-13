#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "includes/licenzio.h"
#include "includes/command.h"
#include "includes/license.h"

int main(int argsc, char *argv[]) {

  if (argsc <= 1) {
    fprintf(stderr, "Wrong arguments. Use '-h' or '--help' for usage information.\n");
    return 1;
  }

  char *firstArgs = argv[1];

  size_t licenseCount;
  const struct License *licenseList = get_available_license(&licenseCount);


  if (strcmp(firstArgs, "--help") == 0 || strcmp(firstArgs, "-h") == 0) {
    generate_help(licenseList, licenseCount);
  } else if (strcmp(firstArgs, "-v") == 0 ||
             strcmp(firstArgs, "--version") == 0) {
    read_version();
  } else if (strcmp(firstArgs, "--license") == 0 || strcmp(firstArgs, "-l") == 0) {
    print_licenses(licenseList, licenseCount, 0);
  } else {
    const struct License *found =
        find_license(licenseList, licenseCount, argv[1]);
    if (found == NULL) {
      fprintf(stderr, "The provided string doesn't match any supported license.\nUse "
             "'-h' or '--help' for usage information.\n");
      return 1;
    } else {
        if(createLicenseFile(found) != 0) return 1;
    }
  }

  return 0;
}
