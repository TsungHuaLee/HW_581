#include<bits/stdc++.h>
using namespace std;
int main()
{
    int number,count=1;
    while(cin>>number)
    {
        if(number==0)
        break;
        int height[500]={},total=0;
        for(int i=0;i<number;i++)
        {
            cin>>height[i];
            total+=height[i];
        }
        int average=total/number,sum=0;
        for(int i=0;i<number;i++)
        {
            if(height[i]<=average)
                continue;
            sum+=height[i]-average;
        }
        cout<<"Set #"<<count<<endl;
        cout<<"The minimum number of moves is "<<sum<<".\n\n";
        count++;
    }
}
