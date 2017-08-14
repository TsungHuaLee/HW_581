#include<stdio.h>
#include<string.h>
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
        int how_many=0,number[1000]= {};
        scanf("%d",&how_many);
        int i,j,k;
        for(i=0; i<how_many; i++)
            scanf("%d",&number[i]);
        int max=0,temp,count=0;
        for(i=0; i<how_many; i++) //find out max hamming
            for(j=0; j<how_many; j++)
            {
                count=0;  //reset
                temp=number[i]^number[j];  //XOR
                while(temp!=0)
                {
                    count+=temp%2;
                    temp/=2;
                }
                if(count>max)
                    max=count;
            }
        printf("%d",max);

    }
    return 0;
}

