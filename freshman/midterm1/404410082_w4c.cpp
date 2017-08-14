#include<iostream>
#include <string>
#include<stdlib.h>
using namespace std;
int main()
{
    int ncase;
    cin>>ncase;
    cin.ignore();
    while(ncase--)
    {
        string input;
        getline(cin,input);
        for(int i=0; i<input.length(); i++)
            input[i]=toupper(input[i]);
        char letter[30]= {};
        int count[30]= {};
        for(int i=0; i<26; i++)
            letter[i]='A'+i;
        for(int i=0; i<input.length(); i++)
            for(int j=0; j<26 ; j++)
            {
                if(input[i]==letter[j])
                    count[j]++;
            }
        int max=0;
        for(int i=0;i<26;i++)
            if(count[i]>max)
                max=count[i];
        for(int i=0;i<26;i++)
            if(count[i]==max)
                cout<<letter[i];
        cout<<"\n";
    }
}
