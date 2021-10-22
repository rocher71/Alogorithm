#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<sstream>
#include<deque>
using namespace std;

//¼º°ø
int a, b, ans;

int valOfIdx(int idx)
{
	int sum = 0;
	for (int i = 1; i <= 45; i++)
	{
		sum += i;
		if (sum >= idx)
			return i;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	/*int sum = 0;
	for (int i = 1; i <= 44; i++)
		sum += i;
	cout << sum;*/
	
	for (int i = a; i <= b ; i++)
	{
		ans += valOfIdx(i);
	}

	cout << ans << "\n";


}
