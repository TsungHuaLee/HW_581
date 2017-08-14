#include<bits/stdc++.h>
#define N 10100
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int number_spy;
        cin>>number_spy;
        int leader[N]={};
        for(int i=1;i<number_spy;i++)
            cin>>leader[i];
        int mark[N]={};
        int sum=0;
        for(int i=number_spy-1;i>0;i--)
        {
            if(mark[i]==0)
            {
                mark[leader[i]]=1;
                //cout<<"aaaai="<<i<<"ans"<<leader[i]<<endl;
            }
            else
                {
                    sum++;
                   // cout<<"bbbbi="<<i<<endl;
                }
        }
        sum+=mark[0];
        cout<<sum<<endl;
    }
}
