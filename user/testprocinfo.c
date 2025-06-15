#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{

   struct pstat p;
   getpinfo(&p);

   printf("PID    |    In Use    |    inQ    |    Original Tickets    |    Current Tickets    |    Time Slices\n");

   for (int i = 0 ; i < NPROC ; i++) {
        if(p.pid[i] != 0){
            printf("%d      |    %d         |    %d      |    %d                   |    %d                  |    %d\n",
                   p.pid[i],
                   p.inuse[i],
                   p.inQ[i] + 1,
                   p.tickets_original[i],
                   p.tickets_current[i],
                   p.time_slices[i]);
        }
   }


}