#include<stdio.h>
int main()
{
    int na[1001],nb[1001],ans[3000];
    int numa,numb,count;
    int i,ka,kb,kc,j,times,t,first=1;
    scanf("%d",&times);
    for(t=0; t<times; t++)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        scanf("%d%d",&numa,&numb);//輸入測資
        for(i=1; i<=numa; i++)
            scanf("%d",&na[i]);
        for(i=1; i<=numb; i++)
            scanf("%d",&nb[i]);
        ka=1,kb=1,kc=1,count=0;
        while(ka<numa+1&&kb<numb+1)
        {
            if(na[ka]<=nb[kb])
                ans[kc++]=na[ka++];
            else
                ans[kc++]=nb[kb++];
            count++;
        }
        if(ka<=numa)
            while(ka<=numa)
                ans[kc++]=na[ka++];
        if(kb<=numb)
            while(kb<=numb)
                ans[kc++]=nb[kb++];
        printf("%d\n",count);
        if(numa+numb<=6)
            for(j=1; j<=numa+numb; j++)
            {
                printf("%d",ans[j]);
                if(j<numa+numb)
                    printf(" ");
            }
        else
        {
            for(j=1; j<=3; j++)
                printf("%d ",ans[j]);
            for(j=numa+numb-2; j<=numa+numb; j++)
            {
                printf("%d",ans[j]);
                if(j<numa+numb)
                    printf(" ");
            }
        }

    }
//     for(i=1;i<kc;i++)
//                 printf("%d",ans[i]);
}
