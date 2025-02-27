#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(int argc,char*argv[])
{
    int id=fork();
    if(id==0){

    printf("Before \n");
    execl("/bin/ping","ping proess","-c","1","goo
        
        gle.com",NULL);//pinging to infinite times
    for(int i=0;i<100;i++)
    {
    printf("After\n");
    }

   }
   else{
     wait(NULL);
     printf("Hi From parent \n");


   }

    return 0;
}