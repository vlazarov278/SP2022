#include <stdio.h>
#include <fcntl.h>

int second() {
    // Open file for writing, close stdout, dup file, write to stdout
    int file = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(file == -1) {
        printf("Error opening file");
        return -1;
    }
    close(1);
    // Will put it in the lowest available file descriptor which turns out to be 1
    int dup_file = dup(file);
    if(dup_file == -1) {
        printf("Error duplicating file");
        return -1;
    }
    write(1, "Hello World", 11);
    close(file);
    close(dup_file);
    return 0;
}