#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char* argv[])
{
    printf("Opening the file which writer created\n");
    int a=open("sample_write.txt",O_RDWR);
    printf("File got opened and file handler created\n");
    int brr[10];
    printf("File start reading\n");
    int b=read(a,brr,sizeof(int)*10);
    for(int i=0;i<10;i++)
    {
    printf("Read from writer file %d\n",brr[i]);
    }
    int sum=0;
    for(int i=0;i<10;i++)
    {
        sum=sum+brr[i];
    }
    printf("Sending sum to writer %d",sum);
    int c=write(a,&sum,sizeof(int));
    close(a);
    
    return 0;
}