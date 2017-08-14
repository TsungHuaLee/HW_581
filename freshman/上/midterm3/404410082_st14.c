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
        char str[40][300]= {},ans_str[300]= {},compare_str[300]= {};
        int number_string=0,overlap=0;
        int i,j,k;
        scanf("%d",&number_string);
        for(i=0; i<number_string; i++)
            scanf("%s",str[i]);
        strcpy(ans_str,str[0]);

        for(i=1; i<number_string; i++) //connect number_of_string ex:3串做2次
        {
            strcpy(compare_str,str[i]);
            if(strlen(ans_str)<strlen(compare_str))
                overlap=strlen(ans_str);  //assume length of overlap is shorter one
            else
                overlap=strlen(compare_str);
            while(overlap>0)
            {
                char ans_str_back[300]= {};
                for(j=0; j<overlap; j++)
                    ans_str_back[j]=ans_str[strlen(ans_str)-overlap+j];  //取要比的後面幾個
                if(strncmp(ans_str_back ,compare_str,overlap)==0)
                    break;
                else
                    overlap--;
            }
            char to_add[300]= {};
            for(j=0; j<300; j++)
                to_add[j]=compare_str[j+overlap];  //取要加的後面幾個
            strcat(ans_str,to_add);
        }
        printf("%d\n%s",strlen(ans_str),ans_str);
    }
    return 0;
}
