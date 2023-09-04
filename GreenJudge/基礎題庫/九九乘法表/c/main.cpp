#include <stdio.h>

int main() 
{
	int n,x,y;
	scanf("%d",&n);
	for(x=1;x<=n;x++)
	{
		for(y=1;y<=n;y++)
			printf("%dx%d=%2d  ",y,x,x*y);    /* %-2d 表共兩位數並以靠左表示 */ 
		printf("\n");
	}
}
