#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t lock;
void* fun(void* arg)
{
  int *p=malloc(sizeof(int));
  *p=*((int*)arg);
  
  pthread_mutex_lock(&lock);
  pthread_mutex_lock(&lock);
    *p=*p * 2;
  pthread_mutex_unlock(&lock);
  return (void*)p;
}
int main()
{
    pthread_t t1;
    pthread_mutex_init(&lock,NULL);
    int value;
    printf("Enter value\n");
    scanf("%d",&value);
    pthread_create(&t1,NULL,&fun,(void*)&value);
    
    void *m=NULL;
    pthread_join(t1,(void**)&m);
    
    printf("value of %d*2 is %d\n",value,*((int*)m));
    pthread_mutex_destroy(&lock);
    return 0;
}