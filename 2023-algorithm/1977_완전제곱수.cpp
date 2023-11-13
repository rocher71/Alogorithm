#include<iostream>
#include<vector>
using namespace std;

int m, n;
vector<int> v;

int main(){
    cin >> m >> n;
    for(int i = 1 ; i <= 100; i++ ){
        int squareNumber = i * i;
        if(squareNumber < m) continue;
        if(squareNumber > n) break;
        v.push_back(squareNumber);
    }

    if(v.size() == 0){
        cout <<"-1\n";
        return 0;
    }

    int sum = 0;
    for(int squareNumber : v){
        sum += squareNumber;
    }

    cout << sum <<"\n" << v[0];
    return 0;
}
