#include <stdio.h>
#include <iostream>

using namespace std;

int main() 
{
	int n,n_Num[20],play[20],play_Num[20],high=0,high_Num,x,y,change,play_z=1;
	cin >> n;
	for(x=0;x<n;x++)
	{
		cin >> n_Num[x];
		play[x]=1;
	}
	for(x=n;x>1;x--)					/* ®ðªw±Æ§Çªk */ 
	{
		for(y=0;y<x-1;y++)
		{
			if(n_Num[y+1]<n_Num[y])
			{
				change=n_Num[y+1];
				n_Num[y+1]=n_Num[y];
				n_Num[y]=change;
			}
		}
	}
	play_Num[0]=n_Num[0];
	for(x=1;x<n;x++)
	{
		if(n_Num[x]!=n_Num[x-1])
			play_Num[play_z++]=n_Num[x];
		else
			play[play_z-1]++;
	}
	for(x=0;x<play_z;x++)
	{
		if(play[x]>high)
		{
			high=play[x];
			high_Num=play_Num[x];
		}
	}
	cout << high_Num << " " << high;
}
