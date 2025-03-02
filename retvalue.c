#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* fun()
{
    int a=1;
    int *p =malloc(sizeof(int));
    *p=a;
    return (void*)p;
}
int main()
{
    pthread_t p[4];
    void* result;
    for(int i=0;i<4;i++)
    {
        pthread_create(p+i,NULL,&fun,NULL);
    }
    for(int i=0;i<4;i++)
    {
        pthread_join(p[i],(void**)&result);
        printf("The value of a is %d\n",*((int*)result));
    }
    return 0;
}