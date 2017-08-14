#include<stdio.h>
int main()
{
    int student,rank;
    int score_a[1001],score_b[1001],score_c[1001],sum_score[3001];
    int i,j,temp,times,first=1;
    scanf("%d",&times);
    while(times--)
    {
        if(first==1)
            first++;
        else
            printf("\n\n");
    double average_a=0,average_b=0,average_c=0;
    scanf("%d%d",&student,&rank);
    for(i=1; i<=student; i++)
        scanf("%d%d%d",&score_a[i],&score_b[i],&score_c[i]);
    for(i=1; i<=student; i++)
        sum_score[i]=score_a[i]+score_b[i]+score_c[i];
    for(i=1; i<student; i++)  //bubble sort  從1開始存
        for(j=student; j>1; j--)
            if(sum_score[j]>sum_score[j-1])//分數高存前面
            {
                temp=sum_score[j];
                sum_score[j]=sum_score[j-1];
                sum_score[j-1]=temp;

                temp=score_a[j];
                score_a[j]=score_a[j-1];
                score_a[j-1]=temp;

                temp=score_b[j];
                score_b[j]=score_b[j-1];
                score_b[j-1]=temp;

                temp=score_c[j];
                score_c[j]=score_c[j-1];
                score_c[j-1]=temp;

            }
    for(i=1; i<=student; i++)
    {
        average_a+=(double)score_a[i]/student;//(double)轉換型態
        average_b+=(double)score_b[i]/student;
        average_c+=(double)score_c[i]/student;
    }
    for(i=1; i<=rank; i++)
    {
        printf("%d %d %d %d\n",score_a[i],score_b[i],score_c[i],sum_score[i]);
    }
        printf("%0.2f %0.2f %0.2f",average_a,average_b,average_c);
    }
//for(i=1;i<=student;i++)
//    printf("%d ",sum_score[i]);

}
