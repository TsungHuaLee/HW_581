#include<stdio.h>
#include<string.h>
#define MAX 1025

int main()
{
    int times;
    int coe[10250]= {0},ori_coe[10250]= {0},ans_coe[10250]= {0},power,max_power;
    int i,j,k,first=1;
    scanf("%d",&times);
    while(times--)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        for(i=0; i<=1025; i++)//每筆都要歸0
        {
            coe[i]=0;
            ori_coe[i]=0;
            ans_coe[i]=0;
        }
//        memset(coe,0x00,sizeof(int)*MAX);
//        memset(ori_coe,0x00,sizeof(int)*MAX);
//        memset(ans_coe,0x00,sizeof(int)*MAX);
        //ori_coe[1025]={0};ans_coe[1025]={0};<--不能在宣告外的地方做
        for(i=2; i>=0; i--)//輸入係數
            scanf("%d",&coe[i]);
        scanf("%d",&power);//輸入次方
        for(i=2; i>=0; i--)//設定一個不變的   要一直*
            ori_coe[i]=coe[i];
        if(power==1)
            max_power=2;
        else
            max_power=4;
        for(k=1; k<power; k++)//算要乘自己幾次
        {
            for(i=max_power; i>=0; i--)//從次方大係數的去算
            {
                for(j=i; j>=0; j--)//4次方例子  c[4]*c[0]+c[3]*c[1]+c[2]*c[2]+c[1]+c[3]
                {
                    ans_coe[i]+=coe[j]*ori_coe[i-j];
                    //printf("(%d)%d\n",i,coe[i]);
                }
            }
            for(i=max_power; i>=0; i--)//把目前的存回去 下一次要用
                coe[i]=ans_coe[i];
            for(i=0; i<=1025; i++)
                ans_coe[i]=0;//在歸0
            if(k<power-1)//因為最後一次是power-1
                max_power+=2;
        }

        for(i=max_power; i>=0; i--)
        {
            printf("%d",coe[i]);
            if(i>0)
                printf(" ");
        }
    }
    return 0;
}







