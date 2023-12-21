#include <stdio.h>
#include<unistd.h>
#include <pthread.h>
void *computation(){
for(int i=0;i<10;i++){
printf("%d",i);
sleep(1);
}
}
int main(){
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,computation,NULL);
pthread_create(&thread2,NULL,computation,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
return 0;
}

