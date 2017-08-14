#include<bits/stdc++.h>
#include<vector>
#define MAX 5100
using namespace std;
int visit[MAX];
int value[MAX],ans;
vector<int>edge[MAX];
void DFS(int node)
{
    visit[node]=1;
    if(value[node]>ans)
        ans=value[node];
    int next;
    for(int i=0; i<edge[node].size(); i++)
    {
        next=edge[node][i];
        if(visit[next]==0)
            DFS(next);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int number_node,number_edge,number_start;
    while(cin>>number_node>>number_edge>>number_start)
    {
        if(number_node==0&&number_edge==0&&number_start==0)
           break;
        for(int i=0;i<MAX;i++)   //reset
            edge[i].clear();
        for(int i=0;i<MAX;i++)    //reset
            value[i]=0;
        ans=0;     //reset
        int start[1000]={};
        for(int i=0;i<number_start;i++)
            cin>>start[i];
        for(int i=0;i<number_node;i++)
            cin>>value[i];
        int u,v;
        for(int i=0;i<number_edge;i++)
        {
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
           // cout<<u<<" "<<v<<endl;
           // cout<<"sad"<<endl;
        }
        for(int i=0;i<number_start;i++)
        {
            for(int j=0;j<MAX;j++)
                visit[j]=0;
            if(visit[start[i]]==0)
                DFS(start[i]);
        }
        cout<<ans<<endl;
    }
}
