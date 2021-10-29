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
#include<cmath>
using namespace std;


string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, s);
	while (s != ".")
	{
		stack<char> st;
		bool isEmpty = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);

			else if ((s[i] == ')' || s[i] == ']') && st.empty())
			{
				isEmpty = true;
				break;
			}

			else if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '['))
				st.pop();
		}
		if (isEmpty || st.size() != 0)
			cout << "no\n";
		else
			cout << "yes\n";

		getline(cin, s);
	
	}

}
