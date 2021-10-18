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

//실패

int n;
//vector<int> v, ans;
priority_queue<int, vector<int>, greater<int>> minH;
priority_queue<int> maxH;
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	//for (int i = 0; i < n; i++)
	//{
	//	int tmp;
	//	cin >> tmp;
	//	v.push_back(tmp);

	//	sort(v.begin(), v.end());
	//	
	//	if (v.size() % 2 == 0) //짝수개 일 때
	//	{
	//		ans.push_back(v[v.size() / 2 - 1]);
	//	}
	//	else //홀수개 일 때
	//	{
	//		ans.push_back(v[v.size() / 2 ]);
	//	}
	//}

	//for (int i : ans)
	//{
	//	cout << i << "\n";
	//}


	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		if (maxH.empty() && minH.empty())
		{
			maxH.push(tmp);
		}
		else if (!maxH.empty() && minH.empty() && n > maxH.top()
			|| tmp > maxH.top() && tmp > minH.top())	
		{
			minH.push(tmp);
		}
		/*else if ( tmp < minH.top()
			|| tmp < maxH.top())
		{
			maxH.push(tmp);
		}*/
		else
 			maxH.push(tmp);
		
		//cout << maxH.top() << "\n";
		ans.push_back(maxH.top());

	}

	for (int i : ans)
	{
		cout << i << "\n";
	}


	return 0;

}