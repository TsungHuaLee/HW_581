//注意0的時候
#include<stdio.h>
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
        int card_a[10]= {},card_b[10]= {},score_a=0,score_b=0;
        int num_a[10]= {},num_b[10]= {},num_c[10]= {};
        int i,j,k;

        for(i=0; i<6; i++)   //輸入卡牌a
        {
            scanf("%d",&card_a[i]);
            num_a[card_a[i]]++;   //看數字的個數
        }
//        for(i=0; i<10; i++)
//          printf("%d",num_a[i]);
        for(i=0; i<6; i++)   //輸入卡牌b
        {
            scanf("%d",&card_b[i]);
            num_b[card_b[i]]++;//看數字的個數
        }
//        for(i=0; i<10; i++)
//            printf("%d",num_b[i]);

        int fixed_num_a[10]= {},fixed_num_b[10]= {};

        for(i=0; i<10; i++)       //becauce the method of calculate,we set a fixed number of times
        {
            fixed_num_a[i]=num_a[i];
            fixed_num_b[i]=num_b[i];
        }
//        for(i=0; i<10; i++)
//           printf("%d\n",fixed_num_a[i]);
//        for(i=0; i<10; i++)
//            printf("%d\n",fixed_num_b[i]);
        int test,temp;

        for(i=0; i<1000000; i++)   //start to compare
        {
            test=i;   //test=question number
            for(j=0; j<10; j++)   //everytime recover the number of times
            {
                num_a[j]=fixed_num_a[j];
                //     printf("%d ",num_a[j]);
                num_b[j]=fixed_num_b[j];
                //     printf("%d",num_b[j]);
                //     printf("\n");
            }
//            for(i=0; i<10; i++)
//            printf("num_a=%d ",num_a[i]);
//            printf("\n");
//            for(i=0; i<10; i++)
//            printf("num_b=%d ",num_b[i]);
            int flaga=1,flagb=1;

            if(test==0)  //at beginning i==0
            {
                if(num_a[0]==0)
                    flaga=0;
                if(num_b[0]==0)
                    flagb=0;
            }
            while(test!=0)        //judge the flag
            {
                //      printf("test=%d\n",test);
                temp=test%10;
                num_a[temp]--;
                num_b[temp]--;
                if(num_a[temp]<0)
                {
                    flaga=0;
                }
                //  printf("num_a=%d ",num_a[temp]);
                if(num_b[temp]<0)
                {
                    flagb=0;
                }
                // printf("num_b=%d ",num_b[temp]);
                // printf("\n");
                test/=10;
            }
            //    printf("flaga=%d flagb=%d\n",flaga,flagb);
            if(flaga!=flagb)  // flaga==flagb --> all correct || all false
            {
                if(flaga==1)
                    score_a++;
                else
                    score_b++;

            }
        }
        printf("%d %d",score_a,score_b);
    }
}
