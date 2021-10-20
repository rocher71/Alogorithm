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

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
		{
			for (int j = 0; j < n; j++)
			{
				cout << " *";
			}
			cout << "\n";
		}
		else
		{
			
			for (int j = 0; j < n - 1; j++)
			{
				cout << "* ";
			}
			cout << "*\n";
		}
		
		
	}
}
