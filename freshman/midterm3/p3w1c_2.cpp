#include<bits/stdc++.h>
#include<algorithm>
#include<sstream>
#include<vector>
#define N 1100
using namespace std;
int num,lead[N]= {},wei[N]= {};
int mark1[N],mark2[N],mark3[N];
vector<int> child[N];   //有幾個小孩
void DFS(int node)
{
    for(int i=0; i<child[node].size(); i++)
    {
        int down=child[node][i];
        DFS(down);
    }
    for(int i=0; i<child[node].size(); i++)
    {
        int temp=child[node][i];
        mark1[node]+=mark3[temp];
        mark2[node]+=mark1[temp];
    }
    mark2[node]+=wei[node];     //mark2 自己+以前的mark1
    mark3[node]=max(mark1[node],mark2[node]);
}
int main()
{
    ios::sync_with_stdio(false);
//    string buffer;
//    getline(cin,buffer);
//    istringstream strinput(buffer);
    int ncase;
//    strinput>>ncase;
    cin>>ncase;
//    cout<<ncase<<endl;
    for(int ii=0; ii<ncase; ii++)
    {
        for(int i=0; i<N; i++)  //reset
        {
            lead[i]=0;
            wei[i]=0;
            mark1[i]=0;
            mark2[i]=0;
            mark3[i]=0;
            child[i].clear();
        }
//        getline(cin,buffer);
//        istringstream strinput(buffer);
        cin>>num>>wei[1];
//        cout<<num<<" "<<wei[1]<<endl;
        int j=2;
//        while(buffer[0]!=0)         //input
//        {
//            if (getline(cin,buffer)==NULL)
//                break;
//            istringstream strinput(buffer);
//            strinput>>lead[j]>>wei[j];
//            int who=lead[j];
//            child[who].push_back(j);
//            j++;
//        }
        for(int i=0;i<num-1;i++)
        {
            cin>>lead[j]>>wei[j];
            int who=lead[j];
            child[who].push_back(j);
            j++;
        }
        for(int i=1; i<=num; i++)   //底層都先找最大(mark3)
            if(child[i].empty())
                mark3[i]=wei[i];
        DFS(1);
        cout<<mark3[1]<<endl;
    }
}
