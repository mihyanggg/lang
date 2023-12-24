#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    int fd, i;
    char* name;

    if (argc == 1) {
        printf("touch: missing file operand\n");
        return 0;
    }

    for (i=1; i<argc; i++) {
        if (0 < (fd = creat(argv[i], 0664))) {
            close(fd);
        }
    }

    return 0;
}
