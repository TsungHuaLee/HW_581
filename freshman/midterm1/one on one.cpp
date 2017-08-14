#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int number;
    while(cin>>number)
    {
       if(number==0)
        break;
       int enemy[10001]={},my_soldier[10001]={};
       int i;
       for(i=0;i<number;i++)
        cin>>enemy[i];
       for(i=0;i<number;i++)
        cin>>my_soldier[i];
       sort(enemy,enemy+number);
       sort(my_soldier,my_soldier+number);
       int win=0,j=0;
       for(i=0;i<number;i++)
       {
           if(my_soldier[i]>enemy[j])
           {
               win++;
               j++;
           }
       }
       cout<<win<<"\n";
    }
}

