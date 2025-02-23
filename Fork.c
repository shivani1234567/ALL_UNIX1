#include<stdio.h>
int main(int argc,char*argv[])
{
    int id=fork();
    if(id==0)
    {
        printf("I am from child");
    }
    return 0;
}