#include<stdio.h>
#include<math.h>
float f(float x)
{
         return ( ( 2000 * log ( 140000/(140000-2100*x))) - (9.8*x));
}
int main()
{
        float a,b;
        printf("Enter the values of a and b:");
        scanf("%f%f",&a,&b);
        float integration=((b-a)/6)*(f(a)+4*f((a+b)/2)+f(b));
        printf("\nIntegrated value is :%f",integration);
        return 0;
}
