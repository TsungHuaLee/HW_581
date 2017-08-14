#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int num_wei,num_thing;
        cin>>num_wei>>num_thing;
        int wei[2000]={},thing[500]={};
        int book[200100]={},total=0;
        for(int i=0;i<num_wei;i++)
        {
            int temp;
            cin>>temp;
            book[temp]=1;
            for(int j=total;j>=0;j--)  //from back -->do not repeat
                {
                    if(book[j]>0)
                    book[j+temp]=1;
                }
            total+=temp;
        }
        int ans=0;
        for(int i=0;i<num_thing;i++)
        {
            int temp;
            cin>>temp;
            if(book[temp]>0)
                ans++;
        }
        cout<<ans<<endl;
    }
}
