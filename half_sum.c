#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
void* fun1(void*(arg))
{
   int *p =(int*) arg;
    int sum=0;
    for(int i=0;i<5;i++)
    {
      sum+=*(p+i);
    }


    int *p2=malloc(sizeof(int));
    *p2=sum;
    return (void*)p2;
    

}
void* fun2(void*(arg))
{
    
    
    int *p =(int*) arg;
    int sum=0;
    for(int i=5;i<10;i++)
    {
      sum=sum+*(p+i);
    }
    
    
    int *p1=malloc(sizeof(int));
    *p1=sum;
    
    return (void*)p1;

}
int main()
{
    pthread_t t1,t2;
    void* res1=NULL;
    void* res2=NULL;
    int a[10] ={1,2,3,4,5,6,7,8,9,10};
    pthread_create(&t1,NULL,&fun1,a);
    pthread_create(&t2,NULL,&fun2,a);
    pthread_join(t1,(void**)&res1);
    pthread_join(t2,(void**)&res2);
    printf("Sum of first half is %d\n",*((int*)res1));
    printf("Sum of second half is %d\n",*((int*)res2));
    printf("sum of total is %d\n",*((int*)res1)+*((int*)res2));
    return 0;
}