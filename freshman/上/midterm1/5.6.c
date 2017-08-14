#include<stdio.h>

int main()
{
    int year,month,day,date=0,i=0,t,j;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
    date=0;
    scanf("%d/%d/%d",&year,&month,&day);
    if(year<1970||month<1||month>12||day<1||day>31)
        printf("0\n");
    else if((month==4||month==6||month==9||month==11)&&day>30)
        printf("0\n");
    else if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31)
        printf("0\n");
    else if(month=2&&year%400==0&&day>29)
        printf("0\n");
    else if(month=2&&year%4==0&&year%100!=0&&day>29)
        printf("0\n");
    else if(month=2&&year%4!=0&&day>28)
        printf("0\n");
    else
    {
        for(i=1970; i<year; i++)
        {

            if(year%400!=0)
                if(year%4==0&&year%100!=0)
                    date+=366;
                else
                    date+=365;
            else
                date+=366;
        }
        //printf("%d",date);
        for(i=1; i<month; i++)
        {
            switch(i)
            {

            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                date+=31;
            case 4:case 6:case 9:case 11:
                date+=30;
            case 2:
                if(year%400!=0)
                    if(year%4==0&&year%100!=0)
                        date+=29;
                    else
                        date+=28;
                else
                    date+=29;
            }
        }
        date+=day;
        printf("%d\n",date);
    }

    }






}
