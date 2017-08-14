#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int number;
    while(cin>>number)
    {
        if(number==0)
            break;
        int length[100]= {};
        for(int i=0; i<number; i++)
            cin>>length[i];
        sort(length,length+number);
        int coun=0,i,j,k;
        for(i=2; i<number; i++)
            for(j=0; j<i; j++)
                for(k=j+1; k<i; k++)
                   {
                       //cout<<length[j]<<" "<<length[k]<<endl;
                       if(length[j]+length[k]>length[i])
                         {
                             coun++;
                            //cout<<coun<<endl;
                        }
                   }
        cout<<coun<<endl;
    }
}

