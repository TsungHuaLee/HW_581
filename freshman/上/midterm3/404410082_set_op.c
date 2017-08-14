#include<stdio.h>
#include<string.h>
int main()
{
    int how_many_subset,how_many_calculate;
    while(scanf("%d%d\n",&how_many_subset,&how_many_calculate)!=EOF)
    {
        unsigned long long int set[100]= {};
        char input[1000][51]= {},temp;
        int i,j,t;
        for(i=0; i<how_many_subset; i++)
            scanf("%s\n",&input[i]);
        for(i=0; i<how_many_subset; i++)
            for(j=0; j<strlen(input[i]); j++)
                set[i]|=(1uLL<<(input[i][j]-'A'));
        int take1,take2;
        char symbal;
        for(i=0; i<how_many_calculate; i++)
        {
            unsigned long long int ans_set=0;
            scanf("%d %c %d",&take1,&symbal,&take2);
            if(symbal=='+')
            {
                ans_set=set[take1]|set[take2];
            }
            else if(symbal=='*')
            {
                ans_set=set[take1]&set[take2];
            }
            if(ans_set==0)
                printf("-1");
            else
            {
                for(j=0; j<=57; j++)
                {
                    if(ans_set&1)
                        printf("%c",j+'A');
                    ans_set>>=1uLL;
                }
            }
            printf("\n");
        }

    }
}
