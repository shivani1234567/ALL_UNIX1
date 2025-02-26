#include<unistd.h>
#include<stdio.h>
int main(int argc,char*argv[])
{
    int id=fork();
    if(id==0){

    printf("Before \n");
    execl("/bin/ping","ping process","-c","1","google.com",NULL);//pinging to infinite times
    for(int i=0;i<100;i++)
    {
    printf("After\n");
    }

   }
   else{
     sleep(1);
     printf("Hi From parent \n");


   }

    return 0;
}
