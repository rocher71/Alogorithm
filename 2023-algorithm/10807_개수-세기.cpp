#include<iostream>
#include<algorithm>
#include<math.h>
#include <sstream>

using namespace std;

vector<int> v;
int num[201];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, value;
    cin>> n;
    for(int i =0;i <n; i++){
        int x;
        cin >> x;
        v.push_back(x + 100);
        num[x+100]++;
    }
    cin >> value;
    cout<< num[value+100]<<"\n";



    return 0;
}
