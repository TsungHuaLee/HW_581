#include<stdio.h>
#include<string.h>
int main()
{
    while(1)
    {
        int squre,power,divide,binary_power;
        scanf("%d%d%d",&squre,&power,&divide);
        if(squre==0&&power==0&&divide==0)
        {
            break;
        }
        long long int matrix[6][6]= {},temp[6][6]= {},ans[6][6]= {},ans_temp[6][6]= {};
        int i,j,k,t;
        for(i=1; i<=squre; i++)
            for(j=1; j<=squre; j++)
                scanf("%lld",&matrix[i][j]);

        for(i=1; i<=squre; i++)    //set ans = I
            for(j=0; j<=squre; j++)
            {
                if(i==j)
                    ans[i][j]=1;
                else
                    ans[i][j]=0;
            }

        for(t=0; t<=32; t++)    //t=1  binary system t =2的t次方
        {
            //t=1  binary_power=2的1次方
            binary_power=power%2;
            power/=2;  //prepare for next round
            if(t!=0)
            {
                for(i=1; i<=squre; i++)
                    for(j=1; j<=squre; j++)
                    {
                        temp[i][j]=0;
                        for(k=1; k<=squre; k++)
                        {
                            temp[i][j]=(temp[i][j]+(matrix[i][k]*matrix[k][j])%divide)%divide;
                        }
                    }

                for(i=1; i<=squre; i++)
                    for(j=1; j<=squre; j++)
                        matrix[i][j]=temp[i][j];
                //test
//                printf("t=%d\n",t);
//                for(i=1; i<=squre; i++)
//                {
//                    for(j=1; j<=squre; j++)
//                    {
//                        if(j!=1)
//                            printf(" ");
//                        printf("%lld",matrix[i][j]);
//                    }
//                    printf("\n");
//                }
//                printf("\n");
            }
            //after prepare binary power ans matrix
            if(binary_power==1)
            {
                for(i=1; i<=squre; i++)
                    for(j=1; j<=squre; j++)
                    {
                        ans_temp[i][j]=0;
                        for(k=1; k<=squre; k++)
                        {
                            ans_temp[i][j]=(ans_temp[i][j]+(ans[i][k]*matrix[k][j])%divide)%divide;
                        }
                    }

                for(i=1; i<=squre; i++)
                    for(j=1; j<=squre; j++)
                        ans[i][j]=ans_temp[i][j];
            }

        }
        for(i=1; i<=squre; i++)
        {
            for(j=1; j<=squre; j++)
            {
                if(j!=1)
                    printf(" ");
                printf("%lld",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
