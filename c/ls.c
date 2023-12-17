#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    
    struct dirent *dir;
    int c;

    DIR *dp = opendir(".");
    if (dp == NULL) {
        return -1;
    }

    if (argc == 1) {
        while (dir = readdir(dp)) {
            if (dir->d_name[0] == '.')
                continue;
            else
                printf("%s  ", dir->d_name);
        }
    closedir(dp);
    }
    else {
        while( (c = getopt(argc, argv, ":abc:d")) != -1) {
            switch(c) {
                case 'a':
                    while (dir = readdir(dp)) {
                        printf("%s  ", dir->d_name);
                    }
                    break;
                case ':':
                    break;
                case '?':
                    printf("Does not support %c\n", optopt);
            }
            closedir(dp);
        }
    }
    printf("\n");

    return 0;
}
