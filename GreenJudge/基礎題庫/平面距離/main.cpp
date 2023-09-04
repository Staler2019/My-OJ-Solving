#include <stdio.h>
#include <math.h>

int main() 
{
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	printf("%0.3f", sqrt((a-c)*(a-c)+(b-d)*(b-d)));
}
