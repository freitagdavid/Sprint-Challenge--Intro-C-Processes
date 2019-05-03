#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv) {

  char path[4096];
  // Parse command line
  if (argc == 1) {
    strcpy(path, ".");
  } else if (argc == 2) {
    strcpy(path, argv[1]);
  } else {
    printf("Usage: lsls [directory]");
    exit(0);
  }
  char *trailing_slash = strchr(path, '/');
  if (trailing_slash == NULL) {
    int input_length = strlen(path);
    char *seperator = "/";
    strcat(path, seperator);
  }

  // Open directory

  DIR *dir = opendir(path);
  if (dir) {
    struct dirent *child = readdir(dir);
    struct stat file_stat;
    char full_file_path[4096];
    // char full_file_path[4096] = strcat(path, child->d_name);
    while ((child = readdir(dir)) != NULL) {
      strcpy(full_file_path, path);
      strcat(full_file_path, child->d_name);
      stat(full_file_path, &file_stat);
      printf("%10lld %s\n", file_stat.st_size, child->d_name);
    }
  } else if (ENOENT == errno) {
    printf("Err: Directory does not exist");
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}