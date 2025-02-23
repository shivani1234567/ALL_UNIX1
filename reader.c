#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char* argv[])
{
    printf("Opening the file which writer created\n");
    int a=open("sample_write.txt",O_RDONLY);
    printf("File got opened and file handler created\n");
    int y;
    printf("File start reading\n");
    int b=read(a,&y,sizeof(y));
    printf("Read from writer file,%d\n",y);
    close(a);
    return 0;
}