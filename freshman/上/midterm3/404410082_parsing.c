#include<stdio.h>
#include<string.h>
int main()
{
    char input[1000]={},first=1;
    while(gets(input)!=NULL)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        char delimeter[]="  ,";
        char *start=input;
        int sum=0;
        start=strtok(start,delimeter);
        while(start!=NULL)
        {
            sum+=atoi(start);
            start=strtok(NULL,delimeter);
        }
        printf("%d",sum);
    }
}
