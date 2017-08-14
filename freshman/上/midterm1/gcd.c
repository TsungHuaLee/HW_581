#include<stdio.h>

int main()
{
   int x,y,temp,i,t,j;
    scanf("%d%d",&x,&y);
    if(x<y)
       {
        temp=x;
        x=y;
        y=x;
        }
     while(x%y!=0)
     {
       i=x%y;
       x=y;
       y=i;
     }
     printf("%d\n",y);

}
