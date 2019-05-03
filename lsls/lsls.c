#include <dirent.h>
#include <stdio.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv) {

  char *path;

  // Parse command line
  if (argc == 1) {
    path = "./";
  } else if (argc == 2) {
    path = argv[1];
  } else {
    printf("Usage: lsls [directory]");
  }

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}