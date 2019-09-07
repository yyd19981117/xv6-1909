#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

extern struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;

int sys_getpinfo(void)
{
  struct pstat* pstatA;

  if(argptr(1, (char**)&pstatA, sizeof(struct pstat)) < 0)
  {
  	 cprintf("didn't parse arg");
  	return -1;
  }

  //struct ptable *pt = ptable;  

  acquire(&ptable.lock);
  
  struct proc* p;
  //make array of pstat's
  //struct pstat* pstatA = (struct pstat*) malloc((uint)(NPROC * sizeof(struct pstat)));
  

  int i = 0;
  //printf("PID \t Stride \t tickets \t pass \t n_schedule \t name \n ");
  for/*(i = 0; i < NPROC; i++ )
     */(p = ptable.proc; p < &ptable.proc[NPROC]; p++)
    { 
    
      p = &ptable.proc[i];
	 
      (pstatA + i)->pid = p->pid;
      (pstatA + i)->stride = p->stride;
      strncpy((pstatA+i)->name, p->name, 16);//(pstatA + i)->name = p->name;
      (pstatA + i)->tickets = p->tickets;
      (pstatA + i)->pass = p->pass;
      (pstatA + i)->n_schedule = p->n_schedule;
      if((p->state) != UNUSED  )
	      (pstatA + i)->inuse = 1;
      
		 //print out the stats to stdout
	  if((p->state) != UNUSED)
		 cprintf("PID %d; \t stride %d \t tickets %d; \t pass %d; \t n_schedule %d; \t name %s \n", p->pid, p->stride, p->tickets, p->pass, p->n_schedule, p->name );
      i++; // Increment index
    }
  release(&ptable.lock);
  return 0;
  //free(pstatA);
}

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_cps(void)
{
  return cps();
}

int sys_getstride(void)
{
  return getstride();
}

int 
sys_chpr(void)
{
  int pid, pr;
  if(argint(0, &pid) < 0)
  return -1;
  if(argint(1, &pr) <0)
  return -1;

  return chpr(pid, pr);
}

int 
sys_clone(void)
{
  int func_add;
  int arg;
  int stack_add;

  if (argint(0, &func_add) < 0)
     return -1;
  if (argint(1, &arg) < 0)
     return -1;
  if (argint(2, &stack_add) < 0)
     return -1;
 
  return clone((void *)func_add, (void *)arg, (void *)stack_add);
  
}

int 
sys_join(void)
{
  int stack_add;

  if (argint(0, &stack_add) < 0)
     return -1;

  return join((void **)stack_add);
}

int
sys_sem_init(void)
{
  int num, max;
  if(argint(0, &num) < 0)
    return -1;
  if(argint(1, &max) < 0)
    return -1;
  return sem_init(num, max);
}

int
sys_sem_destroy(void)
{
  int num;
  if(argint(0, &num) < 0)
    return -1;
  return sem_destroy(num);
}

int
sys_sem_wait(void)
{
  int num, count;
  if(argint(0, &num) < 0)
    return -1;
  if(argint(1, &count) < 0)
    return -1;
  return sem_wait(num, count);
}

int
sys_sem_signal(void)
{
  int num, count;
  if(argint(0, &num) < 0)
    return -1;
  if(argint(1, &count) < 0)
    return -1;
  return sem_signal(num, count);
}
