#include <iostream>
#include <string>
#include<algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <sstream>
#include <deque>
#include <cmath>
using namespace std;
#define MAX 91

// 점화식 : arr[n] = arr[n-1] + arr[n-2]

long long int arr[MAX];
int n;

long long int solve(int num){
    
    for(int i = 3; i<= num; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    return arr[num];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    arr[1] = 1;
    arr[2] = 1;
    
    cout << solve(n) << "\n";


}
