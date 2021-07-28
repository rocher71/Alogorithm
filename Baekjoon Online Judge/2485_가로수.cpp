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
//½ÇÆÐ
int n, cnt;
vector<int> gaps;
vector<int> locations;

int gcd(int, int);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		locations.push_back(tmp);
	}

	sort(locations.begin(), locations.end());

	for (int i = 0; i < n-1; i++)
	{
		int a = locations[i];
		int b = locations[i + 1];
		gaps.push_back(abs(b-a));
	}

	if (gaps.size() == 1)
		gaps[0] = gcd(locations[0], locations[1]);
	else
	{
		for (int i = 0; i < gaps.size() - 1; i++)
		{
			gaps[i + 1] = gcd(gaps[i], gaps[i + 1]);
		}
	}

	int GCD = gaps[gaps.size() - 1];

	for (int i = 0; i < locations.size() - 1; i++)
	{
		if (abs(locations[i] - locations[i + 1]) == GCD) continue;
		
		locations.push_back(-1);
		/*for (int j = i+1; j < locations.size() - i -2; j++)
		{
			locations[j + 1] = locations[j];
		}*/
		
		for (int j = locations.size()-1; j > i + 1; j--)
		{
			locations[j] = locations[j - 1];
		}

		if(locations[i+1]>locations[i]) 
			locations[i + 1] = locations[i] + GCD;	
		else
			locations[i + 1] = locations[i] - GCD;
		cnt++;

	}

	cout << cnt << "\n";
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}