#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef struct
{
    ull left;
    ull right;
} interval;
bool compare(const interval lhs,const interval rhs)
{
    return lhs.left<rhs.left;
}
int main()
{
    ios::sync_with_stdio(false);
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int number_line;
        cin>>number_line;
        interval line[50100];
        for(int i=0;i<number_line;i++)
        {
            int l,r,temp;
            cin>>l>>r;
            if(l>r)
            {
                temp=l;
                l=r;
                r=temp;
            }
            line[i].left=l;
            line[i].right=r;
        }
        sort(line,line+number_line,compare);
        //for(int i=0;i<number_line;i++)
        //    cout<<line[i].left<<" "<<line[i].right<<endl;
        int sum=0,temp_left,temp_right;
        temp_left=line[0].left;
        temp_right=line[0].right;
        for(int i=1;i<number_line;i++)
        {
             if(line[i].left>temp_right)
             {
                 sum+=temp_right-temp_left;
                 temp_left=line[i].left;
                 temp_right=line[i].right;
             }
             else if(line[i].left<temp_right&&line[i].right>temp_right)
                temp_right=line[i].right;
        }
         sum+=temp_right-temp_left;
        cout<<sum<<endl;
    }
}
