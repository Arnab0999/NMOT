#include<stdio.h>
#include<math.h>
float f(float x)
{
         return ( ( 2000 * log ( 140000/(140000-2100*x))) - (9.8*x));
}
float SimpsonsRule(float a,float b,int n)
{
    float h=(b-a)/n;
    float result=0;
    for(int i = 0; i <= n; i++)
    {
        if(i==0||i==n)
        {
            if(i==0)
                result+=f(a);
            else
                result+=f(b);
            
        }
        else if(i%2==0)
        {
            result+=2*f(a+i*h);
        }
        else
        {
            result+=4*f(a+i*h);
        }
    }
    return result*(h/3);
}
int main()
{
        float a,b;
        int n;
        printf("Enter the values of lower and upper limits:");
        scanf("%f%f",&a,&b);
        printf("Enter number of divisions:");
        scanf("%d",&n);
        printf("Result=%5f\n",SimpsonsRule(a,b,n));
        return 0;
}
