#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>


char *search_dir(const char *filename, const char *dname) {
  int found = 0;
  // vector<string> dirs;
  struct stat s;
  struct dirent *de;
  DIR *directry;
  char *subdirname;
  printf("In search_dir\n");

  // string subdirname;
  subdirname = (char *)malloc(sizeof(char) * 256);
  strcpy(subdirname, dname);
  char *rex;
  rex = (char *)malloc(sizeof(char) * 200);
  printf("DNAME=%s\n", dname);
  if (lstat(dname, &s) >= 0) {
    printf("stat == 0\n");
    if ((s.st_mode & S_IFMT) == S_IFDIR) {
      directry = opendir(dname);
      while ((de = readdir(directry)) != NULL) {
        if(strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) break;
        sprintf(subdirname, "%s/%s", subdirname, de->d_name);
        printf("Name of dir: %s\n", de->d_name);
        printf("Before search_dir subdirname is %s\n", subdirname);
        rex = search_dir(filename, subdirname);
        printf("REX=%s\n", rex);
        sprintf(subdirname, "%s%s", subdirname, rex);
        printf("After search_dir subdirname is %s\n", subdirname);
        // recursive call

        if (chdir(subdirname) < 0) {
          printf("error chdir to %s\n", subdirname);
          return NULL;
        }
      }
      closedir(directry);
    }
  } else { printf("Problem lstat: %s\n", strerror(errno)); }
  free(subdirname);
  return rex;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("usage. %s <file> <dir>\n", argv[0]);
    return -1;
  }
  char *fname, *dirname;
  fname = (char *)malloc(50);
  dirname = (char *)malloc(100);
  strcpy(fname, argv[1]);
  strcpy(dirname, argv[2]);
  if (search_dir(fname, dirname) == -1) {
    printf("Error search_dir for dir %s\n", fname);
  }
  // free
  free(fname);
  free(dirname);
  return 0;
}
