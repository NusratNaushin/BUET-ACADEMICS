#include <stdio.h>

#include <stdlib.h>     // for exit()
#include <unistd.h>     // for fork(), write()
#include <sys/wait.h>   

int main(){


    if(fork()==0){
    write(1,"hello",6);
    exit(0);
    }
    else{
    
    wait(0);
    write(1,"world",6);
   
    }
    

}
