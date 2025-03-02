#include<stdio.h>
#include<pthread.h>
int mail=0;
void* fun()
{
    for(int i=0;i<1000000;i++)
    mail++;
}
int main(int argc,char*argv[])
{
  pthread_t a,b;
  pthread_create(&a,NULL,&fun,NULL);
  pthread_create(&b,NULL,&fun,NULL); 
  pthread_join(a,NULL);
  pthread_join(b,NULL); 
  printf("Value of mail is %d\n",mail);
  return 0;
}