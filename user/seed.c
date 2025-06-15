#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int main(int argc, char *argv[]){

    int seeds;




    if (argc < 2){
        printf("Msut provide one \n");


    }
    else{
            seeds = atoi(argv[1]);
            setSeed(seeds);

            printf("The seed has been set to %d",seeds);
           
    }

  //  printf("seed.c user program added \n");




}