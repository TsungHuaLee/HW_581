#include<stdio.h>
int horizon_losed(int color,const int chess[][20],int r,int c)
{
    int i,j;
    int count=0;
    for(i=0; i<5; i++)
    {
        if(c+i>19)
            break;
        if(color==chess[r][c+i])
            count++;
        else
            break;
    }
    if(count==5)
        return 1;
    else
        return 0;
}
int vertical_losed(int color,const int chess[][20],int r,int c)
{
    int i,j;
    int count=0;
    for(i=0; i<5; i++)
    {
        if(r+i>19)
            break;
        if(color==chess[r+i][c])
            count++;
        else
            break;
    }
    if(count==5)
        return 1;
    else
        return 0;
}
int right_obliqe_losed(int color,const int chess[][20],int r,int c)
{
    int i,j;
    int count=0;
    for(i=0; i<5; i++)
    {
        if((c+i>19)||(r+i>19))
            break;
        if(color==chess[r+i][c+i])
            count++;
        else
            break;
    }
    if(count==5)
        return 1;
    else
        return 0;
}
int left_oblique_losed(int color,const int chess[][20],int r,int c)
{
    int i,j;
    int count=0;
    for(i=0; i<5; i++)
    {
        if((r+i>19)||(c-i<1))
            break;
        if(color==chess[r+i][c-i])
            count++;
        else
            break;
    }
    if(count==5)
        return 1;
    else
        return 0;
}

