#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int numInput;
    while(cin>>numInput)
    {
        if(numInput == 0)
        break;
        int sum(0);
        for(int i = 0;i < numInput;i++)
        {
            string input;
            cin>>input;
            int k,j;
            for(k = 0,j = 0;input[j];j++)
            {
                k *= 2;
                if(input[j] == '1')
                k++;
            }
            sum += k;
        }
        cout<<sum<<endl;
    }
    return 0;
}
