#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int ch;
    //extern char *optarg;
    extern int optind;

    while ( (ch=getopt(argc, argv, ":abc:d")) != -1) {
        printf("Current Option Number: %d\n", optind);
        printf("argc: %d\n", argc);
        switch(ch) {
            case 'a':
                printf("Option : a\n");
                break;
            case 'b':
                printf("Option : b\n");
                break;
            case 'c':
                printf("Option : c\n");
                //printf("Option arg : optopt");
                break;
            case 'd':
                printf("Option : d\n");
                break;
            case ':':
                if(optopt == 'a') printf("aaa\n");
                if(optopt == 'b') printf("bbb\n");
                if(optopt == 'c') printf("ccc\n");
                if(optopt == 'd') printf("ddd\n");
                break;
            case '?':
                printf("Option Error !! No Option : %c\n", optopt);
                break;
        }
    }
    
    return 0;
}