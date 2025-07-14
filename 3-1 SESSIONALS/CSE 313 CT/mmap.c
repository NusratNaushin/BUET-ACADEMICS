#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *filename = "example.txt";

    // Open the file for read/write
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get file size
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }
    size_t filesize = st.st_size;

    // Map the file into memory
    char *map = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    printf("Original file content:\n%.*s\n", (int)filesize, map);

    // Modify the memory (first few bytes)
    strcpy(map, "HELLO");

    // Sync the memory back to the file
    if (msync(map, filesize, MS_SYNC) == -1) {
        perror("msync");
    }

    // Unmap and close
    munmap(map, filesize);
    close(fd);

    printf("File modified successfully.\n");
    return 0;
}
