#include<bits/stdc++.h>
#include<sstream>
using namespace std;
typedef struct
{
    int left;
    int right;
}Interval;
bool compare(const Interval lys,const Interval rys)
{
    return lys.left<rys.left;
}
int main()
{
    ios::sync_with_stdio(false);
    string buffer;
    getline(cin,buffer);
    istringstream ncase_input(buffer);
    int ncase;
    ncase_input>>ncase;
    getline(cin,buffer);
    for(int ii=0;ii<ncase;ii++)
    {
        getline(cin,buffer);
        int j=0;
        Interval interval[500];
        while(buffer[0]!=0)
        {
            istringstream input(buffer);
            input>>interval[j].left>>interval[j].right;
            if(interval[j].left>interval[j].right)
              {
                  int temp;
                  temp=interval[j].left;
                  interval[j].left=interval[j].right;
                  interval[j].right=temp;
              }
              j++;
              if(getline(cin,buffer)==NULL)
                break;
        }
        sort(interval,interval+j,compare);
        int ans=0,l,r=-1,temp=0;
        for(int i=0;i<j;i++)
        {
            if(r==199)
               break;
            //cout<<"test  "<<interval[i].left<<" "<<interval[i].right<<endl;
            //cout<<"r+1="<<r+1<<endl;
            if(interval[i].left<=r+1)
              {
                  if(interval[i].right>temp)
                    {
                        temp=interval[i].right;
                        l=interval[i].left;
                    }
                  if(temp==199)
                  {
                      ans++;
                      break;
                  }
              }
            else
            {
                ans++;
                //cout<<"i="<<i<<" l="<<l<<" r="<<temp<<endl;
                r=temp;
                i-=1;
            }
        }
        cout<<ans<<endl;
    }
}
