#include<stdio.h>
#include<string.h>
int main()
{
    int ncase,first=1;
    scanf("%d",&ncase);
    while(ncase--)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        char number1[40]= {},number2[40]= {},ans[40]={};
        int m1[40]= {},m2[40]= {},sum[40]= {},sum_len;
        int i,j;
        scanf("%s",number1);
        scanf("%s",number2);
        for(i=0; i<strlen(number1); i++) ////!!range
            m1[strlen(number1)-i-1]=number1[i]-'0';
        for(i=0; i<strlen(number2); i++)
            m2[strlen(number2)-i-1]=number2[i]-'0';
//        for(i=0; i<strlen(number1); i++)
//            printf("%d",m1[i]);
//        printf("\n");
//        for(i=0; i<strlen(number2); i++)
//            printf("%d",m2[i]);
        if(strlen(number1)>strlen(number2))
            sum_len=strlen(number1);
        else
            sum_len=strlen(number2);

        for(i=0;i<sum_len;i++)
            sum[i]=m1[i]+m2[i];

        for(i=0;i<sum_len;i++)
        {
            sum[i+1]+=(sum[i]/10);
            sum[i]%=10;
        }
        int flag=0;
        for(i=39;i>=0;i--)
        {
            if(sum[i]!=0||flag==1)
            {
                flag=1;
                printf("%d",sum[i]);
            }
        }
    }
    return 0;
}
