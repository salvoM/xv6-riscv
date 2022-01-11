#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "syscall.h"
#include "defs.h"
// #include "proc.c"
#define N 170
// #include <stdio.h>
void forktest(void);
int main (void){
	int i  = 0;
	int pid;
	forktest();
	
}
void
forktest(void)
{
  int n, pid, r;

  printf("fork test\n");
  printf("Nextpid(): %d\n", get_nextpid());

  for(n=0; n<N; n++){
    pid = fork();
    if(pid < 0)
      break;
    if(pid == 0){
	//   //fprintf(1, "My pid: %d, my parent pid: %d", getpid(), getppid());
      // scanf("%d", &r);
      printf("HI");
	  exit(0);
	}
  }

  if(n == N){
    //fprintf(1,"fork claimed to work N times!\n");
    exit(1);
  }

  for(; n > 0; n--){
    if(wait(0) < 0){
      //fprintf(1,"wait stopped early\n");
      exit(1);
    }
  }

  if(wait(0) != -1){
    //fprintf(1,"wait got too many\n");
    exit(1);
  }

  //fprintf(1,"fork test OK\n");
}
