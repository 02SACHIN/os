#include <iostream>
using std::cin; using std::cout; using std::endl;

class Scheduling
{
    int** Process;  
    
    int number;     //Number of processes.
    int start_time; 
    int quantum_time; //Quantum time for each process 

    public:

    Scheduling();
    void Read_info();
    void RR();
};

Scheduling::Scheduling()  
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
        cout<<"Enter the Arrival time of the process number "<<i+1<<" :";
        cin>>Process[i][1];
        cout<<"Enter the Burst time of the process number "<<i+1<<" :";
        cin>>Process[i][2];
    }

    cout<<"Please enter the quantum time unit:";
    cin>>quantum_time;
}

void Scheduling::RR()
{
    int sum = 0;  // Array required to accomodate the process

    for(int i = 0; i < number; i++) 
    {
        sum+=Process[i][2];  
    }

    int count= 0;  

    int* Array = new int[sum]; //Array to store execution chart.

    for(int i = 0; i < sum; i)
    {
        if(Process[count][2]>0)  // It is logical to consider a process with some positive burst time.
        {
            if(Process[count][2]>=quantum_time) // If the value of burst time is greater than qunatum time, then it executes
                                                // for whole cyle.
            {
                for(int j = 0; j < quantum_time; j++) 
                {
                    Array[i] = Process[count][0]; //Each time i is increased 
                    i++;
                }
                Process[count][2]-=quantum_time; //Burst time is decreased by 1 quantum time 
            }

            else //If the value less then qunatum time 
            {
                while(Process[count][2]!=0)
                {
                    Array[i] = Process[count][0];   // we push process id into the array.
                    i++;                            //Change the index of the array
                    Process[count][2]--;            //and Decrease the value of burst time by 1.
                }
            }
        }

        if(count == number-1) //When count reached value  - 1 then we set 0
        {
            count = 0;
        }

        else  //Increase by one.
        {
            count++;
        }
    }

    for(int i = 0; i < sum; i++) //Print process chart in respect to time time.
    {
        cout<<"Process:"<<Array[i]<<" at time :"<<i+1<<endl;
    }
}

int main()
{
    Scheduling s;
    s.Read_info();
    cout<<"The process execution chart for the cpu is:"<<endl;
    s.RR();
    return 0;
}