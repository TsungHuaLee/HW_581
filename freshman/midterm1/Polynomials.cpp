#include<iostream>
using namespace std;
int main()
{
    int times,first=1;
    cin>>times;
    while(times--)
    {
        if(first==1)
            first++;
        else
            cout<<"\n";
        int coe[10000]= {},ori_coe[10000]= {},power;
        int i;
        for(i=2; i>=0; i--)
            cin>>coe[i];
        cin>>power;
        for(i=2; i>=0; i--)
            ori_coe[i]=coe[i];
        int max_power;
        if(power==1)
            max_power=2;
        else
            max_power=4;
        int t,j;
        int temp_coe[10000]= {};
        for(t=1; t<power; t++)
        {
            for(i=max_power;i>=0;i--)
                temp_coe[i]=0;
            for(i=max_power; i>=0; i--)
            {
                for(j=i; j>=0; j--)
                    temp_coe[i]+=coe[j]*ori_coe[i-j];
            }
            for(i=max_power; i>=0; i--)
            {
                coe[i]=temp_coe[i];
            }
            max_power+=2;
        }
        for(i=2*power; i>=0; i--)
        {
            cout<<coe[i];
            if(i>0)
                cout<<" ";
        }
    }
    return 0;
}
