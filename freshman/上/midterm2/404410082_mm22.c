#include<stdio.h>
#include<math.h>
typedef long long ll;//定 義 long long -->ll
int main()
{

    ll times;

    scanf("%lld",&times);
    while(times--)
    {
        ll number;
        scanf("%lld",&number);
        ll m[number],num[number],difference;//技巧-->陣列的大小決定於輸入的值
        ll i;
        for(i=0; i<number; i++)
        {
            scanf("%lld",&num[i]);
            m[i]=0;//歸0
        }
        if(number==1)//只有1個數字一定是jolly
            printf("Jolly\n");
        for(i=0; i<number-1; i++)
        {
            difference=abs(num[i]-num[i+1]);//算差
           // temp=difference;
         //   printf("dif=%lld\n",difference);
         //   printf("yee%d %d",i,n[i+1]);
            if(difference>number-1||difference<1||m[difference]==1)//注意放的順序 m[difference]放後面
            {
                printf("Not jolly\n");
                break;
            }
            else
            {
            //    printf("sdf");
                ++m[difference];
            }
            if(i==number-2)
                printf("Jolly\n");
        }
        //printf("i=%lld",i);



//        for(i=1; i<=number-1; i++)
//        {
//            temp=difference[i];
//            m[temp]++;
//        }
//        judge=1;
//        for(i=1; i<=number-1; i++)
//        {
//            if(m[i]!=1)
//                judge=0;
//        }
//        if(judge==1)
//            printf("Jolly");
//        else
//            printf("Not jolly");
    }
    return 0;

}
