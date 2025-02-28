#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void h(int sig)
{

    printf("INPUT NUMBER:\n");
}
int main(int argc,char*argv[])
{
    struct sigaction sa;
    
    sa.sa_handler=&h;  
    sa.sa_flags =SA_RESTART;
    sigaction(SIGCONT,&sa,NULL);
    /*signal(SIGTSTP,&h);*/
    int x;
    printf("Enter value of x");
    scanf("%d",&x);
    printf("Value of 5*%d = %d",x,5*x);
    return 0;
}