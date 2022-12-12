#include <iostream>

int first_fit(int* arr, int size, int memory)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] >= memory)
        {
            arr[i] = arr[i] - memory;
            return i;
        }
    }

    return -1;
}

int main()
{
    int number_of_processes, number_of_memory_chunks;

    std::cout<<"Please enter the number of memory chunks:";
    std::cin>>number_of_memory_chunks;

    int* memory = new int[number_of_memory_chunks];

    for(int i = 0; i < number_of_memory_chunks; i++)
    {
        std::cout<<"Enter the size of chunk number "<<i+1<<":";
        std::cin>>memory[i];
    }

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
        int x = first_fit(memory, number_of_processes, processes[i]);
        if(x == -1)
        {
            std::cout<<"No memory found for process "<<i+1<<std::endl;
        }

        else
        {
            std::cout<<"Process number "<<i+1<<" gets memory in chunk number "<<x+1<<std::endl;
        }
    }
}