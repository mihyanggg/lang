#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
    struct dirent *entry;

    // 현재 디렉터리 열기
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("현재 디렉터리 열기 실패");
        return 1;
    }

    // 디렉터리 내의 파일 순회
    while ((entry = readdir(dir))) {
        char *filename = entry->d_name;

        // 파일명이 ".c" 확장자이거나 파일명이 "clean"인 파일은 삭제하지 않음
        if (strstr(filename, ".c") == NULL && strcmp(filename, "clean") != 0) {
            // 파일 삭제
            if (remove(filename) == 0) {
                printf("삭제된 파일: %s\n", filename);
            } else {
                perror("파일 삭제 실패");
            }
        }
    }

    // 디렉터리 닫기
    closedir(dir);

    return 0;
}

