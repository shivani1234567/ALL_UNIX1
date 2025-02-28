#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
    int a=fork();
    if(a==-1)
    {
        printf("Unable to fork\n");
    }
    else if(a==0)
    {
        sleep(5);
        printf("It begins with 1\n");
    }
    else
    {
        int w;
        printf("What is the value of 3*5?\n");
        scanf("%d",&w);
        if(w==15)
        {
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect!\n");
        }
    }
    return 0;
}