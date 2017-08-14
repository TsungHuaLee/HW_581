#include<stdio.h>

int main(void)
{
    int number,how_many_answer;
    int a[100001],sum[100001]={},left[1001],right[1001];
    int i,j,temp;
    scanf("%d%d",&number,&how_many_answer);//輸入n k
    for(i=1; i<=number; i++)
        scanf("%d",&a[i]);//輸入n個數字
    for(i=1; i<=how_many_answer; i++)
        scanf("%d%d",&left[i],&right[i]);//輸入加的範圍
    for(i=1; i<=how_many_answer; i++) //左邊範圍小  右邊範圍大
        if(left[i]>right[i])
        {
            temp=left[i];
            left[i]=right[i];
            right[i]=temp;
        }
    for(i=1; i<=how_many_answer; i++)
    {
        for(j=left[i]; j<=right[i]; j++)
            sum[i]+=a[j];
        printf("%d",sum[i]);
        if(i<how_many_answer)
                printf("\n");
    }
}
