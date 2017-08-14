#include<stdio.h>
int re(int number)
{
    int reverse=0;
    while(number!=0)
    {
        reverse=reverse*10+number%10;
        number/=10;
    }
    return reverse;
}




int main()
{
    int number,reverse,count;
    int i,ncase,first=1;
    scanf("%d",&ncase);
    while(ncase--)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        scanf("%d",&number);
        reverse=re(number);
        count=0;
        while(number!=reverse)
        {
            number+=reverse;
            reverse=re(number);
            count++;
        }
        printf("%d %d",count,reverse);
    }
}
