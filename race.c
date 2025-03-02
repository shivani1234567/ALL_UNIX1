#include<stdio.h>
#include<pthread.h>
int mail=0;

pthread_mutex_t l; 
void* func()
{
    int a=2;
  pthread_mutex_lock(&l);
   for(int i=0;i<1000000;i++)
     mail++;
  pthread_mutex_unlock(&l);
  
  return((void*)&mail);
}
int main(int argc,char* argv[])
{
    pthread_mutex_init(&l,NULL);
    pthread_t a[4];

    for(int i=0;i<4;i++)
    {
          pthread_create(a+i,NULL,&func,NULL);
          printf("creating thread %d\n",i);
          
    }
    void *b=NULL;
    for(int i=0;i<4;i++)
    {
        pthread_join(a[i],&b);
          printf("Finished thread %d creation\n",i);
          printf("Value of mail is %d\n",*((int*)b));
    }
    printf("Total value of mail is %d\n",mail);

    return 0;
    
}