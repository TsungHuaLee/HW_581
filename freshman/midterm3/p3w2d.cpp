#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int number;
    while(1)
    {
        cin>>number;
        if(number==0)
            break;
        long long int table[300][300]= {},coun[300][300]= {};
        for(int i=1; i<=number; i++)
            for(int j=1; j<=number; j++)
                cin>>table[i][j];

        coun[1][1]=table[1][1];
        for(int i=1; i<=number; i++)
            for(int j=1; j<=number; j++)
            {
                long long int add=(coun[i-1][j]>=coun[i][j-1])?coun[i-1][j]:coun[i][j-1];
                coun[i][j]=add+table[i][j];
            }

        cout<<coun[number][number]<<endl;
    }
}
