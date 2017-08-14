#include<stdio.h>
#include<string.h>
int main()
{
    char input[1000]={},first=1;
    while(scanf("%s",input)!=EOF)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        int i,j;
        int count=1;
        for(i=0;i<strlen(input);i++)
        {
            if(input[i]==input[i+1])
            {
                count++;
            }
            else
            {
                printf("%d%c",count,input[i]);
                count=1;   //RESET
            }
        }
    }
}
