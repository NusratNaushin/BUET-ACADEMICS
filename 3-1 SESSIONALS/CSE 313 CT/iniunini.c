#include <stdio.h>
#include <stdlib.h>

int a_unin_global;

int main(){
    int a_unini_local;
    printf("uninitialized global variable: %p\n", (void *)&a_unin_global);
    printf("uninitialized local variable: %p\n", (void *)&a_unini_local);
    printf("a_unin: %d\n", a_unin_global);
    printf("a_ini: %d\n", a_unini_local);
}