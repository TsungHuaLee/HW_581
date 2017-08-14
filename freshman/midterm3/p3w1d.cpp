#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int num_node;
        cin>>num_node;
        int head[5100]={},dis[5100]={};
        for(int i=2;i<=num_node;i++)
            cin>>head[i];
        for(int i=2;i<=num_node;i++)
            cin>>dis[i];
        int num[5100]={};
        for(int i=1;i<=num_node;i++)
            num[i]=1;
        int sum=0;
        for(int i=num_node;i>=1;i--)
        {
            num[head[i]]+=num[i];
            int leave=num_node-num[i];
            sum+=(num[i]*leave*dis[i]*2);
//            cout<<num[i]<<"*"<<leave<<"*"<<dis[i]<<"*2"<<endl;
        }
        cout<<sum<<endl;
    }

}
