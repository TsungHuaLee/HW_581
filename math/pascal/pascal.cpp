#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long int buf[110] = {1};
    for(int i = 0; i < n; i++){
        for(int j = i; j > 0; j--)
            buf[j] = buf[j] + buf[j - 1];
        for(int j = 0; j <= i; j++)
            cout<<buf[j]<<" ";
        cout<<endl;
    }
}
