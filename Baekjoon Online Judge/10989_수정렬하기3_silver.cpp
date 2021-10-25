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
int n, k;
int arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		arr[k]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		while (arr[i] > 0)
		{
			cout << i << "\n";
			arr[i]--;
		}
			
	}


	cout << "\n";

}
