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

int n, cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		/*if (i % 5 != 0) continue;
		
		while (num>=5 && num % 5 == 0) {
			num = num / 5;
			cnt++;
		}*/
		int num = i;
		while (num % 5 == 0) {
			num = num / 5;
			cnt++;
		}
	}

	cout << cnt << "\n";

}
