#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int num)
{
 write(STDOUT_FILENO,"\nI won't die\n",14);
}
void seghandler(int num)
{
write(STDOUT_FILENO,"Seg Fault!\n",10);
}
int main()
{
int *p = NULL;
signal(SIGINT, handler);
signal(SIGTERM, handler);
signal(SIGKILL, handler);
signal(SIGSEGV, seghandler);
*p = 45; //Should be Segmentation Fault
while(1)
{
printf("Wasting your cycles. %d\n",getpid());
sleep(1);
}
}
