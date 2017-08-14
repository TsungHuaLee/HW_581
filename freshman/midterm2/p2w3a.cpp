#include<bits/stdc++.h>
#include<vector>
#define MAX 50100
using namespace std;
bool visit[MAX];
int weight[MAX],sum;
vector<int>edge[MAX];
void DFS(int node)//vector<int>edge[
{
    visit[node]=true;
    sum+=weight[node];
    //cout<<"sum="<<sum<<endl;
    int next;
    for(int i=0; i<edge[node].size(); i++)
    {
        next=edge[node][i];
        if(!visit[next])
            DFS(next);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        for(int i=0; i<MAX; i++)
            edge[i].clear();
        int number_node,number_edge;
        cin>>number_node>>number_edge;
        for(int i=0; i<MAX; i++) //reset 0
            weight[i]=0;
        for(int i=0; i<number_node; i++)
            cin>>weight[i];
        int u,v;
        for(int i=0; i<number_edge; i++)
        {
            cin>>u>>v;
            edge[u].push_back(v);  //no direct
            edge[v].push_back(u);
        }
        int max=0;
        fill(visit, visit+MAX, false);
        for(int i=0; i<number_node; i++)
        {
            sum=0;
            if(!visit[i])
                DFS(i);
            if(max<sum)
                max=sum;
        }
        cout<<max<<endl;
    }
}
