#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "pstat.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  if(n < 0)
    n = 0;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
uint64
sys_history(){

  int id;
  uint64 ust;
  argint(0,&id);
  argaddr(1,&ust);
  return history(id,ust);
}
uint64
sys_settickets(void){
  //printf("testing setticket");

  int tickets;

  argint(0, &tickets);

  return settickets(tickets);

  return 0;
}

uint64
sys_getpinfo(void){
  //printf("testing getpinfo");

  uint64 addr;
  struct pstat process_charactersitics;

  argaddr(0, &addr);




  getpinfo(&process_charactersitics);



  if(copyout(myproc()->pagetable, addr, (char *)&process_charactersitics, sizeof(struct pstat)) < 0){
    return -1;
  }

  return 0;
}

uint64
sys_setSeed(void){


  int seeds;

  argint(0, &seeds);

  return setSeed(seeds);

  return 0;
}

uint64
sys_getRandomNumber(void){

  uint64 addr;
  int n;

  argaddr(0, &addr);
  argint(1,&n);
  int random_numbers[15];
    
    // Call the main implementation in proc.c
  getRandomNumber(random_numbers, n);

  if(copyout(myproc()->pagetable, addr, (char *)&random_numbers, n*sizeof(int)) < 0){
    return -1;
  }
    return 0;
}