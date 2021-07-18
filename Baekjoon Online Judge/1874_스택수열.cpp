#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

//성공
// 큐 쓰는게 포인트였음!

stack<int> st;
vector<int> v;
vector<string> ans;
queue<int> numq;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	for (int i = 0; i < n; i++)
	{
		numq.push(i + 1);
	}



	for (int i = 0; i < n; )
	{
 		if (st.empty())
		{
			st.push(numq.front());
			numq.pop();
			ans.push_back("+");

		}
		else if (st.top() < v[i])
		{
			for (int j = numq.front(); j <= v[i]; j++)
			{
				st.push(j);
				ans.push_back("+");
				numq.pop();
			}
		}
		else if (st.top() > v[i])
		{
			cout << "NO\n";
			return 0;
		}

		if (st.top() == v[i])
		{
			st.pop();
			ans.push_back("-");
			i++;
		}
	}


	for (string s : ans)
	{
		cout << s << "\n";
	}

	return 0;


}