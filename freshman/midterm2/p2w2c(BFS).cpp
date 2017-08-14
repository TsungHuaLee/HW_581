#include<bits/stdc++.h>
#include<queue>//or stack
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int number_treasure,number_road,number_starting;
    while(1)
    {
        cin>>number_treasure>>number_road>>number_starting;
        if(number_road==0&&number_road==0&&number_starting==0)
            break;
        int start[2000]={};
        for(int i=0; i<number_starting; i++)
            cin>>start[i];
        int treasure[2000]= {};
        for(int i=0; i<number_treasure; i++)
            cin>>treasure[i];
        int road[200][200]= {},u,v;
        for(int i=0; i<number_road; i++)
        {
            cin>>u>>v;
            road[u][v]++;
        }
        int visit[200]= {},max=0,point;
        queue<int> initial;
        for(int i=0; i<number_starting; i++)
        {
            initial.push(start[i]);
            visit[start[i]]++;
            if(max<treasure[start[i]])
                max=treasure[start[i]];
            while(!initial.empty())
            {
                int point=initial.front();
                initial.pop();
                for(int j=0;j<number_treasure;j++)
                   if(road[point][j]!=0&&visit[j]==0)
                {
                    //cout<<"next"<<road[point][j]<<endl;
                    initial.push(j);
                    visit[j]++;
                    if(max<treasure[j])
                        max=treasure[j];
                }
            }
        }
        cout<<max<<endl;
    }
}
