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

int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int candy, ppl, perPerson, remainder;
		cin >> candy >> ppl;
		perPerson = candy / ppl;
		remainder = candy - perPerson * ppl;
		cout << "You get " << perPerson << " piece(s) and your dad gets " << remainder << " piece(s)." << "\n";
	}

}