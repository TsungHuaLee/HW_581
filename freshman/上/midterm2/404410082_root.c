#include<stdio.h>
#include<math.h>
double f(int power, double x, double coe[])
{//多項式函數
    double fx,xi;
    int i;
    fx=coe[0];xi=1;
    for(i=1;i<=power;i++)
    {
        xi*=x;
        fx+=coe[i]*xi;
    }
    return fx;
}

int main()
{
    int power;
    double coe[1000],a,b,mid;
    double fa,fb,fmid;
    int i;
    int times,first=1;
    scanf("%d",&times);
    while(times--)
    {
        if(first==1)
            first++;
        else
            printf("\n");
    scanf("%d",&power);
    for(i=power;i>=0;i--)
    {

        scanf("%lf",&coe[i]);
       // printf("out%lf",coe[i]);
    }
    scanf("%lf%lf",&a,&b);
    //printf("a=%lf b=%lf\n",a,b);
    while(1)
    {
        fa=f(power,a,coe);//a的函數直
        fb=f(power,b,coe);//b的函數直
       // printf("fa=%lf fb=%lf\n",fa,fb);
        mid=(a+b)/2;//取平均值
       // printf("mid=%lf\n",mid);
        fmid=f(power,mid,coe);//平均值的函數直
       // printf("mid=%lf fmid=%lf\n",mid,fmid);
        double absfmid=fabs(fmid);
       // printf("absfmid%0.9f",absfmid);
        if(absfmid<0.000001)
        {
       //     printf("yee");
            break;
        }
        if(fa*fmid<0)
            b=mid;//縮小範圍變(a,mid)
        else
            a=mid;//所小範圍變(mid,b)
    }
    printf("%0.5lf",mid);

    }
}

//多項式 fabs-->浮點數絕對值
