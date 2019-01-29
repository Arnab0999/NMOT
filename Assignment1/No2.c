#include<stdio.h>
#include<math.h>
struct limits
{
    float xl;
    float xu;
};
float F(float x)
{
    return pow(x,4)+2*pow(x,3)-x-1;
}
float Fdash(float x)
{
    return 4*pow(x,3)+6*x*x-1;
}
struct limits checklimits(struct limits l)
{
    l.xl=0;
    l.xu=0;
    while(1)
    {
        if(F(l.xl)*F(l.xu)<0)
        {
            break;
        }
        else
        {
            l.xl--;
            l.xu++;
        }
    }
    return l;
}
float check(float xl,float xu,int count)
{
    count++;
    float xm=(xl+xu)/2;
    float fxm=F(xm);
    float fxl=F(xl);
    float fxu=F(xu);
    if(fxl*fxu<0)
    {
        if(count>=10)
        {
            return xm;
        }
        else if(fxl*fxm<0)
        {
            xm=check(xl,xm,count);
        }
        else if(fxl*fxm>0)
        {
            xm=check(xm,xu,count);
        }
        else if(fxl*fxm==0)
        {
            return xm;
        }
    }
    else
    {
        return xm;
    }
}
float Newtoncheck(float xi,int count)
{
    count++;
    if(count>=11)
    {
        return xi;
    }
    float fx=F(xi);
    float fdashx=Fdash(xi);
    float h=fx/fdashx;
    float xiold=xi;
    xi=xi-h;
 float error=((xi-xiold)/xi)*100;
    printf("%d\t%f\t%f\t%f\t%f\n",count,xi,F(xiold),error,Fdash(xiold));
    xi=Newtoncheck(xi,count);
}
int main()
{
    struct limits l;
    l=checklimits(l);
    float xl=l.xl;
    float xu=l.xu;
    float xi=check(xl,xu,0);
    int count=0;
    printf("Iteration   Xi            f(Xi)        Error percent       f'(Xi)\n");
    printf("--------------------------------------------------------------------\n");
    xi=Newtoncheck(xi,count);
    printf("\nRoot=%f",xi);
    return 0;
}
