#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Step 1: Open output.txt for writing
    int file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file < 0) {
        perror("open");
        exit(1);
    }

    // Step 2: Redirect stdout (fd = 1) to the file
    dup2(file, 1);  // Now printf and write(1,...) will go to output.txt

    // Step 3: Duplicate stdout (which now goes to output.txt)
    int fd = dup(1);  // fd now also writes to output.txt

    // Step 4: Write using both fds
    write(1, "hello", 5);   // write through stdout
    write(fd, "world", 5);  // write through duplicate

    // Optional: add newline
    write(1, "\n", 1);

    close(file);
    close(fd);
    return 0;
}

