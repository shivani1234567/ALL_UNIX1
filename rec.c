#include<pthread.h>
#include<stdio.h>
pthread_mutex_t l;
int mail=0;
void* fun()
{
  pthread_mutex_lock(&l);
  pthread_mutex_lock(&l);
   mail++;
   printf("Value of mail is %d\n",mail);
  pthread_mutex_unlock(&l);
}
int main()
{
    pthread_mutexattr_t ml;
    pthread_mutexattr_init(&ml);
    pthread_mutexattr_settype(&ml,PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_t t1;
    pthread_mutex_init(&l,&ml);
    pthread_create(&t1,NULL,&fun,NULL);
    pthread_join(t1,NULL);
    return 0;
}