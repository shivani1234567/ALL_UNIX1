#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sem;

int mail=0;
void* func()
{
   sem_wait(&sem);
    sleep(2);
     mail++;
     printf("Value of mail is %d\n",mail);
    sem_post(&sem);
}
int main()
{
    pthread_t th[10];
    sem_init((&sem),0,1);
    for(int i=0;i<10;i++)
    {
       pthread_create(th+i,NULL,&func,NULL);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(th[i],NULL);
    }
    return 0;
}