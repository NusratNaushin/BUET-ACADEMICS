#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int main(int argc, char *argv[]){

int n;




    if (argc < 2){
        printf("Msut provide one \n");


    }
    else{
            n = atoi(argv[1]);
            int arr[15];

            getRandomNumber(arr,n);

            printf("next random numbers are ");
            for(int i = 0 ; i < n ; i++){

            if(i==0){printf("[");}
            printf(" %d ",arr[i]);
            if(i==n-1){printf("]");}


            }
           
    }

   // printf("seed.c user program added \n");



}