#include <stdio.h>
#include <iostream>

using namespace std;

int main() 
{
	int n,m,m_Num[20]={0},x,y;
	cin >> n >> m;
	for(x=0;x<m;x++)
	{
		cin >> y;
		m_Num[--y]=1;		/* 1表已回來 */ 
	}
	for(x=0;x<n;x++)
	{
		if(m_Num[x]==0)
			cout << x+1 << " ";
	}
}
