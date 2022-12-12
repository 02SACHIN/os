#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    
    pid=fork();   //child process
    
    if(pid<0)   
    {
        printf("Something wrong retry\n");
    }

    else if(pid == 0) 
    {
        printf("________________Child created successfully________\n");
        printf("_______Executing the child process________________\n");
        execlp("/home/Desktop/helloWorld.exe","helloWorld.exe",NULL); 
    }

    else  {
        wait(NULL);  //wait untill one of the child is finished.
       
        printf("_____________ parent process______________________\n");
        printf("The id of the process is__________________%d",pid);  
        printf("\nExecuting the code in parent process.\n");
    }

    return 0;
}