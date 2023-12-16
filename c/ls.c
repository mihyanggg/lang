#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    
    struct dirent *dir;

    DIR *dp = opendir(".");
    if (dp == NULL) {
        return -1;
    }
    
    while (dir = readdir(dp)) {
        if (argc == 1) {
            if (dir->d_name[0] == '.')
                continue;
            else
                printf("%s  ", dir->d_name);
        }
        else if (strchr(argv[1], 'a')) {
            printf("%s  ", dir->d_name);
        }
    }

    printf("\n");

    closedir(dp);
    
    return 0;
}
