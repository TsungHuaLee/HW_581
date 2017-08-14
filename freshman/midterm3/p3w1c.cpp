#include<bits/stdc++.h>
#include<algorithm>
#include<sstream>
#include<vector>
#define N 1100
using namespace std;
int num,lead[N]= {},wei[N]= {};
int mark1[N],mark2[N],mark3[N];
vector<int> edge[N];
void DFS(int node)
{
    for(int i=0; i<edge[node].size(); i++)
    {
        int down=edge[node][i];
        DFS(down);
    }
    for(int i=0; i<edge[node].size(); i++)
    {
        int temp=edge[node][i];
        mark1[node]+=mark3[temp];
        mark2[node]+=mark1[temp];
    }
    mark2[node]+=wei[node];
    mark3[node]=max(mark1[node],mark2[node]);
}
int main()
{
    ios::sync_with_stdio(false);
    string buffer;
    getline(cin,buffer);
    istringstream strinput(buffer);
    int ncase;
    strinput>>ncase;
    for(int ii=0; ii<ncase; ii++)
    {
        for(int i=0; i<N; i++)  //reset
        {
            lead[i]=0;
            wei[i]=0;
            mark1[i]=0;
            mark2[i]=0;
            mark3[i]=0;
            edge[i].clear();
        }
        getline(cin,buffer);
        istringstream strinput(buffer);
        strinput>>num>>wei[1];
        int j=2;
        while(buffer[0]!=0)
        {
            if (getline(cin,buffer)==NULL)
                break;
            istringstream strinput(buffer);
            strinput>>lead[j]>>wei[j];
            int who=lead[j];
            edge[who].push_back(j);
            j++;
        }
        for(int i=1; i<=num; i++)
            if(edge[i].empty())
                mark3[i]=wei[i];
        DFS(1);
        cout<<mark3[1]<<endl;
    }
}