int horizon_four(int color,const int chess[][20],int r,int c)
{
    int i,j;
    int count=0;
    for(i=0; i<4; i++)
    {
        if(c+i>19)
            break;
        if(color==chess[r][c+i])
            count++;
        else
            break;
    }
    if(count==4&&(chess[r][c-1]==0||chess[r][c+4]==0))
        return 1;
    else
        return 0;
}
int vertical_four(int color,const int chess[][20],int r,int c)
{
    int i,j;
    int count=0;
    for(i=0; i<4; i++)
    {
        if(r+i>19)
            break;
        if(color==chess[r+i][c])
            count++;
        else
            break;
    }
    if(count==4&&(chess[r-1][c]==0||chess[r+4][c]==0))
        return 1;
    else
        return 0;
}
int right_oblique_four(int color,const int chess[][20],int r,int c)
{
    int i,j;
    int count=0;
    for(i=0; i<4; i++)
    {
        if((c+i>19)||(r+i>19))
            break;
        if(color==chess[r+i][c+i])
            count++;
        else
            break;
    }
    if(count==4&&(chess[r+4][c+4]==0||chess[r-1][c-1]==0))
        return 1;
    else
        return 0;
}
int left_obilique_four(int color,const int chess[][20],int r,int c)
{
    int i,j;
    int count=0;
    for(i=0; i<4; i++)
    {
        if((r+i>19)||(c-i<1))
            break;
        if(color==chess[r+i][c-i])
            count++;
        else
            break;
    }
    if(count==4&&(chess[r+4][c-4]==0||chess[r-1][c+1]==0))
        return 1;
    else
        return 0;
}
int horizon_two_two(const int chess[][20],int r,int c)
{
    int i,j;
    if(c>15)
        return 0;
    if(chess[r][c]==chess[r][c+1]&&chess[r][c+2]==0&&chess[r][c]==chess[r][c+3]&&chess[r][c]==chess[r][c+4])
        return 1;
    else
        return 0;
}
int vertical_two_two(const int chess[][20],int r,int c)
{
    int i,j;
    if(r>15)
        return 0;
    if(chess[r][c]==chess[r+1][c]&&chess[r+2][c]==0&&chess[r][c]==chess[r+3][c]&&chess[r][c]==chess[r+4][c])
        return 1;
    else
        return 0;
}
int right_oblique_two_two(const chess[][20],int r,int c)
{
    int i;
    if(r>15||c>15)
        return 0;
    if(chess[r][c]==chess[r+1][c+1]&&chess[r+2][c+2]==0&&chess[r][c]==chess[r+3][c+3]&&chess[r][c]==chess[r+4][c+4])
        return 1;
    else
        return 0;
}
int left_oblique_two_two(const chess[][20],int r,int c)
{
    int i;
    if(r>15||c<5)
        return 0;
    if(chess[r][c]==chess[r+1][c-1]&&chess[r+2][c-2]==0&&chess[r][c]==chess[r+3][c-3]&&chess[r][c]==chess[r+4][c-4])
        return 1;
    else
        return 0;
}
int horizon_three_one(const chess[][20],int r,int c)
{
    int i;
    if(c>15)
        return 0;
    if(chess[r][c]==chess[r][c+1]&&chess[r][c]==chess[r][c+2]&&chess[r][c+3]==0&&chess[r][c]==chess[r][c+4])
        return 1;
    else
        return 0;
}
int vertical_three_one(const chess[][20],int r,int c)
{
    int i;
    if(r>15)
        return 0;
    if(chess[r][c]==chess[r+1][c]&&chess[r][c]==chess[r+2][c]&&chess[r][c+3]==0&&chess[r+4][c]==chess[r][c])
        return 1;
    else
        return 0;
}
int right_oblique_three_one(const chess[][20],int r,int c)
{
    int i;
    if(r>15||c>15)
        return 0;
    if(chess[r][c]==chess[r+1][c+1]&&chess[r][c]==chess[r+2][c+2]&&chess[r+3][c+3]==0&&chess[r][c]==chess[r+4][c+4])
        return 1;
    else
        return 0;
}
int left_oblique_three_one(const chess[][20],int r,int c)
{
    int i;
    if(r>15||c<5)
        return 0;
    if(chess[r][c]==chess[r+1][c-1]&&chess[r][c]==chess[r+2][c-2]&&chess[r+3][c-3]==0&&chess[r][c]==chess[r+4][c-4])
        return 1;
    else
        return 0;
}
int horizon_one_three(const chess[][20],int r,int c)
{
    int i;
    if(c>15)
        return 0;
    if(chess[r][c+1]==0&&chess[r][c]==chess[r][c+2]&&chess[r][c]==chess[r][c+3]&&chess[r][c]==chess[r][c+4])
        return 1;
    else
        return 0;
}
int vertical_one_three(const chess[][20],int r,int c)
{
    int i;
    if(r>15)
        return 0;
    if(chess[r+1][c]==0&&chess[r][c]==chess[r+2][c]&&chess[r][c]==chess[r][c+3]&&chess[r][c]==chess[r+4][c])
        return 1;
    else
        return 0;
}
int right_oblique_one_three(const chess[][20],int r,int c)
{
    int i;
    if(r>15||c>15)
        return 0;
    if(chess[r+1][c+1]==0&&chess[r][c]==chess[r+2][c+2]&&chess[r][c]==chess[r+3][c+3]&&chess[r][c]==chess[r+4][c+4])
        return 1;
    else
        return 0;
}
int left_oblique_one_three(const chess[][20],int r,int c)
{
    int i;
    if(r>15||c<5)
        return 0;
    if(chess[r+1][c-1]==0&&chess[r][c]==chess[r+2][c-2]&&chess[r][c]==chess[r+3][c-3]&&chess[r][c]==chess[r+4][c-4])
        return 1;
    else
        return 0;
}

