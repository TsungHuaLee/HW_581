#include<stdio.h>
#include<math.h>
int main()
{
    int number,search_times,coor[30000][5]= {0};
    int flag,dx,dy,dis,min_dis,sum;
    int i,j,times,first=1;
    scanf("%d",&times);
    while(times--)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        scanf("%d",&number);
        for(i=1; i<=number; i++)
            scanf("%d%d",&coor[i][0],&coor[i][1]);//輸入x y座標
        sum=0;
        coor[0][0]=0;//初始為原點
        coor[0][1]=0;//初始為原點
        search_times=number;
        int judge[30000]= {0};
        while(search_times--)
        {
            min_dis=500000;
            for(i=1; i<=number; i++) //找出最近的點
            {

                if(judge[i]==1)//去過 找別處
                    continue;
//////                  printf("i=%d ",i);
//////                  printf("x=%d y=%d\n",coor[0][0],coor[0][1]);
                dx=abs(coor[i][0]-coor[0][0]);//把coor[0][0]當成每次出發的x座標
                dy=abs(coor[i][1]-coor[0][1]);//把coor[0][1]當成每次出發的y座標
                dis=dx+dy;
//               printf("dx=%d dy=%d dis=%d\n",dx,dy,dis);
                if(min_dis>dis)
                {
                    min_dis=dis;
                    flag=i;//記下最小點在哪
                }
            }
            coor[0][0]=coor[flag][0];//flag記下的點 將是下一筆的出發點
            coor[0][1]=coor[flag][1];//
            judge[flag]=1;//標記去過的點
//            for(j=1; j<=number; j++)
//                printf("test2 %d %d\n",coor[j][0],coor[j][1]);
            sum+=min_dis;

//              printf("sum=%d\n",sum);
        }
        printf("%d",sum);
    }
}
