#include<stdio.h>
int main()
{
    int number,first=1;
    while(scanf("%d",&number)!=EOF)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        int ans[3000]= {1},flag=0;
        int i,j;
        if(number==0)
            printf("%d!\n1",number);
        else if(number==1)
            printf("%d!\n1",number);//  0! 1! are special case
        else
        {
            for(i=1; i<=number; i++)
            {
                for(j=0; j<3000; j++)
                {//*1 *2.......*number
                    ans[j]*=i;
                }
                for(j=0; j<3000; j++) //進位
                {
                    ans[j+1]+=(ans[j]/10);
                    ans[j]%=10;
                  //  printf("%d ",ans[j]);
                }
            }
//        for(j=0; j<3000; j++)
//            printf("%d",ans[j]);
            printf("%d!\n",number);
            for(i=2999; i>=0; i--)  //warning!!!!  not from 3000  because we call ans[0]~ans[2999] don't have ans[3000]
            {
                if(ans[i]!=0||flag==1)
                {
                    flag = 1;
                    printf("%d",ans[i]);
                }
            }
        }
    }
}
