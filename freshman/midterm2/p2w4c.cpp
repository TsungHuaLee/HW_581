#include<bits/stdc++.h>
#define N 10000
typedef unsigned long long ull;
using namespace std;
ull MIN(ull first,ull second)
{
    ull re;
    if(first<second)
        re=first;
    else
        re=second;
    return re;
}
int main()
{
   while(1)
   {
       int number_gate;
       cin>>number_gate;
       if(number_gate==0)
          break;
       int temp1[N]={},temp2[N]={};
       temp1[0]=1000;
       temp2[0]=1000;
       for(int i=1;i<=number_gate;i++)
        cin>>temp1[i]>>temp2[i];
       ull up_up,up_down,down_up,down_down,up_min=0,down_min=0;
       for(int i=1;i<=number_gate;i++)
       {
           up_up=up_min+abs(temp1[i]-temp1[i-1]);
           down_up=down_min+abs(temp1[i]-temp2[i-1]);
           up_down=up_min+abs(temp2[i]-temp1[i-1]);
           down_down=down_min+abs(temp2[i]-temp2[i-1]);
           up_min=MIN(up_up,down_up);
           down_min=MIN(up_down,down_down);
           //cout<<up_min<<" "<<down_min<<endl;
       }
       cout<<MIN(up_min,down_min)<<endl;
   }
}
