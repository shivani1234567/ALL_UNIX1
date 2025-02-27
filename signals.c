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
       usleep(1000000);
      }
    }
   else 
    {
        sleep(2);
        kill(i,SIGSTOP);/*here i needs pid of the process it needs o go and what  to do is second one*/
        sleep(4);
        kill(i,SIGCONT);
        sleep(2);
        kill(i,SIGKILL);
        wait(NULL);
        printf("Hi from parent\n");
    }
}