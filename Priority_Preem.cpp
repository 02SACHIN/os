#include <iostream>
using std::cin; using std::cout; using std::endl;

class Scheduling
{
    int** Process; 
    int number;     //Number represents the number of processes.

    public:

    Scheduling();
    void Read_info();
    void sort();
    void DisplayInformationMatrix();
    void PriorityPreemptive();
};

Scheduling::Scheduling()  
{
    cout<<"Enter the number of process:";
    cin>>number;

    Process = new int*[number];

    for(int i = 0; i<number; i++)
    {
        Process[i] = new int[4];
    }

}

void Scheduling::Read_info()  //Information about the processes and the start time.
{
    for(int i = 0; i<number; i++)
    {
        Process[i][0] = i+1;
        cout<<"Enter the Arrival time of the process number "<<i+1<<" :";
        cin>>Process[i][1];
        cout<<"Enter the Burst time of the process number "<<i+1<<" :";
        cin>>Process[i][2];
        cout<<"Enter the Priority of the process number "<<i+1<<" :";
        cin>>Process[i][3];
    }
}

void Scheduling::DisplayInformationMatrix() //Display the 2-d matrix.
{
    for(int i = 0; i < number; i++)
    {
        cout<<Process[i][0]<<" "<<Process[i][1]<<" "<<Process[i][2]<<" "<<Process[i][3]<<endl;
    }
}

void Scheduling::sort() //If two processes have same arrival time then the one with higher priority (low priority number) is placed first
                        
{

    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(Process[i][1] < Process[j][1])
            {
                std::swap(Process[i],Process[j]);
            }

            else if(Process[i][1] == Process[j][1])
            {
                if(Process[i][3]<Process[j][3])
                {
                    std::swap(Process[i],Process[j]);
                }
            }
        }
    }

}

void Scheduling::PriorityPreemptive()
{
    this->sort();// Here the array is first sorted and the process with minimum arrival time marks the begining of the execution.
    int current_time = Process[0][1];
    int total = 0;//Number of cycles required to complete all the process.
    for(int i = 0; i < number; i++)//Numerically the value is equal to the sum of the burst time of the processes.
    {
        total+=Process[i][2];
    }

    int matrix[total];//Store the gant chart.
    int current_Process = Process[0][0] - 1;

    for(int i = 0; i < total; i++)//Total cpu cycles the loop is repeated.
    {
        matrix[i] = Process[current_Process][0];//ith index gets the id of current process.
        Process[current_Process][2]--;          //Burst time of current process is decreasesd.
        current_time++;                         // and current time is increased.

        if(Process[current_Process][2]<=0) 
        {
            Process[current_Process][3] = INT16_MAX;
        }

        for(int j = 0; j < number; j++) //This loop checks if any process should replace the current process.
        {
            if(Process[j][3] < Process[current_Process][3] && Process[j][2]!=0 && Process[j][1]<=current_time)
            {
                //Here three things are checked to replace the current process. 
                //First the process-higherpriority.
                //Second it's burst time should not be zero 
                //third it's arrival time should be less then
                current_Process = j;
            }
                
        }

    }

    for(int i = 0; i < total; i++) //This loop prints the gant chart.
    {
        cout<<"Process :"<<matrix[i]<<" at time:"<<i+Process[0][1]<<endl;
    }

    cout<<"All the processes ends at:"<<current_time<<endl;
}

int main()
{
    Scheduling s;
    s.Read_info();
    s.PriorityPreemptive();
}