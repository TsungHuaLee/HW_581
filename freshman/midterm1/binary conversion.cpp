#include<iostream>
#include <string>
#include <bitset>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    unsigned long long int N;
    while(cin>>N)
    {
        if(N==0)
            break;
        unsigned long long int sum=0,i;
        for(i=0;i<N;i++)
        {
            string binary;
            cin>>binary;
            string support(32-binary.size(),'0');
            support+=binary;
            //cout<<support<<"\n";
            bitset<32> decimal(support);
            //cout<<decimal<<"\n";
            sum+=(decimal.to_ulong());
        }
            cout<<sum<<"\n";
    }
}
