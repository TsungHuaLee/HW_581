#include<stdio.h>
int main()
{
    int syear,smon,sdate,difd=0,i,j,k,l;
    scanf("%d",&k);
    for(l=0; l<k; l++)/*����k��*/
    {
        scanf("%d/%d/%d",&syear,&smon,&sdate); /*��J�~(scanf year)��(scanf month)��(scanf date)*/
        if((syear<1970)||(smon>12)||(sdate>31)||(smon<1)||(sdate<1)) /*���i�H�p��1970�~,�j��12��,�j��31��,�p��@��*/
        {
            printf("0\n");
        }
        else if (((syear%400==0)||((syear%4==0)&&(syear%100!=0)))&&((smon==2)&&(sdate>29)))/*���i�H�b�|�~��2��W�L29��*/
        {
            printf("0\n");
        }
        else if (((syear%4!=0)||((syear%100==0)&&(syear%400!=0)))&&((smon==2)&&(sdate>28)))/*���~���i�H�W�L28��*/
        {
            printf("0\n");
        }
        else if(((smon==4)||(smon==6)||(smon==9)||(smon==11))&&(sdate>30))
            printf("0\n");
        else if(syear==1970)/*�p�G�O1970�~����*/
        {
            for(j=0; j<smon; j++)/*�q��J������W�Ӥ�ѼƤ@���[��@��Ѽ�*/
            {
                switch(j) /*�C�Ӥ�����Ѽ�*/
                {
                case 0:
                    difd=difd+0;  /*difd�O(different day)�ۮt�Ѽ�*/
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
                        difd=(difd+28); /*�ۮt�`�Ѽ�*/
                }
                break;




                }
            }
            difd=difd+sdate;
            printf("%d\n",difd);
            difd=0;




        }
        else/*���O1970�~����*/
        {
            for(i=1970; i<syear; i++)/*�q1971�~�@�[���J������e�@�Ӥ�*/
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
