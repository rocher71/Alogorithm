#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    char firstLet = s[0];

    int lastIdx = 0, backCnt = 1;
    char lastLet = s[s.length() - 1];
    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (s[i] != lastLet)
        {
            lastIdx = i + 1;
            break;
        }
        backCnt++;
    }

    string modifyStr = s.substr(lastIdx, backCnt) + s.substr(0, s.length() - backCnt);

    int cnt = 0;
    char prev = modifyStr[0];
    for (char c : modifyStr)
    {
        if (c != prev)
        {
            prev = c;
            answer.push_back(cnt);
            cnt = 1;
        }
        else
            cnt++;
    }
    answer.push_back(cnt);

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<int> v;
    v = solution("aaaab");
    for (int i : v)
    {
        cout << i << " ";
    }
}