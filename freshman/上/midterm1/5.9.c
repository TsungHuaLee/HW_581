#include<stdio.h>
int main()
{
    int number,i,power,test,j;
    scanf("%d",&test);
    for(j=0; j<test; j++)
    {
        scanf("%d",&number);
        for(i=2; i*i<=number; i++)
        {
            power=0;
            while(number%i==0)
            {
                power++;
                number/=i;
            }
            if(power!=0)
                printf("%d\n%d\n",i,power);
        }
        if(number!=1)
            printf("%d\n1",number);
          if(j!=test-1)
            printf("\n\n");
    }
}
