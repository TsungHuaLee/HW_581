#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    while(getline(cin,input))
    {
        for(int i=0;i<input.length();i++)
        {
            if(input[i]<='8'&&input[i]>='0')
                input[i]+=1;
            else if(input[i]=='9')
                input[i]='0';
            else if(input[i]<='Z'&&input[i]>='A')
                input[i]=('Z'-input[i])+'a';
            else if(input[i]<='z'&&input[i]>='a')
                input[i]=('z'-input[i])+'A';
        }
        cout<<input<<endl;
    }

}

