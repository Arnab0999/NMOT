#include<stdio.h>
#include<math.h>
float f(float x,float y)
{
    return (2-exp(-4*x)-2*y);
}
float RungeKutta(float x0,float y0,float x,float h)
{
    int count = (int) (x-x0)/h;
    float y = y0;
    float k1,k2,k3,k4;
    for(int i = 0; i < count; i++)
    {
        k1 = h*f(x0,y);
        k2 = h*f(x0+0.5*h,y+0.5*k1);
        k3 = h*f(x0+0.5*h,y+0.5*k2);
        k4 = h*f(x0+h,y+k3);
        y = y + (1.0/6.0)*(k1+2*k2+2*k3+k4);
        x0 = x0 + h;
    }
    return y;
}
int main()
{
    float x0,y0,x,h;
    printf("Enter the initial values of x and y");
    scanf("%f%f",&x0,&y0);
    printf("Enter the interval:");
    scanf("%f",&h);
    printf("Enter the value of x in which the value of y should be find out:");
    scanf("%f",&x);
    printf("Value of y at x=%5f is %5f",x,RungeKutta(x0,y0,x,h));
    return 0;
}
