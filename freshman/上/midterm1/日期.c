#include<stdio.h>
int main()
{
    int syear,smon,sdate,difd=0,i,j,k,l;
    scanf("%d",&k);
    for(l=0; l<k; l++)/*重複k次*/
    {
        scanf("%d/%d/%d",&syear,&smon,&sdate); /*輸入年(scanf year)月(scanf month)日(scanf date)*/
        if((syear<1970)||(smon>12)||(sdate>31)||(smon<1)||(sdate<1)) /*不可以小於1970年,大於12月,大於31天,小於一月*/
        {
            printf("0\n");
        }
        else if (((syear%400==0)||((syear%4==0)&&(syear%100!=0)))&&((smon==2)&&(sdate>29)))/*不可以在閏年的2月超過29天*/
        {
            printf("0\n");
        }
        else if (((syear%4!=0)||((syear%100==0)&&(syear%400!=0)))&&((smon==2)&&(sdate>28)))/*平年不可以超過28天*/
        {
            printf("0\n");
        }
        else if(((smon==4)||(smon==6)||(smon==9)||(smon==11))&&(sdate>30))
            printf("0\n");
        else if(syear==1970)/*如果是1970年的話*/
        {
            for(j=0; j<smon; j++)/*從輸入月分的上個月天數一直加到一月天數*/
            {
                switch(j) /*每個月分的天數*/
                {
                case 0:
                    difd=difd+0;  /*difd是(different day)相差天數*/
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    difd=difd+31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    difd=difd+30;
                    break;
                case 2 :
                {
                    if ((syear%400==0)||((syear%4==0)&&(syear%100!=0)))
                        difd=(difd+29);
                    else
                        difd=(difd+28); /*相差總天數*/
                }
                break;




                }
            }
            difd=difd+sdate;
            printf("%d\n",difd);
            difd=0;




        }
        else/*不是1970年的話*/
        {
            for(i=1970; i<syear; i++)/*從1971年一加到輸入日期的前一個月*/
            {
                if((i%400==0)||((i%4==0)&&(i%100!=0)))
                    difd=difd+366;
                else
                    difd=difd+365;
            }
            for(j=smon-1; j>=0; j--)
            {
                switch(j)
                {
                case 0:
                    difd=difd+0;
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    difd=difd+31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    difd=difd+30;
                    break;
                case 2 :
                    if ((syear%400==0)||((syear%4==0)&&(syear%100!=0)))
                        difd=(difd+29);
                    else
                        difd=difd+28;
                    break;
                }
            }
            difd=difd+sdate;
            printf("%d\n",difd);
            difd=0;
        }




    }
}
