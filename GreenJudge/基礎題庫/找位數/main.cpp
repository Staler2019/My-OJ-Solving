#include <stdio.h>
#include <math.h>

int main() 
{
	double a,b;
	int c;
	scanf("%lf%lf",&a,&b);
	c=ceil(b*log10(a));      /* ceilタ俱计ceill璽俱计 
								floorタ俱计floorl璽俱计 */ 
	if(c=b*log10(a))
		c++;
	printf("%d",c);
}
