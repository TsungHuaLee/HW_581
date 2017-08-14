#include<stdio.h>
main()
{
    int i,x,y,z,a;
    scanf("%d",&i);
    x=i/50;
    y=((i-x*50)/10);
    z=((i-x*50-y*10)/5);
    a=((i-x*50-y*10-z*5));
    printf("%d\n%d\n%d\n%d\n", x,y,z,a);


}
