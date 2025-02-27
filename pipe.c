#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,char* argv[])
{
   srand(time(NULL));
   int a[2];
   pipe(a);
   int id =fork();
   if(id==0) //writer writing to file
   {
     close(a[0]);
     printf("You are inside child\n");
     int arr[10];
     for(int i=0;i<10;i++)
     {
        arr[i]=rand()%100;
     }
     int w=write(a[1],arr,sizeof(int)*10);
     for(int i=0;i<10;i++)
     {
        printf("Sent from writer that is child is %d\n",arr[i]);
     }
     close(a[1]);

   }
   else //reader reading from the file
   {
      wait(NULL);
      printf("Hi You are inside parent\n");
       close(a[1]);
       int brr[10];
       int r =read(a[0],brr,sizeof(int)*10);
       for(int i=0 ;i<10;i++)
        {
          printf("Received from child that is writer is %d\n",brr[i]);
        }
        close(a[0 ]);
   }
   return 0;
}