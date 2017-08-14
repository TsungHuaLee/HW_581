#include<stdio.h>
#include<string.h>
int main()
{
    char input[999999]= {};
    int first=1;
    while(scanf("%s",input)!=EOF)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        char pattern[999999]= {};
        int number=0;
        int i,j,flag=0;
        for(i=0; i<strlen(input); i++)
        {
            if((input[i]<'0'||input[i]>'9')&&(input[i+1]>'0'&&input[i+1]<'9')||(input[i+1]=='\0'))  //input[i] is alphabet  input[i+1] is number
            {
                pattern[flag]=input[i];
                for(j=0; j<number; j++)
                    printf("%s",pattern);
                number=0;                //reset
                for(j=0; j<999999; j++)
                    pattern[j]=0;        //reset
                flag=0;
            }
            else if(input[i]>'0'&&input[i]<'9')  //input[i] is number
            {
                number=number*10+input[i]-'0';
                // printf("number=%d\n",number);
            }
            else
            {
                pattern[flag]=input[i];
                flag++;
            }
        }
    }
}
