#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int number;
    while(cin>>number)
    {
        if(number==0)
            break;
        int max1=0,max2=0,yes,no,input;
        for(int i=0; i<number; i++)
        {
            cin>>input;
            yes=input+max2;
            no=(max1>max2)?max1:max2;
            max1=yes;
            max2=no;
        }
        //int ans=(max1>max2)?max1:max2;
        //cout<<ans<<endl;
//        cout<<((max1>max2)? max1 : max2)<<endl;
        printf("%d\n",(max1>max2)? max1 : max2);
    }
}

