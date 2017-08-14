#include<iostream>
#include<cstdio>
#include<cmath> //abs
using namespace std;
int main()
{
        int ncase;
        cin>>ncase;
        while(ncase--)
        {
            int numPoint;
            cin>>numPoint;
            int xCoordinate[1000] = {},yCoordinate[1000] = {};
            for(int i = 0; i < numPoint; i++)
                cin>>xCoordinate[i]>>yCoordinate[i];
            int maxArea=0,area;
            for(int i=0;i<numPoint-1; i++)
               for(int j = i + 1; j < numPoint; j++)
                {
                  area = (xCoordinate[i] - xCoordinate[j]) * (yCoordinate[i]-yCoordinate[j]);
                  if(maxArea < abs(area))
                    maxArea = abs(area);
                }
            cout<<maxArea<<"\n";

        }
}
