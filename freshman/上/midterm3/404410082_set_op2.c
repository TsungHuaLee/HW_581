#include<stdio.h>
#include<string.h>
int main()
{
    int how_many_subset,how_many_calculate;
    while(scanf("%d%d\n",&how_many_subset,&how_many_calculate)!=EOF)
    {
        unsigned long long int set[100]= {};
        char input[1000][100]= {};
        int i,j,t;
        for(i=0; i<how_many_subset; i++)
            gets(input[i]);
        for(i=0; i<how_many_subset; i++)
            for(j=0; j<strlen(input[i]); j++)
                set[i]|=(1uLL<<(input[i][j]-'A'));
        int take1=0,take2=0;
        char symbal=0;
        for(t=0; t<how_many_calculate; t++)
        {
            scanf("%d %c %d",&take1,&symbal,&take2);
            unsigned long long int ans_set;
            if(symbal=='+')
                ans_set=set[take1]|set[take2];
            else if(symbal=='*')
                ans_set=set[take1]&set[take2];
            if(ans_set==0)//空集合
                printf("-1");
            else
            {
                for(i=0; i<60; i++)
                {
                    if(ans_set&1)
                        printf("%c",i+'A');
                    ans_set>>=1uLL;
                }
            }
            printf("\n");
        }
    }

}
