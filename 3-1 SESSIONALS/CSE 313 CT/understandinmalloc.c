#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(1);
    printf("Requested: 1 byte\n");
    printf("Usable: %zu bytes\n", malloc_usable_size(ptr));
    free(ptr);
}
