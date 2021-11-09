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

int n, m;
map<string, string> pswrdM;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string site, pswrd;
		cin >> site >> pswrd;
		pswrdM.insert({ site,pswrd });
	}

	for (int i = 0; i < m; i++)
	{
		string site;
		cin >> site;
		cout << pswrdM.find(site)->second << "\n";
	}
}
