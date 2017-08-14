#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> machine_time;
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int number_job,number_machine;
        cin>>number_job>>number_machine;
        for(int i=0;i<number_machine;i++)
            machine_time.push(0);  //every machine initial time is 0
        int job_time,temp;
        for(int i=0;i<number_job;i++)
        {
            cin>>job_time;
            temp=machine_time.top();
            machine_time.pop();
            machine_time.push(temp-job_time);
        }
        for(int i=0;i<number_machine-1;i++)
            machine_time.pop();
        cout<<-machine_time.top()<<endl;
        machine_time.pop();
    }
    return 0;
}
