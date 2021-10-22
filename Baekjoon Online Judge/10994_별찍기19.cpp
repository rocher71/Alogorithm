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

int n, l;
vector<int> lengths;
stack<int> st1, st2;

//¼º°ø

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	int len = 1 + 4 * (n - 1);
	for (int i = 1; i <= n ; i++)
	{
		l = 1 + 4 * (i - 1);
		//lengths.push_back(l);
		st1.push(l);
	}

	for (int i = 0; i < len; i++)
	{
		int stTop = 0;
		if (i <= len / 2)
			stTop = st1.top();
		else
			stTop = st2.top();

		if (i % 2 == 0)
		{
			for (int j = 0; j < (len - stTop) / 4; j++)
			{
				cout << "* ";
			}
			for (int j = 0; j < stTop; j++)
			{
				cout << "*";
			}
			for (int j = 0; j < (len - stTop) / 4; j++)
			{
				cout << " *";
			}
			/*if(st1.size() > 1)*/
			if (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
			
		}
		else
		{
			for (int j = 0; j < (len - stTop) / 4; j++)
			{
				cout << "* ";
			}
			for (int j = 0; j < stTop; j++)
			{
				cout << " ";
			}
			for (int j = 0; j < (len - stTop) / 4; j++)
			{
				cout << " *";
			}
			if (i > len/2)
			{
				st2.pop();
			}
		}
		cout << "\n";
	}
	
	
	/*for (int i = 0; i < length; i++)
	{
		cout << "*";
		if (i == 0 || i == length - 1)
		{
			for (int j = 0; j < length - 2; j++)
				cout << "*";
		}
		else if ( i == 1 || i == length -2)
		{
			for (int j = 0; j < length - 2; j++)
				cout << " ";
		}
		else if (i == length / 2)
		{
			for (int j = 0; j < length - 2; j++)
			{
				if (j % 2 == 0)
					cout << " ";
				else
					cout << "*";
			}
		}
		else
		{
			cout << " *";
			for (int j = 0; j < length - 4; j++)
			{
				if (j % 2 == 0)
				{
					cout << "*";
				}
				else
				{

				}
			}
			cout << "* " ;
		}
		cout << "*\n";
	}*/





}
