#include<stdio.h> //for printf
#include<unistd.h> //for close
#include<sys/types.h>// for open
#include<sys/stat.h> //for open
#include<fcntl.h>  //for open,write and read function and for wronly
#include<stdlib.h> //for random integer
#include<time.h> //for time
int main(int argc,char* argv[])
{
  int arr[10];
   srand(time(NULL));
    printf("Opening the file \n");
    int a= open("sample_write.txt",O_RDWR);
    if(a == -1)
    {
        printf("Unable to open\n");
    }
    else
    {
      printf("Trying to write \n");
    for(int i=0;i<10;i++)
    {
       arr[i]=rand()%100;
    }
    int b=write(a,arr,sizeof(int)*10);
      printf("Written 10 numbers to array\n");
    
    }
    for(int i=0;i<10;i++){
    printf("Sending number %d\n",arr[i]);
    }
    int num=0;
    int c=read(a,&num,sizeof(int));
    printf("Got sum from reader %d\n",num);
    close(a);

    return 0;
}