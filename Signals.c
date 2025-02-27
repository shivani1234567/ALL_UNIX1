#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
int main(int argc,char*argv[])
{
    int i = fork();
    if(i ==-1)
    {
        printf("Unable to fork \n");
    }
    else if(i==0)
    {
      while(1){
       printf("I am inside child\n");
       usleep(2000000);
      }
    }
   else
    {
        sleep(8);
        kill(i,SIGKILL);/*here i needs pid of the process it needs o go and what  to do is second one*/
        wait(NULL);
        printf("Hi from parent\n");
    }
}
