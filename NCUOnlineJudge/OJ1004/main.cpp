#include <iostream>
using namespace std;

using LL = long long;
#define endl '\n';

LL max(LL a, LL b);

int main()
{
	int n;
	LL last = 0;
	unsigned long long ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{ //DP
		int tmp;
		cin >> tmp;

		/*v1
		last = max(0, last) + tmp;
		//cerr << " tmp" << tmp << " last" << last << endl;
		cerr << " pre-ans" << ans << " last" << last << endl;
		ans = max(ans, last);*/

		/*v2
		last += tmp;
		if (last < 0)
		{
			last = 0;
		}*/

		//v3
		last = ((last < 0) ? 0 : last) + tmp;
		ans = max(ans, last);
	}

	cout << ans;
}

LL max(LL a, LL b) { return (a > b) ? a : b; }