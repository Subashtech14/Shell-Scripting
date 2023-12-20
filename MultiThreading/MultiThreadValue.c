#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *computation(void *add){
long *add_num = (long *)(add);

printf("%ld",*add_num);
}
int main()
{
pthread_t thread1;
pthread_t thread2;
long value1 = 1;
long value2 = 2;
pthread_create(&thread1, NULL, computation, (void*) &value1);
pthread_create(&thread2, NULL, computation, (void*) &value1);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
return 0;
}
