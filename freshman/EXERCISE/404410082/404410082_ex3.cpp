#include<bits/stdc++.h>
#include<sstream>
#include<math.h>
using namespace std;
typedef struct
{
    char name[16];
    int age;
    enum {female,male,undefined} sex;
} record;
void change(string &input,string &name_input,string &age_input,string &sex_input)
{
    int times=0,times2=0;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i]=='"')
        {
            times++;
            continue;
        }
        if(times<2)
        {
            name_input=name_input+input[i];
            continue;
        }
        if(input[i]==',')
        {
            times2++;
            continue;
        }
        if(times2<2)
        {
            age_input=age_input+input[i];
            continue;
        }
        sex_input=sex_input+input[i];
    }
    //cout<<name_input<<endl<<age_input<<endl<<sex_input<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    record *data;
    int size=1;
    data=(record*)malloc(sizeof(record)*size);
    string input;
    int judge=0,flag=0;
    while(getline(cin,input))
    {
        if(input=="break")
            break;
        string name_input,age_input,sex_input;
        change(input,name_input,age_input,sex_input);
//        cout<<name_input<<endl<<age_input<<endl<<sex_input<<endl;
        if(judge==size)
        {
            cout<<"FULL"<<endl<<"double_size"<<endl;
            record *temp_data;
            temp_data=(record*)malloc(2*size*sizeof(record));
            memmove(temp_data,data,size*sizeof(record));
            free(data);
            data=temp_data ;
            size<<=1;
        }
        string temp;
        int times=0;
        for(int i=0; i<name_input.length(); i++)
            data[flag].name[i]=name_input[i];
        int number=0;
        for(int i=0; i<age_input.length(); i++)
        {
            number=number*10+age_input[i]-48;
            //cout<<i<<"number"<<number<<" "<<age_input[i]<<endl;
        }
        data[flag].age=number;
        if(sex_input=="female")
        {
            data[flag].sex=record::female;
        }
        else if(sex_input=="male")
        {
            data[flag].sex=record::male;
        }
        else
        {
            data[flag].sex=record::undefined;
        }
        judge++;
        flag++;
    }
    for(int i=0; i<flag; i++)
    {
        cout<<"name="<<data[i].name;
        cout<<",age="<<data[i].age;
        if(data[i].sex==0)
            cout<<",sex=female"<<endl;
        else if(data[i].sex==1)
            cout<<",sex=male"<<endl;
        else
            cout<<",sex=undefined"<<endl;
    }
}