int main()
{
    int ncase,first=1;
    scanf("%d",&ncase);
    while(ncase--)
    {
        if(first==1)
            first++;
        else
            printf("\n\n");
        int who_next,winner=0,condition=0,color;
        scanf("%d",&who_next);//1 = white  2= black
        int chess[20][20]= {};
        int r,c,i,j;
        int flag=0;
        for(i=1; i<=19; i++)
            for(j=1; j<=19; j++)
                scanf("%d",&chess[i][j]);
        for(r=1; r<=19; r++)
        {
            if(flag==1||flag==2||flag==3||flag==4)
                break;
            for(c=1; c<=19; c++)
            {
                if(chess[r][c]==0)
                    continue;
                if(flag==1||flag==2||flag==3||flag==4)
                    break;
               // printf("row=%d column=%d\n",r,c);
                color=1;  /////////////losed
                if(horizon_losed(color,chess,r,c))
                {
                    flag=1;
                    printf("1 2");
                    break;
                }
                else if(vertical_losed(color,chess,r,c))
                {
                    flag=1;
                    printf("1 2");
                    break;
                }
                else if(right_obliqe_losed(color,chess,r,c))
                {
                    flag=1;
                    printf("1 2");
                    break;
                }
                else if(left_oblique_losed(color,chess,r,c))
                {
                    flag=1;
                    printf("1 2");
                    break;
                }
                color=2;
                if(horizon_losed(color,chess,r,c))
                {
                    flag=1;
                    printf("1 1");
                    break;
                }
                else if(vertical_losed(color,chess,r,c))
                {
                    flag=1;
                    printf("1 1");
                    break;
                }
                else if(right_obliqe_losed(color,chess,r,c))
                {
                    flag=1;
                    printf("1 1");
                    break;
                }
                else if(left_oblique_losed(color,chess,r,c))
                {
                    flag=1;
                    printf("1 1");
                    break;
                }     ////////////////////////

                color=1;  /////////////2
                if(horizon_four(color,chess,r,c))
                {
                    if(who_next==1)
                    {
                        flag=2;
                        printf("2 ");
                        if(chess[r][c-1]==0)
                            printf("%d %d",r,c-1);
                        if(chess[r][c+4]==0)
                            printf("%d %d",r,c+4);
                        break;
                    }
                    else if(who_next==2)
                    {
                        if(chess[r][c-1]==0&&chess[r][c+4]==0)
                        {
                            flag=3;
                            printf("3");
                            break;
                        }
                        else if(chess[r][c+4]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r,c+4);
                            break;
                        }
                        else if(chess[r][c-1]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r,c-1);
                            break;
                        }
                    }
                }
                else if(vertical_four(color,chess,r,c))
                {
                    if(who_next==1)
                    {
                        flag=2;
                        printf("2 ");
                        if(chess[r-1][c]==0)
                            printf("%d %d",r-1,c);
                        if(chess[r+4][c]==0)
                            printf("%d %d",r+4,c);
                        break;
                    }
                    else if(who_next==2)
                    {
                        if(chess[r-1][c]==0&&chess[r+4][c]==0)
                        {
                            flag=3;
                            printf("3");
                            break;
                        }
                        else if(chess[r-1][c]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r-1,c);
                            break;
                        }
                        else if(chess[r+4][c]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r+4,c);
                            break;
                        }
                    }
                }
                else if(right_oblique_four(color,chess,r,c))
                {
                    if(who_next==1)
                    {
                        flag=2;
                        printf("2 ");
                        if(chess[r+4][c+4]==0)
                            printf("%d %d",r+4,c+4);
                        if(chess[r-1][c-1]==0)
                            printf("%d %d",r-1,c-1);
                        break;
                    }
                    else if(who_next==2)
                    {
                        if(chess[r+4][c+4]==0&&chess[r-1][c-1]==0)
                        {
                            flag=3;
                            printf("3");
                            break;
                        }
                        else if(chess[r-1][c-1]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r-1,c-1);
                            break;
                        }
                        else if(chess[r+4][c+4]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r+4,c+4);
                            break;
                        }
                    }
                }
                else if(left_obilique_four(color,chess,r,c))
                {
                    if(who_next==1)
                    {
                        flag=2;
                        printf("2 ");
                        if(chess[r+4][c-4]==0)
                            printf("%d %d",r+4,c-4);
                        if(chess[r-1][c+1]==0)
                            printf("%d %d",r-1,c+1);
                        break;
                    }
                    else if(who_next==2)
                    {
                        if(chess[r-1][c+1]==0&&chess[r+4][c-4]==0)
                        {
                            flag=3;
                            printf("3");
                            break;
                        }
                        else if(chess[r-1][c-1]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r-1,c+1);
                            break;
                        }
                        else if(chess[r+4][c-4]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r+4,c-4);
                            break;
                        }
                    }
                }
                color=2;  /////////////2
                if(horizon_four(color,chess,r,c))
                {
                    if(who_next==2)
                    {
                        flag=2;
                        printf("2 ");
                        if(chess[r][c-1]==0)
                            printf("%d %d",r,c-1);
                        if(chess[r][c+4]==0)
                            printf("%d %d",r,c+4);
                        break;
                    }
                    else if(who_next==1)
                    {
                        if(chess[r][c-1]==0&&chess[r][c+4]==0)
                        {
                            flag=3;
                            printf("3");
                            break;
                        }
                        else if(chess[r][c+4]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r,c+4);
                            break;
                        }
                        else if(chess[r][c-1]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r,c-1);
                            break;
                        }
                    }
                }
                else if(vertical_four(color,chess,r,c))
                {
                    if(who_next==2)
                    {
                        flag=2;
                        printf("2 ");
                        if(chess[r-1][c]==0)
                            printf("%d %d",r-1,c);
                        if(chess[r+4][c]==0)
                            printf("%d %d",r+4,c);
                        break;
                    }
                    else if(who_next==1)
                    {
                        if(chess[r-1][c]==0&&chess[r+4][c]==0)
                        {
                            flag=3;
                            printf("3");
                            break;
                        }
                        else if(chess[r-1][c]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r-1,c);
                            break;
                        }
                        else if(chess[r+4][c]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r+4,c);
                            break;
                        }
                    }
                }
                else if(right_oblique_four(color,chess,r,c))
                {
                    if(who_next==2)
                    {
                        flag=2;
                        printf("2 ");
                        if(chess[r+4][c+4]==0)
                            printf("%d %d",r+4,c+4);
                        if(chess[r-1][c-1]==0)
                            printf("%d %d",r-1,c-1);
                        break;
                    }
                    else if(who_next==1)
                    {
                        if(chess[r+4][c+4]==0&&chess[r-1][c-1]==0)
                        {
                            flag=3;
                            printf("3");
                            break;
                        }
                        else if(chess[r-1][c-1]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r-1,c-1);
                            break;
                        }
                        else if(chess[r+4][c+4]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r+4,c+4);
                            break;
                        }
                    }
                }
                else if(left_obilique_four(color,chess,r,c))
                {
                    if(who_next==2)
                    {
                        flag=2;
                        printf("2 ");
                        if(chess[r+4][c-4]==0)
                            printf("%d %d",r+4,c-4);
                        if(chess[r-1][c+1]==0)
                            printf("%d %d",r-1,c+1);
                        break;
                    }
                    else if(who_next==1)
                    {
                        if(chess[r-1][c+1]==0&&chess[r+4][c-4]==0)
                        {
                            flag=3;
                            printf("3");
                            break;
                        }
                        else if(chess[r-1][c-1]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r-1,c+1);
                            break;
                        }
                        else if(chess[r+4][c-4]==0)
                        {
                            flag=4;
                            printf("4 %d %d",r+4,c-4);
                            break;
                        }
                    }
                }///////
                if(horizon_two_two(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r][c+2]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r][c+2]);
                        break;
                    }
                }
                else if(vertical_two_two(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+2][c]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+2][c]);
                        break;
                    }
                }
                else if(right_oblique_two_two(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+2][c+2]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+2][c+2]);
                        break;
                    }
                }
                else if(left_oblique_two_two(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+2][c-2]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+2][c-2]);
                        break;
                    }
                }
                if(horizon_three_one(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r][c+3]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r][c+3]);
                        break;
                    }
                }
                else if(vertical_three_one(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+3][c]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+3][c]);
                        break;
                    }
                }
                else if(right_oblique_three_one(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+3][c+3]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+3][c+3]);
                        break;
                    }
                }
                else if(left_oblique_three_one(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+3][c-3]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+3][c-3]);
                        break;
                    }
                }
                if(horizon_one_three(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r][c+1]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r][c+1]);
                        break;
                    }
                }
                else if(vertical_one_three(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+1][c]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+1][c]);
                        break;
                    }
                }
                else if(right_oblique_one_three(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+1][c+1]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+1][c+1]);
                        break;
                    }
                }
                else if(left_oblique_one_three(chess,r,c))
                {
                    if(who_next==chess[r][c])
                    {
                        flag=2;
                        printf("2 %d %d",chess[r+1][c-1]);
                        break;
                    }
                    else
                    {
                        flag=4;
                        printf("4 %d %d",chess[r+3][c-3]);
                        break;
                    }
                }

            }

        }
    }
}
