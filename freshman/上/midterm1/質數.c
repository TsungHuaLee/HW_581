#include<stdio.h>
int main()
{
    int composite[101],n,i;
    scanf("%d",&n);
    for(i=2; i<=n; i++)
        composite[i]=0;
    int j=2;
    while(j*j<n)
    {
        while(composite[j]==1)
            j++;
        for(i=2*j; i<=n; i+=j)
            composite[i]=1;
        j++;
    }
    for(i=2; i<=n; i++)
        if(composite[i]==0)
            printf("%d\n",i);
}
