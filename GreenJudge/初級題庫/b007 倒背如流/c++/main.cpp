#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string name;
	int x;
	cin >> name;
	for(x=name.length()-1;x>=0;x--)
		cout << name.at(x);				/* 如果你希望效率高，還是使用[]來訪問
										，如果你希望穩定性好，最好使用at()來訪問。 */
}
