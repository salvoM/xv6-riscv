#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    fprintf(2, "usage: trace mask...\n");
    exit(1);
  }
  trace(atoi(argv[1]));
  exec(argv[2], &argv[2]);
  printf("MHhhhhhh.......");
  exit(0);
}
