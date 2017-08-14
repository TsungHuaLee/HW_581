#include<bits/stdc++.h>
#include<stack>
#include<vector>
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
        int start[5000]= {},treasure[5000]= {};
        for(int i=0; i<number_starting; i++)
            cin>>start[i];
        for(int i=0; i<number_treasure; i++)
            cin>>treasure[i];
        vector<int> road[5000];
        int u,v;
        for(int i=0; i<number_road; i++)
        {
            cin>>u>>v;
            road[u].push_back(v);
        }
        int visit[5000]= {},max=0,point;
        stack<int> city;
        for(int i=0; i<number_starting; i++)
        {
            city.push(start[i]);
            visit[start[i]]++;
            if(max<treasure[start[i]])
                max=treasure[start[i]];
            while(!city.empty())
            {
                int point=city.top();
                city.pop();
                for(int j=0; j<road[point].size(); j++)
                {
                    int next;
                    next=road[point][j];
                    //cout<<"next"<<next<<endl;
                    if(visit[next]==0)
                    {
                        city.push(next);
                        visit[next]++;
                        if(max<treasure[next])
                            max=treasure[next];
                    }
                }
            }
        }
        cout<<max<<endl;
    }
}

