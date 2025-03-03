#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t shia;
void* fun()
{
  if( pthread_mutex_trylock(&shia)==0)
  {
   printf("Lock acquired\n");
   sleep(1);
   pthread_mutex_unlock(&shia);
  }
  else
  {
    printf("Didn't get lock\n");
  }
   return NULL; 
}
int main(int argc ,char* argv[])
{
  pthread_mutex_init(&shia,NULL);
  pthread_t a[4];
  for(int i=0;i<4;i++)
  {
    pthread_create(a+i,NULL,&fun,NULL);
  }   
  for(int i=0;i<4;i++)
  {
    pthread_join(a[i],NULL);
  }
  return 0;
}