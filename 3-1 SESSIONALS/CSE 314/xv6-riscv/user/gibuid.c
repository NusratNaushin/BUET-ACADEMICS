#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main()
{

   int uid = getuid();
   printf("hello world , uid = %d\n", uid);
   return 0;
}
