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
//¼º°ø

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> ans;
	vector<int> subVec;
	for (int i = 0; i < commands.size(); i++)
	{
		int idx1 = commands[i][0] - 1, idx2 = commands[i][1] - 1, ansIdx = commands[i][2] - 1;

		for (int j = idx1; j <= idx2; j++)
		{
			subVec.push_back(array[j]);
		}

		sort(subVec.begin(), subVec.end());
		ans.push_back(subVec[ansIdx]);
		subVec.clear();
	}

	return ans;
}