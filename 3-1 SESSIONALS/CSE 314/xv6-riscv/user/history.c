#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define sycallnumbers 24

int main(int argc, char *argv[])
{

    int id;


    struct syscall_stat st;


    if (argc == 1){
        for (int i = 0; i < sycallnumbers ; i++)
        {
            /* code */

            if (history(i, &st) == 0 )
            {
                 printf("syscall %s,# : %d ,time : %d \n", st.syscall_name,st.count,st.accum_time);

            }
            
        }
        
    }
    else{
            id = atoi(argv[1]);

            history(id, &st);
            printf("syscall %s,# : %d ,time : %d ", st.syscall_name,st.count,st.accum_time);
    }

    return 0;
}