#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int validity_of_at(const string email)//valid return at_position ,invalid return -1;
{
    int number_at=0,at_position=0;
    for(int i=0; i<email.length(); i++)
    {
        if(email[i]=='@')
        {
            number_at++;
            at_position=i;
        }
    }
    if((number_at>1)||(number_at==0))
        return -1;
    else
        return at_position;
}
int validity(const string iden)
{
    int judge;
    for(int i=0; i<iden.length(); i++)
    {
        if((iden[i]>='0' && iden[i]<='9') || iden[i]=='_' || (iden[i]>='a' && iden[i]<='z') || (iden[i]>='A' && iden[i]<='Z')||iden[i]=='.')
            judge=1;
        else
        {
            judge=-1;
            break;
        }
    }
    return judge;
}
void account_sort(string email[],string account[],string domain[],int valid[],int ncase)
{
    int min,i,j,integer;
    string temp;
    for(i=0;i<ncase-1;i++)
    {
        min=i;
        for(j=1;j<ncase;j++)
        {
            if(account[min]>account[j])
                min=j;
        }
        temp=email[i];
        email[i]=email[min];
        email[min]=temp;
        temp=account[i];
        account[i]=account[min];
        account[min]=temp;
        temp=domain[i];
        domain[i]=domain[min];
        domain[min]=temp;
        integer=valid[i];
        valid[i]=valid[min];
        valid[min]=integer;
    }
    cout<<"Sort by Username:\n";
}
void domain_sort(string email[],string account[],string domain[],int valid[],int ncase)
{
    int min,i,j,integer;
    string temp;
    for(i=0;i<ncase-1;i++)
    {
        min=i;
        for(j=1;j<ncase;j++)
        {
            if(domain[min]>domain[j])
                min=j;
        }
        temp=email[i];
        email[i]=email[min];
        email[min]=temp;
        temp=domain[i];
        domain[i]=domain[min];
        domain[min]=temp;
        temp=account[i];
        account[i]=account[min];
        account[min]=temp;
        integer=valid[i];
        valid[i]=valid[min];
        valid[min]=integer;
    }
    cout<<"Sort by Domain:\n";
}

int main()
{
    int ncase;
    cin>>ncase;
    string email[ncase];
    int valid[1000]= {},at=0;
    string account[ncase],domain[ncase];
    int length=0;
    for(int i=0; i<ncase; i++)// n case email
    {
        cin>>email[i];
        if(length<email[i].length())
            length=email[i].length();
        at=validity_of_at(email[i]);
        if(at<0)         // now validity judge "at"
            valid[i]=-1;
        else
        {
            account[i].assign(email[i],0,at);
            domain[i].append(email[i],at+1,email[i].length());
            //cout<<"account "<<account[i]<<"\n";
            //cout<<"domain "<<domain[i]<<"\n";
            //int judge_account,judge_domain;
            int judge_account=validity(account[i]);
            int judge_domain=validity(domain[i]);
            //cout<<i<<" "<<judge_account<<" "<<judge_domain<<"\n";
            if((judge_account==1)&&(judge_domain==1))
                valid[i]=1;
            else
                valid[i]=-1;
        }
    }
    for(int i=0;i<ncase;i++)
    {
        cout<<email[i];
        for(int j=0;j<length+6-email[i].length();j++)
            cout<<" ";
        cout<<"=>";
        if(valid[i]>0)
            cout<<"valid"<<"\n";
        else
            cout<<"Not valid"<<"\n";
    }
    cout<<"----------------------\n";
    account_sort(email,account,domain,valid,ncase);
    for(int i=0;i<ncase;i++)
        if(valid[i]>0)
        cout<<email[i]<<"\n";
    cout<<"\n";
    domain_sort(email,account,domain,valid,ncase);
    for(int i=0;i<ncase;i++)
        if(valid[i]>0)
        cout<<email[i]<<"\n";
}
