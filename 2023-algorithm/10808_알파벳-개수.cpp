#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int arr[26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>> str;
    int ascii = 'a' - '0';

    for(int i =0 ;i <str.length(); i++){
        arr[str[i] - '0' - ascii]++;
    }

    for(int i : arr)
        cout<< i <<" ";
    cout<<"\n";

    return 0;
}
