#include<bits/stdc++.h>
#include<queue>
using namespace std;
int how_much_time(int number_job,int time[],int number_machine)
{
    priority_queue<int> machine_time;
    for(int i=0; i<number_machine; i++)
        machine_time.push(0);
    int temp;
    for(int i=0; i<number_job; i++)
    {
        temp=machine_time.top();
        //cout<<temp<<endl;
        machine_time.pop();
        machine_time.push(temp-time[i]);
    }
    for(int i=0; i<number_machine-1; i++)
        machine_time.pop();
    int out=-machine_time.top();
    //cout<<out;
    machine_time.pop();
    return out;
}
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int number_job,deadline;
        cin>>number_job>>deadline;
        int time[100100]= {},max=0;
        for(int i=0; i<number_job; i++)
        {
            cin>>time[i];
            if(max<time[i])
                max=time[i];
        }
        if(max>deadline)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int down=1,up=number_job,mid=0,judge=0;
        while(down<up)
        {
            mid=(down+up)/2;
            //cout<<"mid="<<mid<<endl;
            judge=how_much_time(number_job,time,mid);
            //cout<<"time="<<judge<<endl;
            if(judge<=deadline) up=mid;
            else down=mid+1;
            //cout<<"up="<<up<<"down="<<down<<endl;
        }
        cout<<up<<endl;
    }
}
