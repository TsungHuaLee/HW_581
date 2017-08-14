#include<stdio.h>
int main()
{
    int n[100000],number,result;
    int i,j,temp,space=1,times,first=1;
    scanf("%d",&times);
    while(times--)
    {
        if(first==1)
            first++;
        else
            printf("\n\n");
        i=0;

        while(1)//輸入數字值到-999出現
        {
            scanf("%d",&n[i]);
            if(n[i]==-999)
            {
                number=i;//表示有0~i-1個數
                break;
            }
            else
                i++;
        }
//    for(i=0;i<number;i++)
//        printf(" %d\n",n[i]);
//    printf("number=%d\n",number);
        for(i=number; i>=0; i--) //大的放前面 bubble_sort
            for(j=0; j<i; j++)
            {
                if(n[j]<n[j+1])
                {
                    if(n[j+1]==-999)//當n[j+1]==-999-->代表已到最後一筆 因為可能數字比-999小
                        break;
                    else
                    {
                        temp=n[j];
                        n[j]=n[j+1];
                        n[j+1]=temp;
                    }
                }
            }
        //for(i=0; i<=number; i++)
        //    printf("%d",n[i]);
        space=1;
        result=1;
        for(i=0; i<number; i++)
        {
            if(n[i]==n[i+1])//記得是==
                result++;
            else //if(n[i]!=n[i+1])
            {
                if(space==1)//判斷換行
                    space++;
                else
                    printf("\n");
                printf("%d",n[i]);
                printf(" %d",result);
                //     printf(" %d",n[i+1]);
                result=1;
            }
        }
    }
    return 0;
}
