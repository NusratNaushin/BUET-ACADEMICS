#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define sycallnumbers 25

int main(int argc, char *argv[])
{

    int id;


    struct syscall_stat st;


    if (argc == 1){
        for (int i = 1; i < sycallnumbers ; i++)
        {
            /* code */

            if (history(i, &st) == 0 )
            {
                 printf("%d: syscall %s,# : %d ,time : %d \n",i, st.syscall_name,st.count,st.accum_time);

            }

        }

    }
    else{
            id = atoi(argv[1]);

            history(id, &st);
            printf("%d: syscall %s,# : %d ,time : %d ",id,st.syscall_name,st.count,st.accum_time);
    }

    return 0;
}