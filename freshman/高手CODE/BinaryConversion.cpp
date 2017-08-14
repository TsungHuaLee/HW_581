
#include <iostream>
//#include <cstdint>
#include <string>
#include <bitset>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    unsigned long long nums;
    while(cin>>nums)
    {
        if(nums==0)
            break;
//        uint32_t sum=0;
        unsigned long sum=0;
        for(unsigned long long x=0; x<nums; x++)
        {
            string inp;
            cin>>inp;
            string support(32-inp.size(),'0');
            support+=inp;
//            cout<<support<<"\n";
            bitset<32> temp(support);
//            cout<<temp<<"\n";
            sum+=(temp.to_ulong());
        }
        cout<<sum<<"\n";
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
//    ios::sync_with_stdio(false);
    ull nums;
    while(cin>>nums)
    {
        ull sum=0;
        if(nums==0)
            break;
        while(nums--)
        {
            string inp;
            cin>>inp;
            for(int x=0; x<inp.size(); x++)
            {
                if(inp[inp.size()-x-1]=='1')
                    sum+=1<<x;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
*/
/*
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long mystoll(string inp) {
    int value = 0;
    for (size_t i = 0; i < inp.length(); i++)
        value = value * 2 + (inp[i] - '0');
    return value;
}

int main() {
    ios::sync_with_stdio(false);

    int N;
    while (cin >> N) {
        if (N == 0) break;

        long long sum = 0;

        for (int i = 0; i < N; i++) {
            string inp;
            cin >> inp;
            sum += mystoll(inp);
        }

        cout << sum << "\n";
    }

    return 0;
}
*/
