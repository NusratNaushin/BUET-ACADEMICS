#include <stdio.h>
#include <stdlib.h>


int global_initialized = 42;
int global_uninitialized;

void func(){};

int main(){

    printf("location of code  : %p\n", (void *) main);

    printf("func address : %p\n",func);

     printf("Address of initialized global : %p\n", (void *)&global_initialized);
    printf("Address of uninitialized global (BSS): %p\n", (void *)&global_uninitialized);
    return 0;
}