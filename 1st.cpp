#include <stdio.h>

int main(int argc, char** argv)
{
    if(argc < 3)  // first argument name of the program ,Second argument File to be copied third argument copying needs to done
         
    {
        printf(" argument pass \n");

        return -1;    //Standard error code
    }

    else
    {
        FILE* f1;   // pointer ---represent the file from -reading  done
        FILE* f2;  // Pointer ---represent the file -you need to write

        int c = 0;  

        f1 = fopen(argv[1] , "r");  //  read mode

        f2 = fopen(argv[2], "w");  // write mode

        while(c!=-1)
        {
            c = fgetc(f1);  // function returns it's ascii value

            if(c!=-1)
            {
                fputc(c , f2); // writes into a file
            }

        }

        printf("Copy successfully\n");
    }

    return 0;
}
