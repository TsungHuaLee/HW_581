#include<stdio.h>
int main ()
{
    int number,m,n[10];
    int i,times,count,first=1;
    while (scanf("%d%d",&number,&m)!=EOF) // 沒有明確測資數 卻有n筆case-->!=EOF
    {
        if(first==1)
            first++;
        else
            printf("\n");
        for(i=1; i<=7; i++)
        {
            n[i]=m%10;
            m/=10;
        }
//        for(i=7;i>=1;i--)
//            printf("%d",n[i]);
        count=0;
        for(i=7; i>=1; i--)
        {
            if(number==(n[i]*10+n[i-1]))
                count++;
        }
        printf("%d",count);
    }
    return 0;
}
