#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>    //This header file has constants defined used in opening the file.
#include <sys/stat.h> //header file  stat struct.
#include <time.h>  //time header convert seconds into proper date.

int main(int argc, char** argv)
{
    struct stat buffer;   //variable stat
    int fd = open(argv[1],O_RDONLY);  //Opening the file in read only mode.
    printf("\n");

    if(fstat(fd, &buffer) == -1)  //case  when no name is provided or problem with opening file.
    {
        printf("Bad call.\n");
    }

    else
    {
        printf("File information retrieved successfully...\n");
        printf("File user id is : %d",buffer.st_uid);  //print user id from the stat struct.
        printf("\n");
        printf("File Size is : %d",(int)buffer.st_size);    //size of file from the stat struct.
        printf(" bytes\n");
        printf("File mode info : %d",buffer.st_mode);       //printing mode 
        printf("\n");

        //first we  get the access and modification time in seconds.
        //Then it is converted into proper date using ctime function defined in "time.h "header file
        printf("The file was last accessed on: %s", ctime(&buffer.st_atime));  
        printf("The file was modified on: %s", ctime(&buffer.st_mtime));

    }

    return 0;
}