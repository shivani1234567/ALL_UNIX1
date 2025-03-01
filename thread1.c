#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* func1()
{
    printf("Hi I am inside function \n");
    sleep(3);
    printf("End of func1\n");
}
int main(int argc,char* argv[])
{
    pthread_t a,b;
    pthread_create(&a,NULL,&func1,NULL);
    pthread_create(&b,NULL,&func1,NULL);
    pthread_join(a,NULL);
    pthread_join(b,NULL);
    printf("Came back to parent\n");
    return 0;

}