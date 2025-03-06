#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
pthread_mutex_t safe;
pthread_mutex_t loc;
int mail=0,mail1=0;
void* func(void *ele)
{
   int p=*((int*)ele);
    if(p%2==0){
    pthread_mutex_lock(&loc);
    mail+=50;
    
    printf("Value of mail by threadid %lu is %d and value is %d\n", pthread_self(),mail,p);
    pthread_mutex_unlock(&loc);
    }
    else
    {
        pthread_mutex_lock(&safe);
        mail1+=10;
        
        printf("Value of mail1 by threadid %lu is %d and value is %d\n", pthread_self(),mail1,p);
        pthread_mutex_unlock(&safe);
    }
    
   

    return NULL;
}
int main(int argc,char*argv[])
{
    int value;
    pthread_mutex_init(&safe,NULL);
    pthread_mutex_init(&loc,NULL);
    pthread_t t[10];
    for(int i=0;i<10;i++){
     value =rand();
    pthread_create(t+i,NULL,&func,&value);
    }
    for(int i=0;i<10;i++){
    pthread_join(t[i],NULL);
    }

    pthread_mutex_destroy(&safe);
    return 0;
}