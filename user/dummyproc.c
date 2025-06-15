#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        settickets(-1);
    }

    else
    {
        int tickets = atoi(argv[1]);

        if (tickets < 1)
        {
            printf("Invalid number of tickets. Setting to default value.\n");
            settickets(-1);
        }
        else
        {
            if (settickets(tickets) < 0)
            {
                printf("Error setting tickets.\n");
            }
            else
            {
                printf("Tickets set to %d.\n", tickets);
            }

            // int pid = fork();
            int pid;
            for (int i = 0; i < 4; i++)
            {
                pid = fork();

                // break;

                if (pid == 0)
                {
                    settickets(tickets);
                    int counter = 0;
                    while (1)
                    {
                        for (volatile int i = 0; i < 100000000; i++)
                        {
                            counter++;
                          //  printf("counter : %d\n", counter);
                            if (counter % 10 == 0)
                            {
                                sleep(5);
                            }
                        }
                    }
                    exit(0);
                }

                else if (pid < 0)
                {
                    printf("fork failed\n");
                    break;
                }
            }

            for (volatile int i = 0; i < 100000000; i++)
                ;
        }
    }
    return 0;
}