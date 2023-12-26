#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>


void cmp_argv(struct dirent *dir, char* argv[], char* path) {
    if (strcmp(dir->d_name, argv[2])) {
        return;
    } else {
        printf("%s/%s\n", path, dir->d_name);
    }
    return;
}

int recursion_dir(char* path, char* argv[]) {
    
    struct dirent *dir;
    char *next_path;
    int path_len;
    
    DIR *dp = opendir(path);
    if (dp == NULL) {
        return -1;
    }

    while ((dir = readdir(dp)) != NULL) {
        if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") || !strcmp(dir->d_name, ".vscode")){
            continue;
        }

        //printf("%d : %s : %s\n", dir->d_type, path, dir->d_name);
        //printf("%s/%s \n", path,dir->d_name);

        if (dir->d_type == 4) {
            path_len = strlen(path) + strlen(dir->d_name) + 2;
            next_path = malloc(path_len);

            if (next_path == NULL) {
                perror("malloc");
                break;
            }

            snprintf(next_path, path_len, "%s/%s", path, dir->d_name);
            recursion_dir(next_path, argv);
            free(next_path);
        }
        cmp_argv(dir, argv, path);
    }
    closedir(dp);
    return 0;
}


int main(int argc, char* argv[]) {

    struct dirent *dir;
    int c, name;
    
    char name_str[6] = "-name";
    name = strcmp(argv[1],name_str);
    
    if (name == 0) {
        //printf("%s\n", argv[1]);
        if(c = recursion_dir(".", argv)) {
            printf("readdir() error \n");
        }
    } else {
        printf("Usage: %s -name \n", argv[0]);
    }

    return 0;
}
