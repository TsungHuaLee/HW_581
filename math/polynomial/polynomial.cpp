#include<iostream>
using namespace std;
//compute the coefficient of (ax^2 + bx + c)^d
int main(){
    int ncase;
    cin>>ncase;
    const int MAXLEN = 10000;
    while(ncase--){
        int coe[MAXLEN] = {}, oriCoe[MAXLEN] = {},power = 0;
        for(int i=2; i>=0; i--){
            cin>>coe[i];
            oriCoe[i] = coe[i];
        }
        cin>>power;

        for(int p = 2; p <= power ; p++){
            int tempCoe[MAXLEN]={};
            for(int i = 2*p; i >= 0 ; i--){
            // t[4] = c[4]*o[0] + c[3]*o[1] + c[2]*o[2] + c[1]*o[3] + c[0]*o[4]
                for(int j = i; j >= 0 ; j--)
                    tempCoe[i] += coe[j] * oriCoe[i-j];
            }
            for(int i=0; i <= 2*p; i++)
                coe[i] = tempCoe[i];
        }
        for(int i=2*power; i >= 0; i--)
            cout<<coe[i]<<" ";
        cout<<endl;
    }
}
