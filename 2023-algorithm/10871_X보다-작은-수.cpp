#include<iostream>
using namespace std;

int n, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp < x) cout << tmp << " ";
    }
    cout<<"\n";
}