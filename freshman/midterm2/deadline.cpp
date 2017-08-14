#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef struct{
   int t;
   int d;
}input;
bool Compare(const input lys,const input rys)
{
    return lys.d<rys.d;
}
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int number_job;
        cin>>number_job;
        input time[number_job];
        for(int i=0;i<number_job;i++)
            cin>>time[i].t;
        for(int i=0;i<number_job;i++)
            cin>>time[i].d;
        sort(time,time+number_job,Compare);
        int flag=1,sum=0;
        for(int i=0;i<number_job;i++)
        {
            sum+=time[i].t;
            //cout<<sum<<endl;
            if(sum>time[i].d)
              {
                  flag=0;
                  break;
              }
        }
        if(flag==0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
}

