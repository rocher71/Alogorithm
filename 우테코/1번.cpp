#include <string>
#include <vector>
#include<iostream>
using namespace std;


vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int cnt[3] = { 0, 0, 0 };

    for (int i : arr)
    {
        if (i == 1)     cnt[0]++;
        else if (i == 2)   cnt[1]++;
        else if (i == 3)   cnt[2]++;
    }

    int maxCnt = max(cnt[0], cnt[1]);
    maxCnt = max(maxCnt, cnt[2]);

    for (int i = 0; i < 3; i++)
    {
        answer.push_back(maxCnt - cnt[i]);
    }

    return answer;
}

int main() {

    vector<int> prob;
    prob.push_back(1);
    vector<int> ans = solution(prob);

    for (int i : ans)
        cout << i << " ";
}