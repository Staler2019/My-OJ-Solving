#include <stdio.h>

int main() 
{
	int n,x,y,z=3,t[4];
	scanf("%d",&n);
	if(n/10000!=0)
	{
		n%=10000;
		for(;z>=0;z--)
		{
			y=1;
			for(x=z;x>0;x--)
				y*=10;
			t[z]=n/y;
			n%=y;
		}
		printf("|____");
		for(x=3;x>=0;x--)
			printf("%d",t[x]);
		printf("|");
	}
	else
	{
		n%=10000;
		for(;z>0;z--)
		{
			y=1;
			for(x=z;x>0;x--)
				y*=10;
			if(n/y!=0)
			{
				x=z;
				z=0;
			}
		}
		printf("|____");
		for(;x<3;x++)
			printf("_");
		printf("%d|",n);	
	}
}
