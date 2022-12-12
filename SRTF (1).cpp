#include <iostream>
using std::cin; using std::cout; using std::endl;

class Scheduling
{
    int** Process; 
    int number;     //Number of processes.

    public:

    Scheduling();
    void Read_info();
    void sort();
    void DisplayInformationMatrix();
    void SRTF();
};

Scheduling::Scheduling()  //Constructor which initilizes the Process matrix.
{
    cout<<"Enter the number of process:";
    cin>>number;

    Process = new int*[number];

    for(int i = 0; i<number; i++)
    {
        Process[i] = new int[3];
    }

}

void Scheduling::Read_info()  // Start time.
{
    for(int i = 0; i<number; i++)
    {
        Process[i][0] = i+1;
        cout<<"Enter the Arrival time of the process number "<<i+1<<" :";
        cin>>Process[i][1];
        cout<<"Enter the Burst time of the process number "<<i+1<<" :";
        cin>>Process[i][2];
    }
}

void Scheduling::sort() 
                         
                         
{
    for(int i = 0; i < number; i++)  // insertion sort
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

void Scheduling::SRTF()
{
    this->sort();   //Process with minimum arrival time marks the begining of the execution.
    int current_time = Process[0][1]; //Time starts from arrival of the first process.
    int total = 0;  //Total number of cycles required to complete all the process.
    for(int i = 0; i < number; i++) 
    {
        total+=Process[i][2];
    }

    int matrix[total];  //Making a matrix of size total to store the gant chart.
    int current_Process = Process[0][0] - 1; //Here we subtracted one because the pid is one more than index value.
                                            
    for(int i = 0; i < total; i++)   // For total cpu cycles the loop is repeated.
    {
        matrix[i] = Process[current_Process][0]; //ID of current process.
        Process[current_Process][2]--;           //Burst time of current process is decreasesd and current time is increased.
        current_time++;                         

        if(Process[current_Process][2]<=0)       // If burst time becomes zero, we set it's burst time to a large value.
                                                 // so that process with next shortest time is selected next.
        {
            Process[current_Process][2] = INT16_MAX;
        }

        for(int j = 0; j < number; j++)   //This loop checks if any process should replace the current process.
        {
            if(Process[j][2] < Process[current_Process][2] && Process[j][2]!=0 && Process[j][1]<=current_time)
            { 
                //Here three things are checked to replace the current process. 
                //First the process-smaller burst time.
                //Second it's burst time should not be zero 
                //third it's arrival time should be less then
                
                current_Process = j;
            }
        }

    }

  

    for(int i = 0; i < total; i++)  //Loop prints the gant chart 
    {
        cout<<"Process :"<<matrix[i]<<" at time:"<<i+Process[0][1]<<endl;
    }

    cout<<"All the processes ends at:"<<current_time<<endl;

}

int main()
{
    Scheduling s;
    s.Read_info();
    s.SRTF();
}