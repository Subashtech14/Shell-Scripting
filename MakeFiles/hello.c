#include<stdio.h>
#include"header.h"
#include<unistd.h>
void hello(){
printf("I am in hello.c \n");
printf("PID of hello.c %d\n",getpid());
}
