#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int number_item,number_student;
        cin>>number_item>>number_student;

        int item[10100] = {},student[10100] = {};
        for(int i = 0; i < number_item; i++)
            cin>>item[i];
        for(int i = 0; i < number_student; i++)
            cin>>student[i];
        if(number_item > number_student)
        {
            cout<<"-1\n";
            continue;
        }
        sort(item, item + number_item);
        sort(student, student + number_student);
        int sum = 0,j,i;
        for(i = 0, j = 0; i < number_student; i++)
        {
            if(student[i] >= item[j])
            {
                sum += student[i];
                j++;
            }
            if(j == number_item)
                break;
        }
        if(j != number_item)
            cout<<"-1\n";
        else
            cout<<sum<<"\n";
    }
}
