#include<bits/stdc++.h>
#define N 100
using namespace std;
int value[N][N];
int number,ans;
void place_queen(int i,int queen_pos[N])
{
    int conflict;
    if(i==number)
    {
        int temp=0;
        for(int k=0; k<number; k++)
            {
                int place=queen_pos[k];
                int add=value[k][place];
                temp+=add;
            }
        if(temp>ans)
            ans=temp;
        return;
    }
    for(int k=0; k<number; k++)  // 8 column
    {
        conflict=0;
        for(int j=0; j<i&& !conflict; j++)
            if(queen_pos[j]==k||abs(k-queen_pos[j])==i-j)
                conflict=1;
        if(!conflict)
        {
            queen_pos[i]=k;
            place_queen(i+1,queen_pos);
        }
    }
}
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                value[i][j]=0;

        cin>>number;
        for(int i=0;i<number;i++)
            for(int j=0;j<number;j++)
                cin>>value[i][j];

        ans=0;
        int queen_pos[N]= {};
            place_queen(0,queen_pos);
        cout<<ans<<endl;
    }
    return 0;
}
