#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int table[101][101][101];// -1->never go  0->go but not  1->go
int val_a,val_b,val_c,tim;
int run(int want,int na,int nb,int nc)
{
    tim++;
    if(want==0) return 1;

    if(table[na][nb][nc]>=0)//if have went
        {
            return table[na][nb][nc];
        }
    table[na][nb][nc]=0;//noting happen

    if((want>0&&na>0)&&run(want-val_a,na-1,nb,nc)==1)
        table[na][nb][nc]=1;

    if((want>0&&nb>0)&&run(want-val_b,na,nb-1,nc)==1)
        table[na][nb][nc]=1;

    if((want>0&&nc>0)&&run(want-val_c,na,nb,nc-1)==1)
        table[na][nb][nc]=1;

    return table[na][nb][nc];
}
int main()
{

    ios::sync_with_stdio(false);
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        tim=0;
        int want,na,nb,nc;
        cin>>want>>na>>nb>>nc>>val_a>>val_b>>val_c;
        for(int i=0; i<=100; i++)
            for(int j=0; j<=100; j++)
                for(int k=0; k<=100; k++)
                    table[i][j][k]=-1;
//        cout<<run(want,na,nb,nc);
        if(run(want,na,nb,nc)==1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}
