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

	deque<string> toNums(string str)
	{
		string substring = str.substr(1, str.size() - 2);

		deque<string> ans;
		stringstream ss(substring);
		string tmp;

		while (getline(ss, tmp, ','))
		{
			ans.push_back(tmp);
		}

		return ans;
	}

	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> t;
		/* ∫§≈ÕΩ·º≠ «Æ ∂© ∆≤∏≤!
		for (int i = 0; i < t; i++)
		{
			bool isError = false;
			string cmd, nums;
			int tmp;
			cin >> cmd >> tmp >> nums;

			vector<string> ve = toNums(nums);
		
			for (int j = 0; j < cmd.size(); j++)
			{
				if (cmd[j] == 'R')
				{
					if (j != cmd.size() - 1 && cmd[j + 1] == 'R')
					{
						j++;
						continue;
					}
					else
						reverse(ve.begin(), ve.end());
				}
				else if (cmd[j] == 'D')
				{
					if (ve.empty())
					{
						cout << "error\n";
						isError = true;
						break;
					}
					else
					{
						ve.erase(ve.begin());
					}
				}
			}
			if (isError) continue;

			if (ve.empty())
			{
				cout << "[]\n";
			}
			else
			{
				cout << "[";
				for (int j = 0; j < ve.size() - 1; j++)
				{
					cout << ve[j] << ",";
				}
				cout << ve[ve.size() - 1] << "]\n";
			}

		}*/

		for (int i = 0; i < t; i++)
		{
			bool isError = false, isReversed = false;
			string cmd, nums;
			int tmp;
			cin >> cmd >> tmp >> nums;

			//vector<string> ve = toNums(nums);
			deque<string> dq = toNums(nums);

			for (int j = 0; j < cmd.size(); j++)
			{
				if (cmd[j] == 'R')
				{
					/*if (j != cmd.size() - 1 && cmd[j + 1] == 'R')
					{
						j++;
						continue;
					}
					else
						reverse(dq.begin(), dq.end());*/
					if (j != cmd.size() - 1 && cmd[j + 1] == 'R')
					{
						j++;
						continue;
					}
					else
					{
						isReversed = !isReversed;
					}
				}
				else if (cmd[j] == 'D')
				{
					if (dq.empty())
					{
						cout << "error\n";
						isError = true;
						break;
					}
					else
					{
						if (isReversed)
						{
							dq.erase(dq.end()-1);
						}
						else
							dq.erase(dq.begin());
					}
				}
			}
			if (isError) continue;

			if (dq.empty())
			{
				cout << "[]\n";
			}
			else
			{
				cout << "[";
				if (isReversed)
				{
					for (int j = 0; j < dq.size() - 1; j++)
					{
						cout << dq[dq.size() - j -1] << ",";
					}
					cout << dq[0] << "]\n";
				}
				else
				{
					for (int j = 0; j < dq.size() - 1; j++)
					{
						cout << dq[j] << ",";
					}
					cout << dq[dq.size() - 1] << "]\n";
				}
				
				
			}

		}

		return 0;

	}