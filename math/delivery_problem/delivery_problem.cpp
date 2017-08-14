#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--)
    {
        int number_box;
        int each_time[1100] = {};
        cin>>number_box;
        for(int i = 0; i < number_box; i++)
            cin>>each_time[i];
        sort(each_time,each_time + number_box);
        int total = each_time[0],before = 0;
        for(int i = 1; i < number_box; i++)
        {
            before += 2 * each_time[i - 1];
            total = total + before + each_time[i];
        }
        cout<<total<<"\n";
    }
}
