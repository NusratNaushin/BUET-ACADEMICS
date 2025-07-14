#include <stdio.h>
#include <stdlib.h>

// Global variable with initial value → .data
int global_data = 42;

// Global variable without initial value → .bss
int global_bss;

// Function to show code segment
void dummy_func() {}

int main() {
    // Local variable → stack
    int local_var = 10;

    // Dynamic allocation → heap
    int *heap_var = (int *)malloc(sizeof(int));
    *heap_var = 99;

    printf("Code Segment (dummy_func):      %p\n", (void *)dummy_func);
    printf("Code Segment (main):            %p\n", (void *)main);

    printf("Data Segment (global_data):     %p\n", (void *)&global_data);
    printf("BSS Segment (global_bss):       %p\n", (void *)&global_bss);

    printf("Heap Segment (malloc'd var):    %p\n", (void *)heap_var);

    printf("Stack Segment (local_var):      %p\n", (void *)&local_var);

    free(heap_var);
    return 0;
}
