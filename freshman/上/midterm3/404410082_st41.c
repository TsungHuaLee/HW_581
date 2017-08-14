#include<stdio.h>
#include<string.h>
int main()
{
    int ncase,first=1;
    scanf("%d\n",&ncase);  //  remember "\n"!!!!!!
    while(ncase--)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        char string1[99999]= {},string2[99999]= {},string3[99999]= {};
        int i,j,length=0,now=0,same=1;
        gets(string1);
        gets(string2);
        gets(string3);
        length=strlen(string2);
        for(i=0; i<strlen(string1); i++)
        {
            if(string1[i]!=string2[0])  //print-->until the first alphabet are same
                printf("%c",string1[i]);

            else if(string1[i]==string2[0])
            {
                for(j=i; j<i+length; j++)  //judge the word are same??
                {
                    if(string1[j]==string2[now])
                       {
                           same=1;
                           now++;
                       }
                    else
                    {
                        same=0;
                        break;
                    }
                }
                if(same==1)  //they are same
                {
                    printf("%s",string3);
                    i+=length-1;
                    now=0;  //reset
                }
                else
                {
                    printf("%c",string1[i]);
                    now=0;  //reset
                }
            }
        }
    }
}
