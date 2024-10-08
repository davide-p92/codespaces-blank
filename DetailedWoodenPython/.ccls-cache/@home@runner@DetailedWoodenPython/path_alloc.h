#ifndef _PATH_ALLOC_H_
#define _PATH_ALLOC_H_ 1

#include "apue.h"

#define PATH_MAX_GUESS 1024

char *path_alloc(size_t *size);
#endif /* _PATH_ALLOC_H_ */