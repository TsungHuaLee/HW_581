#include<iostream>
#include<cstdlib>
using namespace std;
//int book[1000200];
int main()
{
    while(1)
    {
        int *book;
        book = (int*)malloc(sizeof(int)*1000200);
        int dividend(0),divisor(0);
        cin>>dividend>>divisor;
        if(divisor == 0){
            free(book);
            break;
        }
        int i;
        for(i = 1;;i++)   //Store where remainder show up
        {
             if(book[dividend] > 0)  //if remainder show up again -> cycle
                break;      //this time remainder will be next time dividend
             book[dividend] = i;
             dividend = (dividend * 10) % divisor;
        }
        cout<<i - book[dividend]<<"\n";  // i'th show up again - last time show up = cycle length
    }
}
