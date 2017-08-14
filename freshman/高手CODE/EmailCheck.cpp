#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull validity_check(const string inp)
{
    ull mouse=inp.size();
    ull x=0;
    bool dot=false;
    for(; x<inp.length(); x++)
    {
        if((inp[x]>='0' && inp[x]<='9') || inp[x]=='_' || (inp[x]>='a' && inp[x]<='z') || (inp[x]>='A' && inp[x]<='Z'))
            continue;
        if(inp[x]=='@')
        {
            if(mouse==inp.size())
            {
                mouse=x;
            }
            else
            {
                return 0;
            }
        }
        else if(inp[x]=='.' && mouse!=inp.size())
            dot=true;
    }
    if(dot==false)
        return 0;
    return mouse;
}
bool SBU(const pair<string,string> &A, const pair<string,string> &B)
{
    return A.first<B.first;
}
bool SBD(const pair<string,string> &A, const pair<string,string> &B)
{
    return A.second<B.second;
}
int main()
{
    ull qty, maxlength=0;
    vector<pair<string,string> > data;
    vector<string> Wformat;
    cin>>qty;
    while(qty--)
    {
        ull mouse;
        string inp;
        cin>>inp;
        mouse = validity_check(inp);
        maxlength=max(maxlength,inp.size());
        if(mouse==0 || mouse==inp.size())
        {
            Wformat.push_back(inp);
            continue;
        }
        string fir,sec;
        fir.append(inp.substr(0,mouse));
        sec.assign(inp,mouse+1,inp.length()-mouse-1);
        data.push_back(make_pair(fir,sec));
    }
    cout.setf(ios::left);
    for(ull x=0; x<data.size(); x++)
    {
        cout.width(maxlength+8);
        string output;
        output+=data[x].first;
        output+='@';
        output+=data[x].second;
        cout<<output;
        cout<<"=> Valid\n";
    }
    for(ull x=0; x<Wformat.size(); x++)
    {
        cout.width(maxlength+8);
        cout<<Wformat[x];
        cout<<"=> Invalid\n";
    }
    cout.unsetf(ios::left);
    string boundary(maxlength+8,'-');
    cout<<boundary<<"\n";
    cout<<"Sort by Username:\n";
    sort(data.begin(),data.end(),SBU);
    for(ull x=0; x<data.size(); x++)
    {
        cout<<data[x].first<<'@'<<data[x].second<<"\n";
    }
    cout<<"\nSort by Domain:\n";
    sort(data.begin(),data.end(),SBD);
    for(ull x=0; x<data.size(); x++)
    {
        cout<<data[x].first<<'@'<<data[x].second<<"\n";
    }
    return 0;
}
