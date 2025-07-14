#include <stdio.h>
#include <stdlib.h>

int main(){

    int *a = malloc(4);
int *b = malloc(4);
printf("%p < %p?  %s\n", a, b, (a < b ? "YES" : "NO"));  // YES means heap grew upward

}