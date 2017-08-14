#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        long long int number,power,dividor;
        cin>>number>>power>>dividor;
        long long int output=1,binary_power=0,temp=1;
        long long int i,first=1;
        while(power!=0)
        {
            binary_power=power%2;
            power/=2;
            if(first==1)
               {
                   temp=number;
                   first++;
               }
            else
            temp=(temp*temp)%dividor;
            if(binary_power==1)
                output=(output*temp)%dividor;
        }
        cout<<output<<"\n";
    }
}
