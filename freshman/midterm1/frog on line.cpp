#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        int cell[11111]= {};
        for(int i=0; i<n; i++)
            cin>>cell[i];
        while(m--)
        {
            int position,head;
            cin>>position>>head;
            int book[2][11111]= {},step=1;
            if(head<0)
                book[1][position]=step;  //book[0] store forward
            else
                book[0][position]=step;  //book[1] store backward
            while(1)
            {
                int cycle=0,judge;
                judge=cell[position]*head;
                position+=cell[position]*head;
                step++;
                if(judge>0)
                {
                    head=1;
                    if(book[0][position]>0)  //have recorded -->cycle
                    {
                        cout<<"Cycle "<<step-book[0][position]<<"\n";
                        break;
                    }
                    else
                        book[0][position]=step;    // not yet -->record
                }
                else
                {
                    head=-1;
                    if(book[1][position]>0)
                    {
                        cout<<"Cycle "<<step-book[1][position]<<"\n";
                        break;
                    }
                    else
                        book[1][position]=step;
                }
                if(position>n-1)
                {
                    cout<<"Forward"<<"\n";
                    break;
                }
                if(position<0)
                {
                    cout<<"Backward"<<"\n";
                    break;
                }
            }
        }
    }
    return 0;
}
