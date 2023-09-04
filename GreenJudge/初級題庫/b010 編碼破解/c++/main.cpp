#include <iostream>

using namespace std;

int main() 
{
	char input;
	while(cin >> input)
	{
		switch(input)
		{
			case 65:
				input=89;
				break;
			case 66:
				input=90;
				break;
			default:
				input-=2;
		}
		cout << input;
	}
}
