#include<iostream>
using namespace std;

int main()
{
    int ncase;
    cin>>ncase;
    while (ncase--)
    {
        long long int base, power, dividor;
        cin>>base>>power>>dividor;
        long long int ans(1), binaryPower(0), temp(1), first(1);
        while(power != 0)  //2^5 = 2^4 * 2^1
        {                  // 5 = 101
            binaryPower = power % 2;    //power decimal to binary .
            power /= 2;
            if(first == 1)
               {
                   temp *= base;  // 2^1
                   first++;
               }
            else
            temp = (temp * temp) % dividor; // first power can use this formula
            if(binaryPower == 1)
                ans=(ans * temp) % dividor;
        }
        cout<<ans<<endl;
    }
    return 0;
}
