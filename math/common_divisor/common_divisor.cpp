#include<iostream>
using namespace std;

int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int q1,r1,q2,r2;
        cin>>q1>>r1>>q2>>r2;
        int divisor[2000] = {},smaller,larger;
        if(q1 - r1 > q2 - r2)
        {
            larger = q1 - r1;
            smaller = q2 - r2;
        }
        else
        {
            larger = q2 - r2;
            smaller = q1 - r1;
        }
        int i;
        for(i = 1; i <= smaller; i++)
        {
            if(smaller % i == 0 && larger % i == 0)
                divisor[i]++;
            else
                continue;
        }

        for(i=1;i<=smaller;i++)
        {
            if(divisor[i]!=0)
                cout<<i<<" ";
        }
    }
    return 0;
}
