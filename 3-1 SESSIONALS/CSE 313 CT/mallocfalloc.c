#include <stdio.h>
#include <stdlib.h>

int main(){

    float *x1 = malloc(10*sizeof(float));
    printf("%ld\n",sizeof(x1));

    double x2[10];
    printf("%ld\n",sizeof(x2));
    printf("%ld\n",sizeof(double));
    free(x1);
    return 0;

}