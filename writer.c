#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
    printf("Opening the file \n");
    int a= open("sample_write.txt",O_WRONLY);
    if(a == -1)
    {
        printf("Unable to open\n");
    }
    else
    {
      printf("Trying to write \n");
    int x=45;
    int b=write(a,&x,sizeof(x));
      printf("Written value %d to the file\n",x);
    }
    close(a);
    return 0;
}