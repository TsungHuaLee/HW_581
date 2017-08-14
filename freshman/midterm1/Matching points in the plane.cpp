#include<iostream>
#include<algorithm>//sort
#include<math.h>//abs pow sqrt
#include<sstream>//stringstream
#include<string>
using namespace std;
int main()
{
    int ncase;
    cin>>ncase;
    cin.ignore();
    while(ncase--)
    {
        string xLine,yLine;
        getline(cin,xLine);
        int xCoordinate[1100] = {};
        istringstream xinput(xLine);
        int numX = 0;
        while(xinput>>xCoordiante[numX])
        {
            numX++;
        }
        getline(cin,yLine);
        istringstream yinput(yLine);
        int yCoordinate[1100] = {};
        int numY = 0;
        while(yinput>>yCoordinate[numY])
        {
            numY++;
        }//x==y
        for(int i = 0; i < numX; i++)
        {
            xCoordinate[i] = abs(xCoordinate[i]);
            yCoordinate[i] = abs(yCoordinate[i]);
        }
        sort(xCoordinate,xCoordinate+numX);
        sort(yCoordinate,yCoordinate+numY);
        long double sum=0;
        for(int i = 0; i < numX; i++)
        {
            sum += sqrt(pow(x_coor[i],2)+pow(y_coor[y-i-1],2));//biggest Y to  smallest X
        }
        cout<<(int)sum<<"\n";
    }
}
