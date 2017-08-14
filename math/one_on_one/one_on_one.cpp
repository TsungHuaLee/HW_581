//use worst of us to best of oppent
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int numOfsolider;
    while(cin>>numOfsolider)
    {
        if(numOfsolider == 0)
            break;
        int enemy[10001] = {},my_soldier[10001] = {};
        int i;
        for(i = 0;i < number;i++)
            cin>>enemy[i];
        for(i = 0;i < number;i++)
            cin>>my_soldier[i];
        sort(enemy,enemy + numOfsolider);
        sort(my_soldier,my_soldier + numOfsolider);
        int win = 0,j = 0;
        for(i = 0; i < number; i++)
        {
            if(my_soldier[i] > enemy[j])
            {
                win++;
                j++;
            }
        }
        cout<<win<<"\n";
    }
}
