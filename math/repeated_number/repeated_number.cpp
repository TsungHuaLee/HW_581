#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int number,compare;
    while(cin>>number>>compare)//&&(!cin.eof()))
    {
        int c[10]={};
        int i;
        for(i=0;i<7;i++)
        {
            c[i]=compare%10;
            compare/=10;
        }
        int times=0;
        for(i=6;i>0;i--)
        {
            if(number==(c[i]*10+c[i-1]))
            times++;
        }
        cout<<times<<"\n";
    }
}
