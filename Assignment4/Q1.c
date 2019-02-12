#include<stdio.h>
#include<math.h>
float f(float x,float y)
{
        return (2-exp(-4*x)-2*y);
}
float fdash(float y,float fun,float h)
{
        return y+fun*h;
}
int main()
{
        float x,y,h;
        printf("Enter the initial values of x and y:");
        scanf("%f%f",&x,&y);
        int i;
        float fun;
        fun=f(x,y);
        printf("\nEnter the value of h:");
        scanf("%f",&h);
        for(i=0;i<10;i++)
        {
                printf("x%d=%f\ty%d=%f\n",i,x,i,y);
                y=fdash(y,fun,h);
                x+=h;
                fun=f(x,y);
        }
        return 0;
}
