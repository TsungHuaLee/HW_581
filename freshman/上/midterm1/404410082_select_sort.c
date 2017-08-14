#include<stdio.h>
int main()
{
    //freopen("out.txt","w+",stdout);
    int number,n[1000];
    int i,j,imin,k,temp,time,first=1;
    while(1)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        time=0;
        scanf("%d",&number);
        if(number==0)
            break;
        for(i=0; i<number; i++)
            scanf("%d",&n[i]);
        for(i=0; i<number-1; i++)
        {
            imin=i;
            for(j=i+1; j<number; j++)
            {
                if(n[j]<n[imin])
                    imin=j;
            }
            if(imin!=i)
            {
                temp=n[i];
                n[i]=n[imin];
                n[imin]=temp;
                time++;
            }

        }
        if(number>=3)
        {
            for(k=0; k<3; k++)
                printf("%d ",n[k]);
            printf("%d",time);
        }
        else
        {
            for(k=0; k<number; k++)
                printf("%d ",n[k]);
            printf("%d",time);
        }
    }
}
