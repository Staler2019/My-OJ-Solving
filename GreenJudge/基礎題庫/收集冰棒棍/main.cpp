#include <stdio.h>

int main() 
{
	int n,left,total=0,x;
	scanf("%d",&n);
	left=n%5;
	total=n;
	n/=5;
	total+=n;
	while(n+left>=5)
	{
		x=(left+n)/5;
		left=(left+n)%5;
		n=x;
		total+=n;
		if(n+left<5)
			break;
	}
	printf("%d",total);
}
