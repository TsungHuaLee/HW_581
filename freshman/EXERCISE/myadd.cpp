#include<iostream>
#include<cstdlib>
#define zero 0
#define one 1
using namespace std;
int main(int argc,char *argv[])
{
    double sum=zero;
    for(int i=one;i<argc;i++)
        sum+=atof(argv[i]);
    cout<<sum<<"\n";
    return 0;
}
