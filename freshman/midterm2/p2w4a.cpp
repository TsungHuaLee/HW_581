#include<bits/stdc++.h>
#define N 15000
using namespace std;
typedef struct
{
    int wide;
    int height;
} record;
bool compare(const record lhs,const record rhs)
{
    return lhs.wide>rhs.wide;
}
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        record dimension[N]= {};
        int number_type,times=0;
        cin>>number_type;
        for(int i=0; i<number_type; i++)
        {
            int l,r;
            cin>>l>>r;
            dimension[times].wide=l;
            dimension[times].height=r;
            times++;
            dimension[times].wide=r;
            dimension[times].height=l;
            times++;
        }
        sort(dimension,dimension+times,compare);
        //for(int i=0; i<times; i++)
        //    cout<<dimension[i].wide<<" "<<dimension[i].height<<endl;
        int judge=dimension[0].wide,add=dimension[0].height,ans=0;
        for(int i=1; i<=times; i++)
        {
            if(judge==dimension[i].wide)
            {
                if(add<dimension[i].height)
                    add=dimension[i].height;
                continue;
            }
            else
            {
                ans+=add;
                //cout<<" add="<<add<<" ans="<<ans;
                judge=dimension[i].wide;
                add=dimension[i].height;
            }
        }
        cout<<ans<<endl;
    }
}
