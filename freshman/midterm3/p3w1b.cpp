#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int number;
    while(cin>>number)
    {
        if(number==0)
            break;
        int pay[1100]= {};
        for(int i=0; i<number; i++)
            cin>>pay[i];
        int mark1[1100]= {},mark2[1100]= {} ,mark3[1100]= {};
        mark1[0]=0;
        mark2[0]=pay[0];
        for(int i=0; i<number; i++)
        {
            mark1[i]=mark3[i-1];
            mark2[i]=pay[i]+mark1[i-1];
            mark3[i]=max(mark1[i],mark2[i]);
            //cout<<i<<" "<<mark1[i]<<" "<<mark2[i]<<" "<<mark3[i]<<endl;
        }
        cout<<mark3[number-1]<<endl;
    }
}
