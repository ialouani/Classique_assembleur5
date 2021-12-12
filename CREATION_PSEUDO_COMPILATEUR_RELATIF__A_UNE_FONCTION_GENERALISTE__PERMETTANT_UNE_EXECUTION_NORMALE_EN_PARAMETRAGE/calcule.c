#include<stdio.h>
#include<stdlib.h>

int evalExpr(int a, int b);

int main(int argc, char* argv[]){
  int a=atoi(argv[1]);int b=atoi(argv[2]);
  printf("%d\n",evalExpr(a,b));
  return 0;
}
