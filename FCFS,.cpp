#include <iostream>
using std::cin; using std::cout; using std::endl;

class Scheduling
{
    int** Process;   //Stores the information
                    //1st process numbe 
                    //2nd Arrival time
                    //3rd burst time.
    int number;     
    int start_time; 
    public:

    Scheduling();
    void Read_info();
    void FCFS();
};

Scheduling::Scheduling()  //Constructor
{
    cout<<"Please enter the number of process:";
    cin>>number;

    Process = new int*[number];

    for(int i = 0; i<number; i++)
    {
        Process[i] = new int[3];
    }

}

void Scheduling::Read_info()  
{
    for(int i = 0; i<number; i++)
    {
        Process[i][0] = i+1;
        cout<<"Enter the Arrival time of the process number:"<<i+1<<" :";
        cin>>Process[i][1];
        cout<<"Enter the Burst time of the process number:"<<i+1<<" :";
        cin>>Process[i][2];
    }

    cout<<"Enter the arrival time of the process which arrived first for reference:";
    cin>>start_time;

}

void Scheduling::FCFS()
{
    int time = start_time;
    int free_time;          //Store the time for which the cpu is free 
                             

    cout<<"The order of execution of the Process is:"<<endl;

    int minimum_index = 0;  //Index for 2d matrix ,whose arrival time is minimum

    for(int i = 0; i < number; i++)
    {
        minimum_index = i;  

        for(int j = 0; j < number; j++)
        {
            if((Process[minimum_index][1]>Process[j][1]))
            {
                minimum_index = j;
            }
        }

        free_time = time - Process[minimum_index][1]; //Calculate free time 
        if(free_time > 0)  // A positive value represents that the next process arrived before completion of the previous process.
        {
            cout<<"Process number :"<<Process[minimum_index][0]<<" Wait time = "<<time-Process[minimum_index][1]<<" Turnaround time = "<<time-Process[minimum_index][1]+Process[minimum_index][2];
            cout<<endl;
            Process[minimum_index][1] = INT16_MAX; 
            time += Process[minimum_index][2];      // current time is increased by the burst time of the process.
        }

        else  //when free cpu time availabe.
        {
             cout<<"Process number :"<<Process[minimum_index][0]<<" Wait time = "<<time-Process[minimum_index][1]-free_time<<" Turnaround time = "<<time-Process[minimum_index][1]+Process[minimum_index][2]-free_time;
            cout<<endl;

            

            Process[minimum_index][1] = INT16_MAX;
            time += Process[minimum_index][2];      // Both of these part remain same as previous one.
        }
    }
}

int main()
{
    Scheduling s;
    s.Read_info();
    s.FCFS();
}