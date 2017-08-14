#include<stdio.h>
int main()
{
    int x,time,i,j,max,ans1,ans2,temp;
    while(1)
    {
        scanf("%d%d",&i,&j);
        ans1=i,ans2=j,max=0;
        if(i>j)
        {
            temp=i;
            i=j;
            j=temp;
        }
        if(i==0||j==0)
            break;
        while(i<=j)
        {
            x=i,time=1;
            while(x!=1)
            {
                if(x%2!=0)
                    x=3*x+1;
                else
                    x=x/2;
                time++;
            }

            if(max<time)
                max=time;
            i++;
        }
        printf("%d %d %d",ans1,ans2,max);
        printf("\n");
    }
}
