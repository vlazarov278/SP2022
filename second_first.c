#include <stdio.h>
#include <fcntl.h>

int main() {
    int file = open("test.txt", O_RDONLY);
    if(file == -1) {
        printf("Error opening file");
        return -1;
    }
    int dup_file = dup(file);
    if(dup_file == -1) {
        printf("Error duplicating file");
        return -1;
    }
    char buf[100];
    int read_bytes = read(file, buf, 100);
    write(1, buf, read_bytes);
    read_bytes = read(dup_file, buf, 100);
    write(1, buf, read_bytes);
    close(file);
    read_bytes = read(dup_file, buf, 100);
    write(1, buf, read_bytes);
    close(dup_file);

    return 0;
}
