#include<stdio.h>
int main()
{
    int x,y,k,n,i,output;
    while(1)
    {
        scanf("%d",&x);
        if(x==0)
            break;
        scanf("%d%d",&y,&n);
        k=1;
        if(x>n)
              x=x%n;
        for(y=y; y>0; y--)
        {
            k=k*x;
            k=k%n;
        }
        output=k;
        printf("%d\n",output);
    }
}
