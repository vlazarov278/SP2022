#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

// Receive command line arguments
int main(int argc, char *argv[]) {
    // Iterate command line arguments
    for(int i = 1; i < argc; i++) {
        // Open file for reading
        int file = open(argv[i], O_RDONLY);
        if(file == -1) {
            printf("Error opening file");
            return -1;
        }
        struct stat file_stat;
        if(fstat(file, &file_stat) == -1) {
            printf("Error getting file stat");
            return -1;
        }
        // Print file_stat
        printf("File: %s\n", argv[i]);
        printf("Size: %ld bytes\n", file_stat.st_size);
        printf("Permissions: %o\n", file_stat.st_mode);
        printf("Last status change: %ld\n", file_stat.st_ctime);
        printf("Last file access: %ld\n", file_stat.st_atime);
        printf("Last file modification: %ld\n", file_stat.st_mtime);
        // Close file
        close(file);
    }

}