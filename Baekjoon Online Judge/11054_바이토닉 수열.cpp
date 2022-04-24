#include <iostream>
#include <string>
#include <string.h>
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
#define MAX 1001

//idx별 (증가하는 수열의 길이 + 감소하는 수열의 길이) 의 최대값 -1
// 포인트 : 감소하는 수열의 길이는 해당 idx 이후의 요소들에서만 봐야함

int incDP[MAX], decDP[MAX], arr[MAX];
int n;

void solve(){
    
    for(int i = 1; i<n; i++){
        int maxIncDP = 1;
        
        //증가수열
        for(int j = 0; j<i ; j++){
            if(arr[i] <= arr[j]) continue;
            
            maxIncDP = max(maxIncDP, incDP[j] + 1);
        }
        incDP[i] = maxIncDP;
    }
    
    //감소수열 - 자기보다 뒤에 있는 원소들만 확인
    for(int i = n-1; i>=0; i--){
        int maxDecDP = 1;
        
        for(int j = i; j<n; j++){
            if(arr[i] <= arr[j]) continue;
            maxDecDP = max(maxDecDP, decDP[j] + 1);
            
        }
        decDP[i] = maxDecDP;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    incDP[0] = 1;
    decDP[n-1] = 1;
    
    solve();
    
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum = max(sum, decDP[i] + incDP[i]);
    }
    sum--;
    
    cout<< sum<<"\n";
    

}
