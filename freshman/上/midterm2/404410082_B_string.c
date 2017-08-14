#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int ncase,first=1;
    scanf("%d\n",&ncase);
    while(ncase--)
    {
        if(first==1)
            first++;
        else
            printf("\n");
        char str[10000]= {0},coun[100][100]= {0};
        int length,asc=65,max_=0;
        int i,j;
        gets(str);//輸入 gets( )
        length=strlen(str);//長度 strlen(  )
        for(i=0; i<length; i++)
            str[i]=toupper(str[i]);//轉大寫 toupper//轉小寫 tolower
        for(i=1; i<=26; i++)//開一個陣列 代表a~~~z
        {
            coun[i][0]=asc;
            asc++;
        }
//        for(i=1;i<=26;i++)
//        {
//            printf("%c\n",coun[i][0])
//        }
        for(i=0; i<length; i++)   //count
            for(j=1; j<=26; j++)//j的1~~~26代表a~~~z
            {
                if(str[i]==coun[j][0])
                    coun[j][1]++;
            }
        for(j=1; j<=26; j++)     //find max count
        {
            if(max_<coun[j][1])
                max_=coun[j][1];
        }
        for(j=1;j<=26;j++)       //輸出
        {
            if(coun[j][1]==max_)
                printf("%c",coun[j][0]);
        }

    }
    return 0;
}
