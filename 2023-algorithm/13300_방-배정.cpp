#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>

using namespace std;

pair<int, int> cnt[7];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, minCnt;
    cin >> n>> minCnt;

    for(int i = 0; i<n ;i++){
        int sex, year;
        cin >> sex >> year;
        if(sex == 0) cnt[year].first++;
        else if(sex == 1) cnt[year].second++;
    }

    int ans = 0;
    for(auto i : cnt){
        ans += ceil(i.first / (minCnt * 1.0));
        ans += ceil(i.second / (minCnt * 1.0));
    }

    cout<< ans<<"\n";


    return 0;
}
