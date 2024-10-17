#include "./error.h"
#include "./path_alloc.h"
#include "apue.h"
#include <dirent.h>
#include <limits.h>

#define PATH_SEP '/'

/*function type called for each fname */
typedef int Myfunc(const char *, const struct stat *, int);

static void myfunc(const struct stat *);
static void myftw(char *);
static void dopath(void);

static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;
static char *fullpath;

int main(int argc, char *argv[]) {
  int ret;

  if (argc != 3)
    err_quit("usage: %s <starting-path> <file-to-search>\n", argv[0]);
  myftw(argv[1]); /* does it all*/

  ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock + ntot;
  if (ntot == 0)
    ntot = 1; /* avoid div by 0 */
  printf("regular files\t=%7ld, %5.2f %%\n", nreg, nreg * 100.0 / ntot);
  printf("directories\t=%7ld, %5.2f %%\n", ndir, (float)ndir * 100 / ntot);
  printf("block special\t=%7ld, %5.2f %%\n", nblk, (float)nblk * 100 / ntot);
  printf("char special\t=%7ld, %5.2f %%\n", nchr, (float)nchr * 100 / ntot);
  printf("FIFOS\t=%7ld, %5.2f %%\n", nfifo, (float)nfifo * 100 / ntot);
  printf("symbolic links\t=%7ld, %5.2f %%\n", nslink,
         (float)nslink * 100 / ntot);
  printf("sockets\t=%7ld, %5.2f %%\n", nsock, (float)nsock * 100 / ntot);
  exit(ret);
}

/*
 * Descend through the hierarchy start at "pathname"
 * func() is called for every file by caller.
 */
/*file other than dir*/
#define FTW_F 1
/*dir*/
#define FTW_D 2
/*dir that can't be read*/
#define FTW_DNR 3
/*file that can't be stat*/
#define FTW_NS 4

static char fname[2048];
static size_t pathlen;

static void myftw(char *pathname) {
  /*ret whatever func rets*/
  if(chdir(pathname) < 0)
    err_ret("chdir error for path %s", pathname);
  return dopath();
}
/*
 * Descend through the hierarchy, starting at "fullpath"
 * If "fullpath" is other than dir,
 * call func() and ret.
 * For dir, call ourself recursively for each name in dir.
 */
static void dopath(void) {
  /*ret whatever func rets*/
  struct stat statbuf;
  struct dirent *dirp;
  DIR *dp;
  int ret, n;

  if (lstat(".", &statbuf) < 0)
    return;
  
  myfunc(&statbuf); //Category: 

  if (!S_ISDIR(statbuf.st_mode)) /*not a dir*/
    return;
  /*It's a dir if we reach this.
   * Process each filename in dir
   */

  if ((dp = opendir(".")) == NULL)
    return;
  int fd_cwdir;
  char cwdir[PATH_MAX];
  while ((dirp = readdir(dp)) != NULL) {
    if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
      continue;
    //Check again lstat
    if(lstat(dirp->d_name, &statbuf) < 0) {
      err_ret("lstat error for %s", dirp->d_name);
      continue;
    }
    if(strcmp(dirp->d_name, fname) == 0) {
      printf("Found file %s in %s\n", fname, fullpath);
    }
    // Check if fullpath is directory
    if (S_ISDIR(statbuf.st_mode) && access(dirp->d_name, R_OK | X_OK)) {
      fd_cwdir = chdir(dirp->d_name);
      fullpath = path_alloc(&pathlen);	/*malloc(PATH+1)*/
      if(pathlen <= strlen(fullpath)) {
        pathlen = strlen(fullpath) * 2;
        if((fullpath = realloc(fullpath, pathlen)) == NULL)
          err_sys("realloc failed");
      }
      snprintf(fullpath, pathlen, "%s/%s/", cwdir, dirp->d_name);
      
      if(strlen(fullpath) > PATH_MAX) {
        err_ret("fullpath too long");
      }
      sprintf(fullpath, "%s", dirp->d_name);
      if (fd_cwdir < 0)
        err_ret("error chdir %s", dirp->d_name);
      if (getcwd(cwdir, PATH_MAX) == NULL)
        err_ret("error getcwd %s", dirp->d_name);
      strcpy(cwdir, dirp->d_name);
      /* recursive call, now we are in cwd as subdirectory */
      dopath();
    } else {
      myfunc(&statbuf);
    }
  }

  if (closedir(dp) < 0)
    err_ret("can't close dir %s", fullpath);
  if(chdir("..") < 0) {
    err_sys("chdir error");
  }
  return;
}

static void myfunc(const struct stat *statptr) {
  switch (statptr->st_mode & S_IFMT) {
    case S_IFREG:
      nreg++;
      break;
    case S_IFBLK:
      nblk++;
      break;
    case S_IFCHR:
      nchr++;
      break;
    case S_IFIFO:
      nfifo++;
      break;
    case S_IFLNK:
      nslink++;
      break;
    case S_IFSOCK:
      nsock++;
      break;
    case S_IFDIR:
      ndir++;
      break;
    }
}