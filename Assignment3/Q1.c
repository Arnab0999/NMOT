#include <stdio.h>
#include <math.h>

float f(float x){

        return ( ( 2000 * log ( 140000/(140000-2100*x))) - (9.8*x));
}
float trapezoidalRule(float a,float b,int n)
{
    float h=(b-a)/n;
    float result=f(a)+f(b);
    for(int i = 0; i < n; i++)
    {
        result+=f(a+i*h);
    }
    return (h/2)*result;
}
int main(){
        float a,b;
        int n;
        printf("Enter the lower and upper limits:");
        scanf("%f%f",&a,&b);
        printf("Enter no. of division:");
	    scanf("%d",&n);
	    printf("Result=%.5f\n",trapezoidalRule(a,b,n));
        return 0;
}
