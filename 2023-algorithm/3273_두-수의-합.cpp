#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>

using namespace std;

vector<int> v;
bool num[2000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, ans = 0;
    cin >> n;
    for(int i = 0;i <n; i++){
        int a;
        cin>>a;

        v.push_back(a);
        num[a] = true;
    }
    cin>>x;

    for(auto i : v){
        if((x-i)<1 || (x-i) > 1000000 || i*2 == x) continue;
        if(num[x-i]){
            ans++;
            num[i] = false;
        }
    }



    cout<< ans;



    return 0;
}
