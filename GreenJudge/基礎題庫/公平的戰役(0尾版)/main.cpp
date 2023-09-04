#include <stdio.h>

int main() 
{
	int n,a,b;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
			break;
		if(a>b)
			printf("A %d\n",a-b);
		else
		{
			if(b>a)
				printf("B %d\n",b-a);
			else
				printf("0\n");
		}
	}
}
