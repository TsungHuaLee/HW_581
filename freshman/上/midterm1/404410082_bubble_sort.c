#include<stdio.h>
int main()
{
    int m,n[1000];
    int i,temp,j,first=1;
    while(1)
    {
        if(first==1)
            first+=1;
        else
            printf("\n");
        int times=0;
        scanf("%d",&m);
        if(m==0)
            break;
        for(i=0; i<m; i++)
            scanf("%d",&(n[i]));
        for(i=m-1; i>=0; i--)//從 m - 1 放 到 1
            for(j=0; j<i; j++)
                if(n[j]>n[j+1])
                {
                    temp=n[j];
                    n[j]=n[j+1];
                    n[j+1]=temp;
                    times++;
                }
        printf("%d",times);
    }
    return 0;
}
