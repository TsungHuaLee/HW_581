#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        string buffer;
        int num=0;
        for(int i=0; i<=str.length(); i++)
        {
            if((str[i]<='9'&&str[i]>='0')||str[i]=='\0')
            {
                for(int j=0; j<num; j++)
                    cout<<buffer;
                num=str[i]-'0';
                buffer.clear();
            }
            else
            buffer+=str[i];
        }
        cout<<endl;
    }
}
