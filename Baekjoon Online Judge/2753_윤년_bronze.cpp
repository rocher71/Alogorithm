#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<set>
#include<sstream>
#include<deque>
#include<cmath>
using namespace std;

//¼º°ø
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	if (n % 4 == 0 && n % 100 != 0 || (n % 400 == 0))
	{
		cout << 1 << "\n";
		return 0;
	}

	cout << "0\n";
	return 0;

}
