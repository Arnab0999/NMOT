#include <stdio.h>
#include <math.h>

float f(float x){
        return ( ( 2000 * log ( 140000/(140000-2100*x))) - (9.8*x));
}

int main(){
        float a,b;
        printf("Enter the values of a and b:");
        scanf("%f%f",&a,&b);
        float intg = (b-a)*( (f(a)+f(b)) / 2 );
        printf("%f\n",intg);
        return 0;
}
