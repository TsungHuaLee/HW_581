#include<stdio.h>
#include<string.h>
int main()
{
   // freopen("out.txt","w+",stdout);
    int m,n[101],even[101],odd[101];
    int i,first=1;
    while(1)
    {
        int evencount=0,oddcount=0;
        scanf("%d",&m);
        if(m==0)
            break;
        if(first==1)
            first = 0;
        else
          printf("\n");

        for(i=0; i<m; i++)
            scanf("%d",&n[i]);
        for(i=0; i<m; i++)
        {
            if(n[i]%2==0)
            {
                even[evencount]=n[i];
                evencount++;
            }
            else
            {
                odd[oddcount]=n[i];
                oddcount++;
            }
        }
        for(i=0; i<oddcount; i++)
        {
            printf("%d",odd[i]);
            if(i<oddcount-1)
                printf(" ");
        }
        printf("\n");
        for(i=0; i<evencount; i++)
        {
            printf("%d",even[i]);
            if(i<evencount-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
