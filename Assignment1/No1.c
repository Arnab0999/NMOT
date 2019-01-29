#include<stdio.h>
#include<math.h>
struct limits
{
    float xl;
    float xu;
};
float F(float x)
{
    float fx=pow(x,4)+2*pow(x,3)-x-1;
    return fx;
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
float check(float xl,float xu,float xm,int count)
{
    count++;
    float xmold=xm;
    xm=(xl+xu)/2;
    float error=((xm-xmold)/xm)*100;
    float fxl=F(xl);
    float fxu=F(xu);
 float fxm=F(xm);
    if(count==1)
    {
        printf("%d\t%f\t%f\t%f\t---NULL---\t%.5f\n",count,xl,xu,xm,fxm);
    }
    else
    {
        printf("%d\t%f\t%f\t%f\t%f\t%.5f\n",count,xl,xu,xm,error,fxm);
    }
    if(fxl*fxu<0)
    {
        if(count>=10)
        {
            return xm;
        }
        else if(fxl*fxm<0)
        {
            xm=check(xl,xm,xm,count);
        }
        else if(fxl*fxm>0)
        {
            xm=check(xm,xu,xm,count);
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
int main()
{
    struct limits l;
    l=checklimits(l);
    float xl=l.xl;
    float xu=l.xu;
    printf("Iteration  Xl             Xu               Xm            ErrorPercent     f(Xm)\n");
    printf("--------------------------------------------------------------------------------\n");
    float xm=check(xl,xu,0,0);
    printf("\nRoot=%f",xm);
    return 0;
}
