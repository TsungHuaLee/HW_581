#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
const int MAXCUTPOINT = 100;
int point[MAXCUTPOINT],fl,fr,flag;
int table[MAXCUTPOINT][MAXCUTPOINT];
int minCost(int left, int right);
//Precondition: left and right are the index in the point[i].
int main(){
    int length,numCut;
    while(cin>>length){
        if(!length)
            break;
        cin>>numCut;
        for(int i=0; i<MAXCUTPOINT; i++){
            point[i]=0;
            for(int j=0; j<MAXCUTPOINT; j++)
                table[i][j] = -1;
        }
        for(int i=1; i<=numCut; i++)
            cin>>point[i];

        point[0] = 0;
        point[numCut + 1] = length;
        flag = 1;
        cout<<minCost(0,numCut + 1)<<endl;
        for(int i=0; i<=numCut +1; i++){
            cout<<endl;
            for(int j=0; j<=numCut+1 ;j++)
                cout<<table[i][j]<<" ";}
    }
}
int minCost(int left, int right){
    if(left == right -1)  // 相鄰切點
        return 0;
    if(table[left][right] != -1)
        return table[left][right];
    int ans = MAX;
    for(int i = left + 1; i < right; i++){
        if(ans > (minCost(left, i) + minCost(i, right) + point[right] - point[left])){
            ans = minCost(left, i) + minCost(i, right) + point[right] - point[left];
        }
    }
    table[left][right] = ans;
    return table[left][right];
}
