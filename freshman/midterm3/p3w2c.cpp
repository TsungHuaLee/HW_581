#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int number,*num;
        num=(int*)malloc(sizeof(int)*600100);
        cin>>number;
        int *temp;
        temp=(int*)malloc(sizeof(int)*600100);
        temp[0]=0;
        int ans=0;
        for(int i=1;i<=number;i++)
            {
                cin>>num[i];
                temp[i]=(temp[i-1]>0)?temp[i-1]+num[i]:num[i];
                if(temp[i]>ans)
                    ans=temp[i];
            }
            cout<<ans<<endl;

    }
}

