#include <iostream>

void sort(int** arr, int size) //Sorting the array in increasing order so that first fit is the largest memory chunk.
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i][1] < arr[j][1])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int best_fit(int** arr, int size, int memory)
{

    for(int i = 0; i < size; i++)
    {
        if(arr[i][1] >= memory)
        {
            arr[i][1] = arr[i][1] - memory;
            return arr[i][0];
        }
    }
    return -1;
}

int main()
{
    int number_of_processes, number_of_memory_chunks;

    std::cout<<"Please enter the number of memory chunks:";
    std::cin>>number_of_memory_chunks;

    int** memory = new int*[number_of_memory_chunks];

    for(int i = 0; i < number_of_memory_chunks; i++)
    {
        memory[i] = new int[2];
    }

    for(int i = 0; i < number_of_memory_chunks; i++)
    {
        memory[i][0] = i+1;
        std::cout<<"Enter the size of chunk number "<<i+1<<":";
        std::cin>>memory[i][1];
    }

    sort(memory, number_of_memory_chunks);

    std::cout<<"Please enter the number of processes:";
    std::cin>>number_of_processes;

    int* processes = new int[number_of_processes];

    for(int i = 0; i < number_of_processes; i++)
    {
        std::cout<<"Enter the size of memory required for process number "<<i+1<<":";
        std::cin>>processes[i];
    }

    for(int i = 0; i < number_of_processes; i++)
    {
        int x = best_fit(memory, number_of_processes, processes[i]);
        if(x == -1)
        {
            std::cout<<"No memory found for process "<<i+1<<std::endl;
        }

        else
        {
            std::cout<<"Process number "<<i+1<<" gets memory in chunk number "<<x<<std::endl;
        }
    }
}