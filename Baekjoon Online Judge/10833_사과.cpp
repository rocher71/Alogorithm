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

int n, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int stu, apple, applePerStu, remaining;
		cin >> stu >> apple;
		applePerStu = apple / stu;
		remaining = apple - applePerStu * stu;
		
		ans += remaining;
	}
	cout << ans << "\n";
}