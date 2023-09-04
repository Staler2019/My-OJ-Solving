#include <iostream>
#include <stdio.h>

using namespace std;

int main() 
{
	int n,n_get[10],x;
	scanf("%d",&n);
	for(x=0;x<n;x++)
		scanf("%d",&n_get[x]);
	for(x=n-1;x>=0;x--)
		printf("%d ",n_get[x]);
}
